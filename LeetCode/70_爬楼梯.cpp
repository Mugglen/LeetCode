#include <vector>

using namespace std;

// 超时的递归,最原始的思路
// 时间复杂度：O（2^n）
// 空间复杂度，O（n）
class Solution_violence {

public:
	int climbStairs(int n) {
		return dfs(n);
	
	}

	int dfs(int i) {
		// 边界处理
		if (i <= 1) {
			return 1;
		}
		return dfs(i - 1) + dfs(i - 2);
	
	}

};

// https://leetcode.cn/problems/climbing-stairs/solutions/2560716/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-7zm1
class Solution {

private:

	// memo 数组的初始值一定不能等于要记忆化的值！
	vector<int> memo;

	// 注意到「先爬 1 个台阶，再爬 2 个台阶」和「先爬 2 个台阶，再爬 1 个台阶」，
	// 都相当于爬 3 个台阶，都会从 dfs(i) 递归到 dfs(i−3)。

	int dfs(int i) {

		// 边界处理
		if (i <= 1) {
			return 1;
		}

		// 注意这里是引用
		int& res = memo[i];

		// 如果之前计算过当前层的结果就直接取
		if (res) {
			return res;
			
		}

		// 记忆当前结果（通过引用修改）
		return res = dfs(i - 1) + dfs(i - 2);
	
	}

public:
	int climbStairs(int n) {
		// 因为要使用索引访问vector，得确保vector大小足够存放每层计算出来的走法
		memo.resize(n + 1);
		return dfs(n);
	}

};