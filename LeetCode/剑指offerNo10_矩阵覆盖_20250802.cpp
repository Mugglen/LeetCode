#include <vector>
using namespace std;

//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    int rectCover(int number) {

        // 递推关系
        // 在2*n的第n个选择竖着摆一个的时候，dp[n] = dp[n-1]
        // 在2*n的第n个不选择竖着摆一个的时候，那就得最后n-1和n的位置横着摆两个dp[n] = dp[n-2]
        // 所以dp[n] = dp[n-1] + dp[n-2];
        // 同时dp[1] = 1, dp[2] = 2 //那好像也是斐波那契数列的感觉
        vector<int> dp(number + 1, 0);
        // dp[n]表示用 n 个 2*1 的小矩形无重叠地覆盖一个 2*n 的大矩形，从同一个方向看总共有多少种不同的方法
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};
#endif // DEBUG1