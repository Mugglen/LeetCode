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

    void movingCountCore(int threshold, 
        int rows, 
        int cols, 
        vector<vector<bool>>& visit, 
        int row, 
        int col, 
        int &count) {
        // 递归边界
        if (row < 0 || col < 0 || row >= rows || col >= cols || visit[row][col] == true) return;
        if (getValue(row, col) > threshold) {
            visit[row][col] = true;
            return;
        }
        // 递归内操作
        visit[row][col] = true;
        count++;

        // 启动递归
        movingCountCore(threshold, rows, cols, visit, row + 1, col, count);
        movingCountCore(threshold, rows, cols, visit, row - 1, col, count);
        movingCountCore(threshold, rows, cols, visit, row, col + 1, count);
        movingCountCore(threshold, rows, cols, visit, row, col - 1, count);

    }

    int getValue(int row, int col) {
        int sum = 0;
        while (row != 0) {
            sum += row % 10;
            row = row / 10;
        }
        while (col != 0) {
            sum += col % 10;
            col = col / 10;
        }
        return sum;
        
    }


    int movingCount(int threshold, int rows, int cols) {
        if (rows < 0 || cols < 0) return 0;
        vector<vector<bool>> visit(rows, vector<bool>(cols, false));
        int count = 0;
        movingCountCore(threshold, rows, cols, visit, 0, 0, count);
        return count;
    }
};


#endif // DEBUG1