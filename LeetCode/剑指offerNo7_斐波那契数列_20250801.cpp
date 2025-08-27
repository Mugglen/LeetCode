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
     * @param n int����
     * @return int����
     */
    int Fibonacci(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        vector<int> dp(n, 0); // ע��쳲�����ͷ������1��1
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n-1]; // ע���n���� n - 1
    }
};
#endif // DEBUG1