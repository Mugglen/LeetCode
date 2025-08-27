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
    // �Ե����ϵ�dp
    int cutRope(int n) {
        // ������3��ֱ�Ӽ���
        if (n <= 3) return n - 1;
        // dp[i]��ʾ����Ϊi�����ӿ��Ա������������˻�
        // ��Ҫdp[n],dp[0]�����壬���Զ��һλ
        vector<int> dp(n + 1, 0);
        // Ԥ�ȸ�ֵ��λ���Ǳ������ĳ˻�ֻ��Ȳ���֮ǰС�ģ����Ǽ���m�ε�m = 1�����Ǳ������
        dp[1] = 1; // 
        dp[2] = 2; // 1 * 1
        dp[3] = 3; // 1 * 2
        // ��������ÿ�����ȣ�ö�����ʣ�µ�һ�γ�Ϊj
        for (int i = 4; i <= n; i++) {
            // ��ʵ����ĳ�ʼֵҲӦ�õ���dp[i] = i����Ȼ�������Ӳ��������û�п��ǽ�ȥ
            //for (int j = 1; j < i; j++) {
            // �Ż��㣡����������ֻ����һ�룬�����볬������ȡ��һ�룬������С�ڵ��ڣ�����dp[5] = 2 * dp[3] = 3 * dp[2]
            for (int j = 1; j <= i/2; j++) {
                dp[i] = max(dp[i], j * dp[i - j]);
            }
        }
        return dp[n];
    }
};


#endif // DEBUG1