#include<vector>
#include<unordered_map>
#include<climits>
#include<iostream>

using namespace std;

// https://leetcode.cn/problems/coin-change/solutions/6568/dong-tai-gui-hua-tao-lu-xiang-jie-by-wei-lai-bu-ke
// 背包问题解释：https://leetcode.cn/problems/coin-change/solutions/778891/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-sq9n

// 动态规划的核心问题是穷举
// 因为这类问题存在「重叠子问题」，如果暴力穷举的话效率会极其低下，
// 所以需要「备忘录」或者「DP table」来优化穷举过程，避免不必要的计算。

// 自顶向下的写法
// 时间复杂度为：子问题总数 * 每个子问题的时间：O（n*m）,n 为目标金额，m为硬币种类数
// 空间复杂度：最坏情况每次都要递归，总递归深度为n，所以栈空间复杂度为O（n），同时备忘录存了n个，所以总空间复杂度为O（n）
class Solution_t2b {

public:
	
	unordered_map<int, int> memo; // 只需要一个索引进行记录，用哈希表

	int dp(int amount, const vector<int>& coins){
		// 查找备忘录，避免重复计算
		if (memo.find(amount) != memo.end()) return memo[amount];

		// base case
		if (amount == 0) return 0;
		if (amount < 0) return -1;

		int res = INT_MAX; // 初始值为正无穷（在下面这个for循环内生效）
		for (int coin : coins) {
			int subproblem = dp(amount - coin, coins); // 注意和完全平方数不同，这里的总值变化不会连带去调整背包的大小
			if (subproblem == -1) continue; // 如果子问题无解，则跳过
			res = min(res, 1 + subproblem); // 取最小值

		}

		// 记入备忘录
		memo[amount] = (res == INT_MAX) ? -1 : res;
		return memo[amount];
	}

	int coinChange(vector<int>& coins, int amount) {
	
		return dp(amount, coins);
	}

};

// 自底向上的方法
// 时间复杂度：两层遍历，为O（n * m）
// 空间复杂度：使用一个dp数组，空间复杂度为O（n）
class Solution_b2t {

public:
	int coinChande(vector<int>& coins, int amount) {
		// 初始化dp数组，dp[i]定义为给金额i换零钱最少的数量(长度为状态 + 1防止溢出)
		vector<int> dp(amount + 1, amount + 1);

		// base case
		dp[0] = 0;

		// 外层用于遍历计算dp数组所有状态
		for (int i = 0; i < dp.size(); i++) {
			// 内层用于对于每个dp数组内的状态，遍历背包，求解
			for (int coin : coins) {
				
				// 子问题无解，跳过
				if (i - coin < 0) continue; //注意这里不是return !!!
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}

		}
		return (dp[amount] == amount + 1 ? -1 : dp[amount]);
	}

};


//#define DEBUG
#ifdef DEBUG
int main() {
	Solution_t2b solution;
	vector<int> coins = { 1, 2, 5 };
	int amount = 11;
	int result = solution.coinChange(coins, amount);
	cout << "Minimum number of coins: " << result << endl;  // 输出最少硬币数量
	return 0;
}
#endif // DEBUG
