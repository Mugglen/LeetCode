#include<vector>
#include<functional>

using namespace std;

class Solution {

public:

	// ע�⣡��������������int������char�ͣ�������Ƚϵ�ʱ��ҪС��
	int islandPerimeter(vector<vector<int>>& grid) {
	
		// �쳣ֵ����
		if (grid.empty() || grid[0].empty()) return 0;

		// ��������Ĵ�С
		int m = grid.size(), n = grid[0].size();
		int perimeter = 0;

		// ����ݹ�lambda
		function<void(int, int)> dfs;

		dfs = [&](int i, int j) -> void {

			// �߽紦��
			if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
				return;
			}

			// ����
			grid[i][j] = 2;

			//���㵱ǰ�ڵ���ܳ�����
			// ����ĸ��������ҡ��ϡ��£��Ƿ���ˮ��0����߽�����
			// ��Ϊ��֪�����Ǹ����������飨1���ģ�ֱ�Ӽ��4���������
			// ��ʼ�����鵺����ܳ����׻���
			int localPerimeter = 0;
			if (i == 0 || grid[i - 1][j] == 0) localPerimeter++;		// ��
			if (i == m - 1 || grid[i + 1][j] == 0) localPerimeter++;	// ��
			if (j == 0 || grid[i][j - 1] == 0) localPerimeter++;		// ��
			if (j == n - 1 || grid[i][j + 1] == 0) localPerimeter++;	// ��

			// �ۼӵ�ǰ�ڵ���ܳ�����
			perimeter += localPerimeter;

			//�ݹ�����ĸ��ھ�
			dfs(i - 1, j);		// ��
			dfs(i + 1, j);		// ��
			dfs(i, j - 1);		// ��
			dfs(i, j + 1);		// ��

			};

		// ����ײ��
		for (int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++){
			
				// �������½�أ�����DFS
				if (grid[i][j] == 1) {
					dfs(i, j);
					// ֻ��һ����
					//return perimeter;
				}
			
			}
		}

		// ע�Ȿ��˵��ֻ��һ�������������return ����д������ĵڶ���forѭ���ڣ��������ﻹ��Ҫ�Ӹ�return 0;
		// Ҫ���ж����
		return perimeter;
	}
};