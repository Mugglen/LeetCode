#include<vector>
#include<functional>

using namespace std;

class Solution {

public:

	// 注意！！！！！输入是int矩阵不是char型，在下面比较的时候要小心
	int islandPerimeter(vector<vector<int>>& grid) {
	
		// 异常值处理
		if (grid.empty() || grid[0].empty()) return 0;

		// 计算网格的大小
		int m = grid.size(), n = grid[0].size();
		int perimeter = 0;

		// 定义递归lambda
		function<void(int, int)> dfs;

		dfs = [&](int i, int j) -> void {

			// 边界处理
			if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) {
				return;
			}

			// 插旗
			grid[i][j] = 2;

			//计算当前节点的周长贡献
			// 检查四个方向（左、右、上、下）是否与水域（0）或边界相邻
			// 因为不知道从那个方向进入这块（1）的，直接检查4个方向最方便
			// 初始化单块岛屿的周长贡献缓存
			int localPerimeter = 0;
			if (i == 0 || grid[i - 1][j] == 0) localPerimeter++;		// 上
			if (i == m - 1 || grid[i + 1][j] == 0) localPerimeter++;	// 下
			if (j == 0 || grid[i][j - 1] == 0) localPerimeter++;		// 左
			if (j == n - 1 || grid[i][j + 1] == 0) localPerimeter++;	// 右

			// 累加当前节点的周长贡献
			perimeter += localPerimeter;

			//递归访问四个邻居
			dfs(i - 1, j);		// 上
			dfs(i + 1, j);		// 下
			dfs(i, j - 1);		// 左
			dfs(i, j + 1);		// 右

			};

		// 遍历撞岛
		for (int i = 0; i < m; i++) {
			for(int j = 0; j < n; j++){
			
				// 如果遇到陆地，启动DFS
				if (grid[i][j] == 1) {
					dfs(i, j);
					// 只有一个岛
					//return perimeter;
				}
			
			}
		}

		// 注意本题说了只有一个岛，所以这个return 可以写到上面的第二个for循环内，但是这里还是要加个return 0;
		// 要是有多个岛
		return perimeter;
	}
};