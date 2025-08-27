#include <vector>
#include <iostream>

using namespace std;
#ifdef DEBUG
class Solution {

public:
	int search(vector<int>& nums, int target) {
	
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;

		// ע����ֲ��ұȽϵ�������ָ��
		//while (nums[mid] != target) {
		while (left <= right) {
			// �����м�ֵ
			int mid = left + ((right - left) / 2);
			cout << "mid:" << mid << endl;
			
			if (nums[mid] < target) {
				left = mid + 1;
			}
			else if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				return mid;
			}
		}

		return -1;

	}

};



int main() {

	Solution solution;

	vector<int> nums = { -1,0,3,5,9,12 };
	int target = 9;

	cout << solution.search(nums, target) << endl;




}
#endif // DEBUG


