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
     * @param number int整型
     * @return int整型
     */
    int jumpFloorII(int number) {
        // 本题青蛙可以跳上n级台阶，dp数组得从0开始算（不过好像本来也是从0开始）
        // 递推关系：dp[n] = dp[n-1]+dp[n-2]+...+dp[1], 1<=n<=20
        // 不过递推关系里项数不定，好像不能递推
        // 哦dp[n-1] = dp[n-2]+...+dp[1]，所以dp[n] = 2dp[n-1]
        if (number == 1) return 1;
        return 2 * jumpFloorII(number - 1);
    }
};
#endif // DEBUG1


// 变成dp[n] = 2*dp[n-1]
//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:

    int jumpFloorII(int number) {
        // 本题青蛙可以跳上n级台阶，dp数组得从0开始算（不过好像本来也是从0开始）
        // 递推关系：dp[n] = dp[n-1]+dp[n-2]+...+dp[1], 1<=n<=20
        // 不过递推关系里项数不定，好像不能递推
        // 哦dp[n-1] = dp[n-2]+...+dp[1]，所以dp[n] = 2dp[n-1]
        if (number == 1) return 1;
        // 初始化dp
        vector<int> dp(number + 1, 0); // 多初始化一个，让下标从1开始
        dp[1] = 1;
        for (int i = 2; i <= number; i++) {
            dp[i] = 2*dp[i - 1];
        }
        return dp[number];
    }
};
#endif // DEBUG2
