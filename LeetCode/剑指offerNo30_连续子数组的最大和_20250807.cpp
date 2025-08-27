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
	// 注意求的是和的最大值，不是区间，感觉就是53 最大子数组和，使用前缀和加贪心算法
    int FindGreatestSumOfSubArray(vector<int>& array) {
        // 初始化最小标签
        int ans = INT_MIN;

		int min_pre_sum = 0;
		int pre_sum = 0;

		// 问题转换成贪心算法，121买卖股票的最佳时机了
		for (int x : array) {
			// 就算前缀和
			pre_sum += x;
			// 更新最大子数组和
			ans = max(ans, pre_sum - min_pre_sum);
			// 更新最小前项和
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
	// 也可以用自底向上的dp
	int FindGreatestSumOfSubArray(vector<int>& array) {
		if (array.size() == 0) return 0;
		int maxNum = array[0];
		vector<int> dp(array.size(), 0);
		dp[0] = array[0];
		// dp[i]表示以array[i]结尾的最大子数组和
		for (int i = 1; i < array.size(); ++i) {
			// 因为是连续子数组，所以dp[i]可以是从array[i]本身开始算，也可以是array[i]加上前一个dp[i-1]，但不能是dp[i-1]本身，这样就不连续了
			dp[i] = max(array[i], array[i] + dp[i - 1]);
			maxNum = max(maxNum, dp[i]);
		}
		return maxNum;
	}
};

#endif // DEBUG2