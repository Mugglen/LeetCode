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

// 自己写的
// ！！！！！！！！这里写错了（有一半用例过不了）
class Solution {

private:
    // 方向
    vector<pair<int, int>> DIRS = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

    // dfs+回溯试试，遇到边界后要把原来改为A的保留，在最后改成0，改为A可以记录这个是边缘岛屿，不要反复遍历
    bool dfs(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();
        // 递归边界（图边界判断）
        if (i < 0 || i >= rows || j < 0 || j >= cols) {
            return true;
        }
        // 岛屿边界判断（！！！！！！！错在这，递归的时候周围有三个‘X’，来的路又被‘A’堵上了，就会认为自己是孤岛）
        if (board[i][j] == 'X' || board[i][j] == 'A') return false;
        // 先插旗
        board[i][j] = 'A';
        bool touchEdge = false;
        // 递归
        for (auto dir : DIRS) {
            touchEdge = touchEdge || dfs(board, i + dir.first, j + dir.second);
        }
        // 没触边，所以是封闭岛屿, 触边了只标记访问，最后统一处理
        if (!touchEdge) {
            board[i][j] = 'X'; // 回溯时捕获
        }
        return touchEdge;
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0) return;
        int rows = board.size();
        int cols = board[0].size();
        // 第一次遍历，捕获封闭岛屿，标记开放岛屿
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') dfs(board, i, j);
            }
        }
        // 第二次遍历，把开放岛屿换回‘O’
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
// 官方题解的深度优先搜索
// 没细看，但大致应该是从图边界出发，DFS把开放岛屿都插旗
// 最后再一并捕获
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