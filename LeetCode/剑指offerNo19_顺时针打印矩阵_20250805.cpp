#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {
private:
    //int DIRS[4][2] = { {0,1}, {-1,0}, {0, -1}, {1, 0} }; // �ҡ��¡�����

public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        // �쳣
        if (matrix.size() == 0 || matrix[0].size() == 0)return vector<int>();
        // ��ʼ��
        vector<int> ans;
        // ��ȡ����߽�
        int row = matrix.size();
        int col = matrix[0].size();
        // ���浱ǰ�������ı߽�(ע����������Ҫ-1)
        int top = 0, bottom = row - 1, left = 0, right = col - 1;
        // ����(ע����top <= bottom��֮ǰд����)
        while (left <= right && top <= bottom) {
            // ������
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            // Խ���ж�(ͬʱ��С�ϱ߽�)
            if (++top > bottom) break;

            // ��������
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            // Խ���ж�
            if (--right < left) break;

            // ��������
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            // Խ���ж�
            if (--bottom < top) break;

            // ��������
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            // Խ���ж�
            if (++left > right) break;

        }   
        return ans;
    }
};

#endif // DEBUG1