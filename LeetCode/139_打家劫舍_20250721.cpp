#include <vector>
#include <functional>

using namespace std;

//#define DEBUG1
#ifdef DEBUG1

// 使用选与不选的思路
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    // 递归搜索，但是不用记忆化的话会超时，理由见链接视频，搜索数会出现相同的子树
	// 以下是不用记忆化的递归搜索
    int rob(vector<int>& nums) {

        int n = nums.size();
		// 定义当前状态dfs(i)表示从前i个屋子中能偷到的最大金额
        function<int(int)> dfs = [&](int i) -> int {
            // 边界处理(从右往左递归)
            if (i < 0)return 0;

			// 不选当前屋子dfs(i - 1)， 选当前屋子dfs(i - 2) + nums[i]
            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);
			return res;
            }; // 注意lamda声明分号
        return dfs(n - 1); // 注意n-1才是最大索引
    }
};


#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

// 使用选与不选的思路
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
// 复杂度计算公式：状态个数 * 每个状态的计算复杂度
class Solution {
public:
    // 递归搜索，但是不用记忆化的话会超时，理由见链接视频，搜索数会出现相同的子树
    // 以下是用记忆化的递归搜索
    int rob(vector<int>& nums) {

        int n = nums.size();
		vector<int> memo(n, -1); // 记忆化数组，初始化为-1表示未计算

        // 定义当前状态dfs(i)表示从前i个屋子中能偷到的最大金额
        function<int(int)> dfs = [&](int i) -> int {
            // 边界处理(从右往左递归)
            if (i < 0)return 0;

			// 检查memo，如果已经计算过，直接返回结果
			if (memo[i] != -1) return memo[i];

            // 不选当前屋子dfs(i - 1)， 选当前屋子dfs(i - 2) + nums[i]
            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);

			//将结果存入memo
			memo[i] = res;

            return res;
            }; // 注意lamda声明分号
        return dfs(n - 1); // 注意n-1才是最大索引
    }
};


#endif // DEBUG2


//#define DEBUG3
#ifdef DEBUG3

// 使用选与不选的思路，同时去掉递归中“递”的部分，保留“归”的部分
// 就把记忆化递归搜索变成了递推（自底向上）
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
// 复杂度计算公式：状态个数 * 每个状态的计算复杂度
class Solution {
public:
    // 递归搜索，但是不用记忆化的话会超时，理由见链接视频，搜索数会出现相同的子树
    // 以下是用记忆化的递归搜索
    int rob(vector<int>& nums) {

        int n = nums.size();
        // 讲记忆化递归搜索中的状态dfs(i)转换为状态数组dp[i]
        // 初始化的时候多留两个空位来处理初始情况
		// 原始递推关系式dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        // (这样会出现负数下标，可以同时给所有i加2，而且给dp预留一开始的空间，就不用特殊处理开始的情况了)
		vector<int> dp(n + 2, 0);// 初始化为0, 答案不可能为负数
        // 注意dp[i]表示从前i个屋子中能偷到的最大金额
        for (int i = 0; i < n; i++) {
            //注意！！！！！这个nums[i]这个i不用加2, 因为虽然dp前面预留了2个无效空间，但是对于nums来说，
            // 一开始就是有效空间，除非是nums前面也预留了两个空间，才变成nums[i+2]
            dp[i + 2] = max(dp[i + 1], dp[i] + nums[i]); 
        }
        return dp[n + 1];
    }
};


#endif // DEBUG3

//#define DEBUG4
#ifdef DEBUG4 // 递推的同时，保留直接从记忆化搜索翻译来的递推关系式，手动处理特殊情况（要考虑给dp数组头初始化，同时要考虑只有1个或者2个屋子的情况）

// 使用选与不选的思路，同时去掉递归中“递”的部分，保留“归”的部分
// 就把记忆化递归搜索变成了递推（自底向上）
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
// 复杂度计算公式：状态个数 * 每个状态的计算复杂度
class Solution {
public:
    // 递归搜索，但是不用记忆化的话会超时，理由见链接视频，搜索数会出现相同的子树
    // 以下是用记忆化的递归搜索
    int rob(vector<int>& nums) {

        int n = nums.size();
        // 讲记忆化递归搜索中的状态dfs(i)转换为状态数组dp[i]
        // 原始递推关系式dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        vector<int> dp(n, 0);// 初始化为0, 答案不可能为负数
		// 特殊情况处理(注意屋子可能只有1个或者2个)
        dp[0] = nums[0]; // 只有一个屋子时，偷这个屋子
        if (n == 1) return dp[0]; // 如果只有一个屋子，直接返回
        dp[1] = max(nums[0], nums[1]); // 只有两个屋子时，偷最大的那个屋子
        if (n == 2) return max(nums[0], nums[1]); // 如果只有两个屋子，偷最大的那个屋子

        // 注意dp[i]表示从前i个屋子中能偷到的最大金额(这里i从2开始)
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); 
        }
        return dp[n-1];
    }
};


#endif // DEBUG4