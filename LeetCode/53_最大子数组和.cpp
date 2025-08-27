#include <vector>
#include <iostream>
using namespace std;

// 前缀和讲解链接
// https://leetcode.cn/problems/maximum-subarray/solutions/2533977/qian-zhui-he-zuo-fa-ben-zhi-shi-mai-mai-abu71
// 时间复杂度：O(n)，其中 n 为 nums 的长度。
// 空间复杂度：O(1)。仅用到若干额外变量。
class Solution{

public:

	int maxSubArray(vector<int>& nums) {

		// 初始化最小标签
		int ans = INT_MIN;
		
		int min_pre_sum = 0;
		int pre_sum = 0;

		// 问题转换成贪心算法，121买卖股票的最佳时机了
		for (int x : nums) {
			// 计算前缀和
			pre_sum += x; 
			// 更新最大子数组和
			ans = max(ans, pre_sum - min_pre_sum);
			// 更新最小前项和
			min_pre_sum = min(min_pre_sum, pre_sum);
		
		
		}
		return ans;
	}


};

//#define DEBUG
#ifdef DEBUG

int main() {

	Solution solution;

	vector<int> nums = { -2, 1, -3, 4 - 1, 2, 1, -5, 4 };

	int maxSub = solution.maxSubArray(nums);

	cout << "maxSub:" << maxSub << endl;

}


#endif // DEBUG
