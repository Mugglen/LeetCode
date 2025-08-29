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

// https://leetcode.cn/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = { 0 }; // 9行里9个数各自出现的次数(维度1表示对应是第几行， 维度2表示是哪个数字，维度2有10个是因为数字为1-9，和下标对应)
        int col[9][10] = { 0 }; // 列
        int box[9][10] = { 0 }; // 3x3
        // 开始挨个遍历
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // 没数的格子跳过
                if (board[i][j] == '.') continue;
                // char 转 数字
                int curNum = board[i][j] - '0';
                // 判断行，列， 3x3中有没有出现过
                if (row[i][curNum]) return false;
                if (col[j][curNum]) return false;
                if (box[j / 3 + (i / 3) * 3][curNum]) return false;
                // 没出现过，加入
                row[i][curNum] = 1;
                col[j][curNum] = 1;
                box[j / 3 + (i / 3) * 3][curNum] = 1;
            }
        }
        return true;
    }
};


#endif // DEBUG1



