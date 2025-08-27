# include <iostream>
# include <vector>
using namespace std;

// ����һ ���ζ��ֲ���

class Solution {
public:
	bool searchMatrix(vector<vector<int>>matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		int left = 0, right = m * n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2; // ע����right - left,���˼�����
			int x = matrix[mid / n][mid % n];
			if (target < x) {
				right = mid - 1;
			}
			else if (target > x) {
				left = mid + 1;
			}
			else {
				return true;
			}
		}
		return false;
		
	}
};

//#define DEBUG

#ifdef DEBUG

int main() {
	vector<vector<int>> matrix = { {1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 60} }; // ע���ǻ����ų�ʼ���������Ŷ�ȡ����
	int target = 3;
	Solution solution;

	bool result = solution.searchMatrix(matrix, target);
	if (result) {
		cout << "�����д���" << target << "Ԫ��" << endl;
	}
	else {
		cout << "�����в�����" << target << "Ԫ��" << endl;
	}
	
	return 0;
}

#endif // DEBUG

