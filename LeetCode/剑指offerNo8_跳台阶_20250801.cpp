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
    int jumpFloor(int number) {
        // 其实就是斐波那契数列，我们用dp的自底向上来做
        // 初始化dp数组
        vector<int> dp(number, 0);
        dp[0] = 1; // 第一级台阶就跳一步
        dp[1] = 2; // 第二集台阶可以一次跳2步，或者跳两次1步
        if (number <= 2) return dp[number - 1]; // 注意number从1开始
        for (int i = 2; i < number; i++) {
            // 从上一个台阶跳1步，或者从上上个台阶跳2步
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number - 1];
    }
};


#endif // DEBUG1