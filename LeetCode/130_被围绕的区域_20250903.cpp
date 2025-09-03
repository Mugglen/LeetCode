#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

// �Լ�д��
// ��������������������д���ˣ���һ�����������ˣ�
class Solution {

private:
    // ����
    vector<pair<int, int>> DIRS = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    // dfs+�������ԣ������߽��Ҫ��ԭ����ΪA�ı����������ĳ�0����ΪA���Լ�¼����Ǳ�Ե���죬��Ҫ��������
    bool dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        // �ݹ�߽磨ͼ�߽��жϣ�
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return true;
        }
        // ����߽��жϣ��������������������⣬�ݹ��ʱ����Χ��������X��������·�ֱ���A�������ˣ��ͻ���Ϊ�Լ��ǹµ���
        if (board[i][j] == 'X' || board[i][j] == 'A') return false;
        // �Ȳ���
        board[i][j] = 'A';
        bool touchEdge = false;
        // �ݹ�
        for (auto dir : DIRS) {
            touchEdge = touchEdge || dfs(board, i + dir.first, j + dir.second);
        }
        // û���ߣ������Ƿ�յ���, ������ֻ��Ƿ��ʣ����ͳһ����
        if (!touchEdge) {
            board[i][j] = 'X'; // ����ʱ����
        }
        return touchEdge;
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int rows = board.size();
        int cols = board[0].size();
        // ��һ�α����������յ��죬��ǿ��ŵ���
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') dfs(board, i, j);
            }
        }
        // �ڶ��α������ѿ��ŵ��컻�ء�O��
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};


// [["O","O","O","O","X","X"],
// ["O","O","O","O","O","O"],
// ["O","X","O","X","O","O"],
// ["O","X","O","O","X","O"],
// ["O","X","O","X","O","O"],
// ["O","X","O","O","O","O"]]

#endif // DEBUG1

#define DEBUG1
#ifdef DEBUG1

// https://leetcode.cn/problems/surrounded-regions/solutions/369110/bei-wei-rao-de-qu-yu-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
// �ٷ����������������
// ûϸ����������Ӧ���Ǵ�ͼ�߽������DFS�ѿ��ŵ��춼����
// �����һ������
class Solution {
public:
    int m, n;

    void dfs(vector<vector<char>>& board, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != 'O') {
            return;
        }
        board[x][y] = 'A';
        dfs(board, x + 1, y);
        dfs(board, x - 1, y);
        dfs(board, x, y + 1);
        dfs(board, x, y - 1);
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        if (m == 0) {
            return;
        }
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int i = 1; i < n - 1; i++) {
            dfs(board, 0, i);
            dfs(board, m - 1, i);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};


#endif // DEBUG1