#include <vector>
using namespace std;

//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    int rectCover(int number) {

        // ���ƹ�ϵ
        // ��2*n�ĵ�n��ѡ�����Ű�һ����ʱ��dp[n] = dp[n-1]
        // ��2*n�ĵ�n����ѡ�����Ű�һ����ʱ���Ǿ͵����n-1��n��λ�ú��Ű�����dp[n] = dp[n-2]
        // ����dp[n] = dp[n-1] + dp[n-2];
        // ͬʱdp[1] = 1, dp[2] = 2 //�Ǻ���Ҳ��쳲��������еĸо�
        vector<int> dp(number + 1, 0);
        // dp[n]��ʾ�� n �� 2*1 ��С�������ص��ظ���һ�� 2*n �Ĵ���Σ���ͬһ�������ܹ��ж����ֲ�ͬ�ķ���
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number];
    }
};
#endif // DEBUG1