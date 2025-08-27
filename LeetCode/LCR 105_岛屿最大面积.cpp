#include<vector>
#include<functional>
using namespace std;


// ʹ��DFS����200_���������޸Ķ���

class Solution {

public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		
		// �쳣ֵ����
		if (grid.empty() || grid[0].empty()) return 0;
	
		// ����߽�
		int m = grid.size(), n = grid[0].size();
		int maxArea = 0;

		// ��װlambda(ע���װ�����﷨)
		function<void(int , int, int&)> dfs;

		// �ݹ�lambda(ע��ӷֺ�)
		dfs = [&](int i, int j, int& ans) -> void {

			// �߽紦��
			if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
				return;
			}

			// ����
			grid[i][j] = 2;
			// ���+1 (�޸ĵ�)
			++ans;
		
			dfs(i, j - 1, ans);// ��
			dfs(i, j + 1, ans);// ��
			dfs(i - 1, j, ans);// ��
			dfs(i + 1, j, ans);// ��
			
			
		};

		// ��������
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// ײ������
				if (grid[i][j] == 1){
					// ע������ÿ��������Ļ���
					int ans = 0;
					dfs(i, j, ans);
					// ע�����max�ķ���ֵ
					maxArea = max(maxArea, ans);
				}
			
			}
		
		}

		return maxArea;

	}

};