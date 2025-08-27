#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/maximum-product-subarray/solutions/2968916/dong-tai-gui-hua-jian-ji-gao-xiao-python-i778/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int maxProduct(vector<int>& nums) {

		// 维护两个dp数组，一个记录从0到i最大子数组乘积，一个记录最小子数组乘积
        int n = nums.size();
		vector<int> dp_max(n, 0), dp_min(n, 0);
        // 初始化
        dp_max[0] = dp_min[0] = nums[0];
		// 从 i = 1 开始遍历数组   
        for (int i = 1; i < n; i++) {
			int x = nums[i];
            // 把 x 加到右端点为 i-1 的（乘积最大/最小）子数组后面，
            // 或者单独组成一个子数组，只有 x 一个元素
            // 注意max(里面要构造一个数组{})
            dp_max[i] = max({ dp_max[i - 1] * x, dp_min[i - 1] * x, x });
            dp_min[i] = min({ dp_max[i - 1] * x, dp_min[i - 1] * x, x });
        }
        return ranges::max(dp_max);
    }
};


#endif // DEBUG
