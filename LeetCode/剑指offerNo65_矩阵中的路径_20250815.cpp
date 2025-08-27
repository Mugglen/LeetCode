#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;

// 牛客下架了这题
//#define DEBUG1
#ifdef DEBUG1

class Solution {

public:
	// 直接写成lambda就不用这么多参数了
	bool dfs(vector<vector<char>>& board,
		char* str,
		int index,
		int x,
		int y,
		vector<vector<bool>>& visited) {

		//边界处理
		if (index == strlen(str)) return true;
		if ((x < 0) || (y < 0) || (x >= board.size()) || (y >= board[0].size()))
			return false; // 越界了
		if (visited[x][y]) return false;
		if (board[x][y] != str[index]) return false;

		// 当前字母匹配上了，继续递归
		visited[x][y] = true;
		if (dfs(board, str, index + 1, x, y - 1, visited) || // 上
			dfs(board, str, index + 1, x, y + 1, visited) || // 左
			dfs(board, str, index + 1, x - 1, y, visited) || // 左
			dfs(board, str, index + 1, x + 1, y, visited)	 // 右
			) {
			// 只用找到一条路径就行，返回后其他遍历过的地方保持true就行
			return true;
		}
		// 没找成功，记得恢复当前位置的标记
		visited[x][y] = false;
		return false;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str) {
		// 异常处理
		if (str == NULL || rows <= 0 || cols <= 0) return false;
		// char* 处理
		vector<vector<char>> board(rows, vector<char>(cols));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				board[i][j] = matrix[i * cols + j];
			}
		}
		// 标记数组处理
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		// 从每个位置启动递归
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (dfs(board, str, 0, i, j, visited) == true) {
					return true;
				}
			}
		}
		return false; // 找不到
	}

};

#endif // DEBUG1