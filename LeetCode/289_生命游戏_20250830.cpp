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
    // 8������
    vector<pair<int, int>> _DIRS = { {-1, 0}, // ��
                                    {1,  0}, // ��
                                    {0, -1}, // ��
                                    {0,  1}, // ��
                                    {-1, 1}, // ����
                                    {1,  1}, // ����
                                    {1, -1}, // ����
                                    {-1,-1} };// ����

    // ���㵱ǰ������ھ��м���1�����뵱ǰ����;���Χ
    int neighborSum(int i, int j, const vector<vector<int>>& board) {
        // �������
        int rows = board.size();
        int cols = board[0].size();
        
        // ��������ע���жϱ߽�
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
        // �������
        int rows = board.size();
        int cols = board[0].size();
        // ������һ��״̬������
        vector<vector<int>> nextBoard(rows, vector<int>(cols, 0));
        // ѭ������ÿ��ϸ��״̬
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



