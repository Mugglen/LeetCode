#include <vector>
using namespace std;

//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param number int����
     * @return int����
     */
    int jumpFloorII(int number) {
        // �������ܿ�������n��̨�ף�dp����ô�0��ʼ�㣨����������Ҳ�Ǵ�0��ʼ��
        // ���ƹ�ϵ��dp[n] = dp[n-1]+dp[n-2]+...+dp[1], 1<=n<=20
        // �������ƹ�ϵ�����������������ܵ���
        // Ŷdp[n-1] = dp[n-2]+...+dp[1]������dp[n] = 2dp[n-1]
        if (number == 1) return 1;
        return 2 * jumpFloorII(number - 1);
    }
};
#endif // DEBUG1


// ���dp[n] = 2*dp[n-1]
//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:

    int jumpFloorII(int number) {
        // �������ܿ�������n��̨�ף�dp����ô�0��ʼ�㣨����������Ҳ�Ǵ�0��ʼ��
        // ���ƹ�ϵ��dp[n] = dp[n-1]+dp[n-2]+...+dp[1], 1<=n<=20
        // �������ƹ�ϵ�����������������ܵ���
        // Ŷdp[n-1] = dp[n-2]+...+dp[1]������dp[n] = 2dp[n-1]
        if (number == 1) return 1;
        // ��ʼ��dp
        vector<int> dp(number + 1, 0); // ���ʼ��һ�������±��1��ʼ
        dp[1] = 1;
        for (int i = 2; i <= number; i++) {
            dp[i] = 2*dp[i - 1];
        }
        return dp[number];
    }
};
#endif // DEBUG2
