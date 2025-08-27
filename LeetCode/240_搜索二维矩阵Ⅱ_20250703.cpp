#include <iostream>
#include <vector>

using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:

    // ע��ÿ�е�Ԫ�ش������������С�
    // ÿ�е�Ԫ�ش��ϵ����������С�
    // ���ǿ����� O(1) ��ʱ���ȡ O(m) �� O(n) ����Ϣ�����֮�£�O(mn) �ı������ң�һ��һ�����ң���ÿ�λ��� O(1) ��ʱ�䣬ֻ��ȡ�� O(1) ����Ϣ��

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // �Ȼ�ȡ��ǰ������к���
        int m = matrix.size(); // ����
        int n = matrix[0].size();// ����

        // ������ʼ��������
        int row = 0; 
        int col = n - 1;

        // ��ʼѭ������(���������һ�е�ʱ������εݼ�����)
        while (row < m && col >= 0) {
            
            // �Ƚ����Ͻ�Ԫ��
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                row++; // ��һ������ʣ��Ԫ��ȫ��С��target
            }
            else {
                col--; // ��һ������ʣ��Ԫ��ȫ������target
            }
        
        }
        return false;
    }
};

#endif // DEBUG

