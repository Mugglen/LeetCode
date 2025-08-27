#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/maximum-product-subarray/solutions/2968916/dong-tai-gui-hua-jian-ji-gao-xiao-python-i778/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //  每个位置两个状态
		// dp_max[i]表示以 nums[i] 结尾的最大乘积
        // dp_min[i]表示以 nums[i] 结尾的最小乘积
        int n = nums.size();
        vector<int> dp_max(n, 0), dp_min(n, 0);
		dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        // 开始计算(错误点！！！！！！！循环起点是1)
        //for (int i = 0; i < n; i++) {
        for (int i = 1; i < n; i++) {
            // 状态转移方程(dp_max和dp_min都有可能是0，所以得把nums[i]单独成一个数组考虑进去)
            // 注意max可以对数组求最大，但是对容器求最大要
            dp_max[i] = max({ dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i] });
            dp_min[i] = min({ dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i] });

        }
        // 使用容器写法,返回的是最大的容器，要解引用，很麻烦(而且速度会比ranges慢很多)
        //return *max_element(dp_max.begin(), dp_max.end());
        return ranges::max(dp_max);
    }
};


#endif // DEBUG
