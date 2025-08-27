#include <iostream>
#include <vector>
using namespace std; // ע��ֺţ�֮ǰ���Ǽ���

// ����˵���Ƿǵ������飬����ȥ���ظ�Ԫ�ؾ��ǵ�����������

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
				right = mid - 1;// �����ƶ��ұ߽磬ֱ���ҵ���һ��
			}
		}

		// �������ұ߽�
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
				left = mid + 1;// �����ƶ���߽磬ֱ���ҵ��ڶ���
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
	cout << "���ص�λ����" << result[0] << "��" << result[1] << endl; // ע��Ҫ�ֿ���ӡ��ֱ��result�ᱨ��
};


#endif // 
