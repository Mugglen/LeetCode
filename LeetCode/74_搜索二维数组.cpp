# include <iostream>
# include <vector>
using namespace std;

// 方法一 两次二分查找

class Solution {
public:
	bool searchMatrix(vector<vector<int>>matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		int left = 0, right = m * n - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2; // 注意是right - left,错了几次了
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
	vector<vector<int>> matrix = { {1, 3, 5, 7},{10, 11, 16, 20},{23, 30, 34, 60} }; // 注意是花括号初始化，方括号读取索引
	int target = 3;
	Solution solution;

	bool result = solution.searchMatrix(matrix, target);
	if (result) {
		cout << "矩阵中存在" << target << "元素" << endl;
	}
	else {
		cout << "矩阵中不存在" << target << "元素" << endl;
	}
	
	return 0;
}

#endif // DEBUG

