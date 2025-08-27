#include <vector>

using namespace std;


//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int Fibonacci(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        vector<int> dp(n, 0); // 注意斐波那契头两个是1，1
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n-1]; // 注意第n个是 n - 1
    }
};
#endif // DEBUG1