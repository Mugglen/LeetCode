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
    int jumpFloor(int number) {
        // ��ʵ����쳲��������У�������dp���Ե���������
        // ��ʼ��dp����
        vector<int> dp(number, 0);
        dp[0] = 1; // ��һ��̨�׾���һ��
        dp[1] = 2; // �ڶ���̨�׿���һ����2��������������1��
        if (number <= 2) return dp[number - 1]; // ע��number��1��ʼ
        for (int i = 2; i < number; i++) {
            // ����һ��̨����1�������ߴ����ϸ�̨����2��
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[number - 1];
    }
};


#endif // DEBUG1