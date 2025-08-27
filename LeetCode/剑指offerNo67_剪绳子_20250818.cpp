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


class Solution {
public:
    // 自底向上的dp
    int cutRope(int n) {
        // 不超过3的直接计算
        if (n <= 3) return n - 1;
        // dp[i]表示长度为i的绳子可以被剪出来的最大乘积
        // 需要dp[n],dp[0]无意义，所以多加一位
        vector<int> dp(n + 1, 0);
        // 预先赋值的位数是被剪掉的乘积只会比不剪之前小的，就是剪成m段的m = 1，就是本身最大
        dp[1] = 1; // 
        dp[2] = 2; // 1 * 1
        dp[3] = 3; // 1 * 2
        // 遍历后序每个长度，枚举最后剩下的一段长为j
        for (int i = 4; i <= n; i++) {
            // 其实后面的初始值也应该等于dp[i] = i，不然整根绳子不剪的情况没有考虑进去
            //for (int j = 1; j < i; j++) {
            // 优化点！！！！可以只遍历一半，但必须超过或者取满一半，所以是小于等于，例如dp[5] = 2 * dp[3] = 3 * dp[2]
            for (int j = 1; j <= i/2; j++) {
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        return dp[n];
    }
};


#endif // DEBUG1