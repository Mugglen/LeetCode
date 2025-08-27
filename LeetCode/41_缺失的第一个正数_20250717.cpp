

#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // https://leetcode.cn/problems/first-missing-positive/solutions/3655377/huan-zuo-wei-tong-guo-li-zi-li-jie-suan-qa94e/?envType=study-plan-v2&envId=top-100-liked
    int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 如果当前学生的学号在 [1, n] 中但是（真身）没有坐在正确的座位上
            // nums[i](当前学号) != nums[nums[i] - 1]（当前学号应该坐在的座位上，现在坐着的学生学号）（注意数组索引从0开始，但是0不在我们关系的范围内，所以存储的索引要-1）
            while (1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                // 那么就交换 nums[i] 和 nums[j]，其中j是i的学号
				int j = nums[i] - 1; // j是i的学号，注意数组索引从0开始，所以要-1
                swap(nums[i], nums[j]);
            }
        }

        // 座位交换结束，开始查找第一个学号与座位编号不匹配的学生
        for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) { // 注意座位编号+1才能和学号对应
				return i + 1; // 返回第一个学号与座位编号不匹配的学生的学号s
            }
        }

		// 如果所有学生的学号都与座位编号匹配，那么第一个缺失的正整数就是n + 1
		return n + 1;
    }
};
#endif // DEBUG
