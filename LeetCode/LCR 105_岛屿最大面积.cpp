#include<vector>
#include<functional>
using namespace std;


// 使用DFS，从200_岛屿数量修改而来

class Solution {

public:
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		
		// 异常值处理
		if (grid.empty() || grid[0].empty()) return 0;
	
		// 计算边界
		int m = grid.size(), n = grid[0].size();
		int maxArea = 0;

		// 包装lambda(注意包装器的语法)
		function<void(int , int, int&)> dfs;

		// 递归lambda(注意加分号)
		dfs = [&](int i, int j, int& ans) -> void {

			// 边界处理
			if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
				return;
			}

			// 插旗
			grid[i][j] = 2;
			// 面积+1 (修改点)
			++ans;
		
			dfs(i, j - 1, ans);// 左
			dfs(i, j + 1, ans);// 右
			dfs(i - 1, j, ans);// 上
			dfs(i + 1, j, ans);// 下
			
			
		};

		// 遍历网络
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// 撞到岛了
				if (grid[i][j] == 1){
					// 注意重置每个岛面积的缓存
					int ans = 0;
					dfs(i, j, ans);
					// 注意回收max的返回值
					maxArea = max(maxArea, ans);
				}
			
			}
		
		}

		return maxArea;

	}

};