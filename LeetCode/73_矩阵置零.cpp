#include <vector>

using namespace std;



// https://leetcode.cn/problems/set-matrix-zeroes/solutions/669901/ju-zhen-zhi-ling-by-leetcode-solution-9ll7

class Solution {

public:
	void setZeroes(vector<vector<int>>& matrix) {
		// �п�
		int m = matrix.size();
		// �п�
		int n = matrix[0].size();

		// ��ʼ���������
		vector<int> row(m), col(n);
	
		//��һ�������¼0���ڵ�����
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