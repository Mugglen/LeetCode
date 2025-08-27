#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left < right) {// ��ʱ��С�ڣ������������ص�ʱ��ֹ������ǵ�Ԫ����������while
			int mid = left + (right - left) / 2 + 1;// ��1 ��Ϊ�˷�ֹleft��right����ʱ��mid�������������left��������left = mid��ʱ�������ѭ����
			// nums[mid]��������������У�������Ԫ����������
			if (nums[mid] >= nums[0]) { left = mid; }// ȷ��Lȡ�������������������һ���������mid + 1�Ļ�����ȡ���Ҳ���������ĵ�һ��
			else { right = mid - 1; }// ��leftλ����������������һ����ʱ����left�����������ص�
		}
		// ��������������ж���
		if (target >= nums[0]) {// ע���Ǵ��ڵ��ڣ�©д��
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
	cout << "�㷨����Ľ��Ϊ��" << result << endl;
}

#endif // DEBUG
