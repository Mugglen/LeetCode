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
	// ע������Ǻ͵����ֵ���������䣬�о�����53 ���������ͣ�ʹ��ǰ׺�ͼ�̰���㷨
    int FindGreatestSumOfSubArray(vector<int>& array) {
        // ��ʼ����С��ǩ
        int ans = INT_MIN;

		int min_pre_sum = 0;
		int pre_sum = 0;

		// ����ת����̰���㷨��121������Ʊ�����ʱ����
		for (int x : array) {
			// ����ǰ׺��
			pre_sum += x;
			// ��������������
			ans = max(ans, pre_sum - min_pre_sum);
			// ������Сǰ���
			min_pre_sum = min(min_pre_sum, pre_sum);
		}
		return ans;
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2


class Solution {
public:
	// Ҳ�������Ե����ϵ�dp
	int FindGreatestSumOfSubArray(vector<int>& array) {
		if (array.size() == 0) return 0;
		int maxNum = array[0];
		vector<int> dp(array.size(), 0);
		dp[0] = array[0];
		// dp[i]��ʾ��array[i]��β������������
		for (int i = 1; i < array.size(); ++i) {
			// ��Ϊ�����������飬����dp[i]�����Ǵ�array[i]����ʼ�㣬Ҳ������array[i]����ǰһ��dp[i-1]����������dp[i-1]���������Ͳ�������
			dp[i] = max(array[i], array[i] + dp[i - 1]);
			maxNum = max(maxNum, dp[i]);
		}
		return maxNum;
	}
};

#endif // DEBUG2