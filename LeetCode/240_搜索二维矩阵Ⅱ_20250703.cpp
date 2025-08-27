#include <iostream>
#include <vector>

using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:

    // 注意每行的元素从左到右升序排列。
    // 每列的元素从上到下升序排列。
    // 我们可以用 O(1) 的时间获取 O(m) 或 O(n) 的信息。相比之下，O(mn) 的暴力查找（一个一个地找），每次花费 O(1) 的时间，只获取了 O(1) 的信息。

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // 先获取当前矩阵的行和列
        int m = matrix.size(); // 行数
        int n = matrix[0].size();// 列数

        // 设置起始搜索行列
        int row = 0; 
        int col = n - 1;

        // 开始循环搜索(搜索到最后一行的时候就依次递减列了)
        while (row < m && col >= 0) {
            
            // 比较右上角元素
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                row++; // 这一行所有剩余元素全部小于target
            }
            else {
                col--; // 这一列所有剩余元素全部大于target
            }
        
        }
        return false;
    }
};

#endif // DEBUG

