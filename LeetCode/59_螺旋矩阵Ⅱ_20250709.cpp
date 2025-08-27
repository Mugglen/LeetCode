#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {

    int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 右下左上四个方向
public:
    vector<vector<int>> generateMatrix(int n) {

        vector ans(n, vector<int>(n)); // 注意这个n*n的矩阵初始化方式
        int i = 0, j = 0, curDirection = 0;
        // 确定循环次数(错误点1！！！！val要从1开始， 同时因为val从1开始的所以循环结束条件为 <= 不是 <)
        for (int val = 1; val <= n * n; val++) { 

            ans[i][j] = val;

            // 计算下一步, curDirection表示当前方向
            int x = i + direction[curDirection][0];
            int y = j + direction[curDirection][1];

            // 如果（x, y）出界或者已经填入内容
            // 注意判断条件除了边界要加上判断有没有值，有值就是绕了一圈
            if (x < 0 || x >= n || y < 0 || y >= n || ans[x][y]) { 
                // 注意是 + 1后才取余数，是在curDirection到3时下一个是0
                curDirection = (curDirection + 1) % 4; 
            }

            // 真正的步进
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

    int direction[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; // 右下左上四个方向(按顺序就是顺时针)
public:
    vector<vector<int>> generateMatrix(int n) {

        // 初始化结果
        vector<vector<int>> ans(n, vector<int>(n));
        int i = 0, j = 0, curDirect = 0;

        for (int val = 1; val <= n * n; val++) {
            
            ans[i][j] = val;

            // 判断下一位是否需要转向
            int nextI = i + direction[curDirect][0];
            int nextJ = j + direction[curDirect][1];
            
            if (nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= n || ans[nextI][nextJ]) {
                // 转向
                curDirect = (curDirect + 1) % 4;
            }

            // 移动
            i += direction[curDirect][0];
            j += direction[curDirect][1];
        
        }
        return ans;

    }
};
#endif // PRETICE