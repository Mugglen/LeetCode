#include <vector>
#include <numeric> // reduce头文件

using namespace std;

// 0-1背包问题(算出满足题目条件的正数和，作为背包容量，nums中元素作为可以填入背包的问题)
// 注意题目要求，输出的是满足条件的组合数，而不是最大值
// https://www.bilibili.com/video/BV16Y411v7Y6/?vd_source=7863beabe20c537c924d81df79243393
// https://leetcode.cn/problems/target-sum/
//#define DEBUG
#ifdef DEBUG

// 当前使用是视频里的思路
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

		// 直接使用target作为背包容量计算的中间变量，这里选取了正数和作为背包容量
        // 设整数和为p，负数绝对值和为n = s - p，s为数组元素和
        // 所以target = p - (s - p)，得到p = (s + t)/2
		// 使用C++17引入的reduce函数来计算数组元素和
        target += reduce(nums.begin(), nums.end());
        // 特判(不能小于0，因为表示的是正数和的两倍，而且必须是偶数)
        if (target < 0 || target % 2) return 0;
        // 取出数组长度
        int n = nums.size();

		// 计算背包容量
		int capacity = target / 2;

        // 写出背包问题范式（记忆化搜索）（capacity + 1是为了兼容0的情况）
		vector<vector<int>> memo(n, vector<int>(capacity + 1, -1)); // -1表示未计算

		// 当前背包剩余容量capacity，当前物品索引i，从右往左遍历
		// C++ 23引入的lambda表达式可以直接使用递归s
        auto dfs = [&](this auto&& dfs, int i, int capacity)-> int {
            // 边界处理
			if (i < 0) return capacity == 0; // 没有物品了,检查是否刚好塞满背包
            // 记忆化操作(索引就是dfs的参数)
            int& res = memo[i][capacity];
			if (res != -1) return res; // 如果已经计算过，直接返回结果
            // 开始选择物品
            // 当前物品容量大于背包剩余容量，不能放入背包，只能不选
			if (capacity < nums[i]) return res = dfs(i-1, capacity); 
			// 当前物品容量小于等于背包剩余容量，可以选择不放入或放入
			// 注意这里的加法原理，即放入背包的情况和不放入背包的情况两件事是互斥的，题解里有解释
            return res = dfs(i - 1, capacity) + dfs(i - 1, capacity - nums[i]);

            };
        return dfs(n - 1, capacity);
    }
};



#endif // DEBUG


//#define DEBUG2
#ifdef DEBUG2
// 当前使用是视频里的思路，翻译成递推
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        // 直接使用target作为背包容量计算的中间变量，这里选取了正数和作为背包容量
        // 设整数和为p，负数绝对值和为n = s - p，s为数组元素和
        // 所以target = p - (s - p)，得到p = (s + t)/2
        // 使用C++17引入的reduce函数来计算数组元素和
        target += reduce(nums.begin(), nums.end());
        // 特判(不能小于0，因为表示的是正数和的两倍，而且必须是偶数)
        if (target < 0 || target % 2) return 0;
        // 取出数组长度
        int n = nums.size();

        // 计算背包容量
        int capacity = target / 2;

        // 写出背包问题范式（初始化dp数组）(注意!!!!!!后面为了处理越界问题，递推关系式里的i都加1了，这里初始化dp数组的时候n也要加上1)
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0)); 
		dp[0][0] = 1; // 初始状态，背包容量为0时，有一种方法(不选任何物品)

        // 当前背包剩余容量capacity，当前物品索引i，从左往右遍历
		// 先枚举物品
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= capacity; c++) { // 注意!!!!!!这是小于等于
                // 开始选择物品
                // 当前物品容量大于背包剩余容量，不能放入背包，只能不选
				// 为了避免越界，c从0开始，所以这里的判断是c < nums[i]，同时i的索引加了1，但是作为nums的索引不变
                if (c < nums[i]) dp[i + 1][c] = dp[i][c];
                // 当前物品容量小于等于背包剩余容量，可以选择不放入或放入
                else dp[i + 1][c] = dp[i][c] + dp[i][c - nums[i]];
            }
        }
        return dp[n][capacity];
    }
};

#endif // DEBUG2


//#define DEBUG3
#ifdef DEBUG3
// 当前使用是视频里的思路，翻译成递推后，进行空间优化，使用2个数组空间
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        target += reduce(nums.begin(), nums.end());
        if (target < 0 || target % 2) return 0;
        int n = nums.size();
        int capacity = target / 2;
        
		// 优化点，只初始化两行，因为结果只依赖于前一行的结果，将计算结果存入不使用的行
        vector<vector<int>> dp(2, vector<int>(capacity + 1, 0));
        dp[0][0] = 1; 

        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= capacity; c++) {
				// 通过将索引 % 2来切换行，避免使用额外的空间
                if (c < nums[i]) 
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else 
                    dp[(i + 1) % 2][c] = dp[i % 2][c] + dp[i % 2][c - nums[i]];
            }
        }
        return dp[n % 2][capacity];
    }
};

#endif // DEBUG3



//#define DEBUG3
#ifdef DEBUG3
// 当前使用是视频里的思路，翻译成递推后，进行空间优化，
// 使用1个数组空间，为了避免运算中覆盖单个数组中后序用于计算的值，采用自顶向下的方法，每次保证计算结果不会覆盖后序要使用的值
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        target += reduce(nums.begin(), nums.end());
        if (target < 0 || target % 2) return 0;
        int n = nums.size();
        int capacity = target / 2;

		// 优化点，只初始化1行，因为结果依赖于当前行稍小索引的元素，所以要采用自顶向下的方法
        vector<int> dp(capacity + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int c = capacity; c >= nums[i]; c--) {
                // 换成自顶向下
                dp[c] = dp[c] + dp[c - nums[i]];
            }
        }
        return dp[capacity];
    }
};

#endif // DEBUG3