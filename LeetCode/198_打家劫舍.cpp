#include<vector>

using namespace std;


// https://leetcode.cn/problems/house-robber/solutions/138131/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap

//定义子问题
//写出子问题的递推关系
//确定 DP 数组的计算顺序
//空间优化（可选

class Solution {

public:
	int rob(vector<int>& nums) {

		// 异常处理
		if (nums.size() == 0) return 0;
		
		// 子问题
		// f(k) = 偷[0,k)房间中的最大金额

		// f(0) = 0;
		// f(1) = nums[0];
		// f(k) = max{rob(k-1), nums[k - 1] + rob(k-2)}

		int N = nums.size();
		vector<int> dp(N + 1, 0);

		// DP数组存储每个子问题的结果,注意初始化初始条件
		dp[0] = 0;
		dp[1] = nums[0];

		for (int k = 2; k <= N; k++) {
			dp[k] = max(dp[k - 1], nums[k - 1] + dp[k - 2]);
		}
		return dp[N];
	
	}

};