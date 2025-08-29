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
        int row[9][10] = { 0 }; // 9����9�������Գ��ֵĴ���(ά��1��ʾ��Ӧ�ǵڼ��У� ά��2��ʾ���ĸ����֣�ά��2��10������Ϊ����Ϊ1-9�����±��Ӧ)
        int col[9][10] = { 0 }; // ��
        int box[9][10] = { 0 }; // 3x3
        // ��ʼ��������
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // û���ĸ�������
                if (board[i][j] == '.') continue;
                // char ת ����
                int curNum = board[i][j] - '0';
                // �ж��У��У� 3x3����û�г��ֹ�
                if (row[i][curNum]) return false;
                if (col[j][curNum]) return false;
                if (box[j / 3 + (i / 3) * 3][curNum]) return false;
                // û���ֹ�������
                row[i][curNum] = 1;
                col[j][curNum] = 1;
                box[j / 3 + (i / 3) * 3][curNum] = 1;
            }
        }
        return true;
    }
};


#endif // DEBUG1



