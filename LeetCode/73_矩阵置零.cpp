#include <vector>

using namespace std;



// https://leetcode.cn/problems/set-matrix-zeroes/solutions/669901/ju-zhen-zhi-ling-by-leetcode-solution-9ll7

class Solution {

public:
	void setZeroes(vector<vector<int>>& matrix) {
		// 列宽
		int m = matrix.size();
		// 行宽
		int n = matrix[0].size();

		// 初始化标记数组
		vector<int> row(m), col(n);
	
		//第一遍遍历记录0所在的行列
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!matrix[i][j]) {
					row[i] = col[j] = true;
				}
			}
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (row[i] || col[j]) {
					matrix[i][j] = 0;
				}
			}
		
		}
	}
};