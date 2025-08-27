#include <iostream>
#include <vector>
using namespace std; // 注意分号，之前忘记加了

// 这题说的是非递增数组，就是去掉重复元素就是递增数组那种

class Solution {
public:
	vector<int>	searchRange(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		int first = -1;
		int last = -1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				first = mid;
				right = mid - 1;// 持续移动右边界，直到找到第一个
			}
		}

		// 重置左右边界
		left = 0;
		right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				last = mid;
				left = mid + 1;// 持续移动左边界，直到找到第二个
			}
		}
		return vector<int> {first, last};
	}
};

//#define DEBUG
#ifdef DEBUG

int main() {
	vector<int> nums = { 5,7,7,8,8,8,10 };
	int target = 8;
	Solution solution;
	vector<int> result = solution.searchRange(nums, target);
	cout << "返回的位置是" << result[0] << "和" << result[1] << endl; // 注意要分开打印，直接result会报错
};


#endif // 
