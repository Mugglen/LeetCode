#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {// 此时是小于，在两者坐标重叠时终止，如果是单元素数组跳过while
			int mid = left + (right - left) / 2 + 1;// 加1 是为了防止left和right相邻时，mid计算出来还等于left，在下面left = mid的时候进入死循环。
			// nums[mid]在左侧有序数组中，包含单元素数组的情况
			if (nums[mid] >= nums[0]) { left = mid; }// 确保L取的是左侧有序数组的最后一个，如果是mid + 1的话可能取到右侧有序数组的第一个
			else { right = mid - 1; }// 在left位于左侧有序数组最后一个的时候向left收束，最终重叠
		}
		// 在左侧有序数组中二分
		if (target >= nums[0]) {// 注意是大于等于，漏写了
			left = 0;
		}
		else {
			left = left + 1;
			right = nums.size() - 1;
		}
		while (left < right) {
			int mid = left + (right - left) / 2 + 1;
			if (nums[mid] <= target) {
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		return nums[left] == target ? right : -1;
	}
};
//#define DEBUG
#ifdef DEBUG

int main() {
	vector<int> nums = { 4,5,6,7,0,1,2 };
	int target = 0;
	Solution solution;
	int result = solution.search(nums, target);
	cout << "算法输出的结果为：" << result << endl;
}

#endif // DEBUG
