#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {

private:
    // 8个方向
    vector<pair<int, int>> _DIRS = { {-1, 0}, // 上
                                    {1,  0}, // 下
                                    {0, -1}, // 左
                                    {0,  1}, // 右
                                    {-1, 1}, // 右上
                                    {1,  1}, // 右下
                                    {1, -1}, // 左下
                                    {-1,-1} };// 左上

    // 计算当前坐标的邻居有几个1，输入当前坐标和矩阵范围
    int neighborSum(int i, int j, const vector<vector<int>>& board) {
        // 获得行列
        int rows = board.size();
        int cols = board[0].size();
        
        // 加起来，注意判断边界
        int sum = 0;
        for (auto dir : _DIRS) {
            int m = i + dir.first;
            int n = j + dir.second;
            if (m >= 0 && m < rows && n >= 0 && n < cols) {
                sum += board[m][n];
            }
        }
        return sum;
    }


public:
    void gameOfLife(vector<vector<int>>& board) {
        // 获得行列
        int rows = board.size();
        int cols = board[0].size();
        // 创建下一个状态的数组
        vector<vector<int>> nextBoard(rows, vector<int>(cols, 0));
        // 循环更新每个细胞状态
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = neighborSum(i, j, board);
                if (sum < 2) nextBoard[i][j] = 0;
                else if (sum == 2) nextBoard[i][j] = board[i][j];
                else if (sum == 3) nextBoard[i][j] = 1;
                else nextBoard[i][j] == 0;
            }
        }
        board = nextBoard;
    }
};

#endif // DEBUG1



