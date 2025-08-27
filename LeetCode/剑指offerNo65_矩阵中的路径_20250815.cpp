#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;

// ţ���¼�������
//#define DEBUG1
#ifdef DEBUG1

class Solution {

public:
	// ֱ��д��lambda�Ͳ�����ô�������
	bool dfs(vector<vector<char>>& board,
		char* str,
		int index,
		int x,
		int y,
		vector<vector<bool>>& visited) {

		//�߽紦��
		if (index == strlen(str)) return true;
		if ((x < 0) || (y < 0) || (x >= board.size()) || (y >= board[0].size()))
			return false; // Խ����
		if (visited[x][y]) return false;
		if (board[x][y] != str[index]) return false;

		// ��ǰ��ĸƥ�����ˣ������ݹ�
		visited[x][y] = true;
		if (dfs(board, str, index + 1, x, y - 1, visited) || // ��
			dfs(board, str, index + 1, x, y + 1, visited) || // ��
			dfs(board, str, index + 1, x - 1, y, visited) || // ��
			dfs(board, str, index + 1, x + 1, y, visited)	 // ��
			) {
			// ֻ���ҵ�һ��·�����У����غ������������ĵط�����true����
			return true;
		}
		// û�ҳɹ����ǵûָ���ǰλ�õı��
		visited[x][y] = false;
		return false;
	}

	bool hasPath(char* matrix, int rows, int cols, char* str) {
		// �쳣����
		if (str == NULL || rows <= 0 || cols <= 0) return false;
		// char* ����
		vector<vector<char>> board(rows, vector<char>(cols));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				board[i][j] = matrix[i * cols + j];
			}
		}
		// ������鴦��
		vector<vector<bool>> visited(rows, vector<bool>(cols, false));
		// ��ÿ��λ�������ݹ�
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (dfs(board, str, 0, i, j, visited) == true) {
					return true;
				}
			}
		}
		return false; // �Ҳ���
	}

};

#endif // DEBUG1