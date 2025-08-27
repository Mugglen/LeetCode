#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {
private:
    //int DIRS[4][2] = { {0,1}, {-1,0}, {0, -1}, {1, 0} }; // 右、下、左、上

public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        // 异常
        if (matrix.size() == 0 || matrix[0].size() == 0)return vector<int>();
        // 初始化
        vector<int> ans;
        // 获取数组边界
        int row = matrix.size();
        int col = matrix[0].size();
        // 保存当前遍历过的边界(注意是索引，要-1)
        int top = 0, bottom = row - 1, left = 0, right = col - 1;
        // 遍历(注意是top <= bottom，之前写反了)
        while (left <= right && top <= bottom) {
            // 从左到右
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            // 越界判断(同时缩小上边界)
            if (++top > bottom) break;

            // 从上往下
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            // 越界判断
            if (--right < left) break;

            // 从右往左
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            // 越界判断
            if (--bottom < top) break;

            // 从下往上
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            // 越界判断
            if (++left > right) break;

        }   
        return ans;
    }
};

#endif // DEBUG1