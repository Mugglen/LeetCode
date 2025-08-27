#include<vector>

using namespace std;


// https://leetcode.cn/problems/house-robber/solutions/138131/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap

//����������
//д��������ĵ��ƹ�ϵ
//ȷ�� DP ����ļ���˳��
//�ռ��Ż�����ѡ

class Solution {

public:
	int rob(vector<int>& nums) {

		// �쳣����
		if (nums.size() == 0) return 0;
		
		// ������
		// f(k) = ͵[0,k)�����е������

		// f(0) = 0;
		// f(1) = nums[0];
		// f(k) = max{rob(k-1), nums[k - 1] + rob(k-2)}

		int N = nums.size();
		vector<int> dp(N + 1, 0);

		// DP����洢ÿ��������Ľ��,ע���ʼ����ʼ����
		dp[0] = 0;
		dp[1] = nums[0];

		for (int k = 2; k <= N; k++) {
			dp[k] = max(dp[k - 1], nums[k - 1] + dp[k - 2]);
		}
		return dp[N];
	
	}

};