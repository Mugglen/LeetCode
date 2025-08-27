#include <vector>
using namespace std;
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

		int n = nums.size();

		// 第一步：从右边开始，找到第一个不满足递增的元素（或者说第一个小于右侧相邻元素的数）
		int i = n - 2; // 从倒数第二个元素开始
		while (i >= 0 && nums[i] >= nums[i + 1]) {
			i--;
		}

		// 如果找到了进入第二步，没找到说明数组为降序，本身就是最大的排列，直接反转
		if (i >= 0) {
			// 第二步：从右向左找到 nums[i] 右边最小的大于（或者说第一个大于） nums[i]的数 nums[j]
			int j = n - 1; // 从最后一个元素开始
			while (nums[j] <= nums[i]) { 
				// 注意这里是小于等于，因为要找到大于 nums[i] 的数，同时这里利用了nums[i]右侧本身是降序排列的特性
				j--;
			}
			// 交换 nums[i] 和 nums[j]
			swap(nums[i], nums[j]);
		}

		// 第三步：反转 nums[i]右侧的元素，这样才是紧挨着的下一个排列
		reverse(nums.begin() + i + 1, nums.end());

    }
};
#endif // DEBUG
