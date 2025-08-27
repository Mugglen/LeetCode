#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {

    int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // ���������ĸ�����
public:
    vector<vector<int>> generateMatrix(int n) {

        vector ans(n, vector<int>(n)); // ע�����n*n�ľ����ʼ����ʽ
        int i = 0, j = 0, curDirection = 0;
        // ȷ��ѭ������(�����1��������valҪ��1��ʼ�� ͬʱ��Ϊval��1��ʼ������ѭ����������Ϊ <= ���� <)
        for (int val = 1; val <= n * n; val++) { 

            ans[i][j] = val;

            // ������һ��, curDirection��ʾ��ǰ����
            int x = i + direction[curDirection][0];
            int y = j + direction[curDirection][1];

            // �����x, y����������Ѿ���������
            // ע���ж��������˱߽�Ҫ�����ж���û��ֵ����ֵ��������һȦ
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y]) { 
                // ע���� + 1���ȡ����������curDirection��3ʱ��һ����0
                curDirection = (curDirection + 1) % 4; 
            }

            // �����Ĳ���
            i += direction[curDirection][0];
            j += direction[curDirection][1];
        
        }
        return ans;

    }
};
#endif // DEBUG



//#define PRETICE
#ifdef PRETICE
class Solution {

    int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // ���������ĸ�����(��˳�����˳ʱ��)
public:
    vector<vector<int>> generateMatrix(int n) {

        // ��ʼ�����
        vector<vector<int>> ans(n, vector<int>(n));
        int i = 0, j = 0, curDirect = 0;

        for (int val = 1; val <= n * n; val++) {
            
            ans[i][j] = val;

            // �ж���һλ�Ƿ���Ҫת��
            int nextI = i + direction[curDirect][0];
            int nextJ = j + direction[curDirect][1];
            
            if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= n || ans[nextI][nextJ]) {
                // ת��
                curDirect = (curDirect + 1) % 4;
            }

            // �ƶ�
            i += direction[curDirect][0];
            j += direction[curDirect][1];
        
        }
        return ans;

    }
};
#endif // PRETICE