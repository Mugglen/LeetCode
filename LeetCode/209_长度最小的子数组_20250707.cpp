#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG


// https://leetcode.cn/problems/minimum-size-subarray-sum/solutions/1959532/biao-ti-xia-biao-zong-suan-cuo-qing-kan-k81nh/
// 使用滑动窗口，枚举右端点，缩小左端点（也可以看成是双指针）
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n + 1, sum = 0, left = 0; // 因为ans要做比较，所以初始化为最大答案+1
        for (int right = 0; right < n; right++) { // 枚举子数组右端点
            sum += nums[right];
            // 缩小左端点
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if (sum >= target) {
                ans = min(ans, right - left + 1); // 计算子数组长度时不确定加不加1可以使用带入特殊值的方法，比如当前左右指针可能指向同一个元素
            }
        }
        return ans <= n ? ans : 0;
    }
};

// 时间复杂度：O（n）
// 空间复杂度：


#endif // DEBUG


//#define PRETICE
#ifdef PRETICE

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // 获取数组长度，初始化答案，为了最后比较是不是没有子数组能满足要求，初始化答案大小为n+1
        int n = nums.size();
        int ans = n + 1;
        int left = 0;
        int sum = 0;

        // 构建滑动窗口
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // 检查移动左指针后数据总和是否大于target
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }

            // 更新结果（错误点！！！！注意更新ans要先判断，而且是大于等于，不是单纯大于）
            if (sum >= target) {
                ans = min(ans, right - left + 1);
            }
            

        }
        // 返回时检查存不存在满足题目要求的子数组
        return ans <= n ? ans : 0;
    }
};



#endif // PRETICE
