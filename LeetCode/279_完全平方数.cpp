#include <iostream>
#include <cmath>
#include <climits>
//#include <cstring>


using namespace std;

// https://leetcode.cn/problems/perfect-squares/solutions/2830762/dong-tai-gui-hua-cong-ji-yi-hua-sou-suo-3kz1g

// 定义：dfs(i, j)为从前i个完全平方数中选一些数（可以重复选），满足元素和恰好等于j，最少要选的数字个数

// 子问题：选不选第i个完全平方数i^2
// 
// 分情况：j < i^2时
// 不能选：问题变为从前i-1个中选：dfs(i, j) = dfs(i-1, j)
// 
// 分情况：j > i^2时
// 可以选：问题变为要比较在前i - 1个中选好还是选了i^2好

// （注意要写在类外，类内会报错，但是在leetcode上能运行）
// 时间复杂度：O（N * sqrt(N)）
// 空间复杂度：O（N）
int memo[101][10001];

void init() {
	memset(memo, -1, sizeof(memo));
}

// 深度优先搜索(DFS)函数，计算最少的完全平方数个数
int dfs(int i, int j) {

	// 异常处理
	if (i == 0) {
		// 如果j == 0，说明不需要任何平方数，返回0，否则返回 INT_MAX，表示无法组合
		return j == 0 ? 0 : INT_MAX;
	}

	int& res = memo[i][j];// 通过引用来减少内存消耗

	// 如果res 不等于 -1 ，表示之前计算过这个状态，直接返回之前的结果（在可以选i^2参与计算的时候会使用）
	if (res != -1) {
		return res;
	}

	// 拆分子问题的两种情况
	if (j < i * i) { // 如果 j 小于当前完全平方数 i*i ，无法选择该平方数
		res = dfs(i - 1, j); // 跳过当前平方数，递归计算剩下的情况
	}
	else {
		// 可以选择当前平方数 i*i，或者不选择(加1是因为dfs结果要加上已经选择的i^2代表的这个次数1)
		// 每层选择的次数累计就是通+1操作来的，有些层不用累计
		res = min(dfs(i - 1, j), dfs(i, j - i * i) + 1);

	}
	// 计算得到最小结果
	return res;


}

class Solution
{
	//（！！！！！！！！！！！注意！！！！！！！！！！！！）
	// 写在private里会触发中断，命令行打印不出东西
//private:
//	// 定义memo， 用于记忆化搜索，避免重复计算(数组大小通过题目提示j的最大值10^4估算)
//	int memo[101][10001];
//
//	void init() {
//		memset(memo, -1, sizeof(memo)); 
//	}
//
//	// 深度优先搜索(DFS)函数，计算最少的完全平方数个数
//	int dfs(int i, int j) {
//	
//		// 异常处理
//		if (i == 0) {
//			// 如果j == 0，说明不需要任何平方数，返回0，否则返回 INT_MAX，表示无法组合
//			return j == 0 ? 0 : INT_MAX;
//		}
//
//		int& res = memo[i][j];// 通过引用来减少内存消耗
//
//		// 如果res 不等于 -1 ，表示之前计算过这个状态，直接返回之前的结果（在可以选i^2参与计算的时候会使用）
//		if (res != -1) {
//			return res;
//		}
//
//		// 拆分子问题的两种情况
//		if (j < i * i) { // 如果 j 小于当前完全平方数 i*i ，无法选择该平方数
//			res = dfs(i - 1, j); // 跳过当前平方数，递归计算剩下的情况
//		}
//		else {
//			// 可以选择当前平方数 i*i，或者不选择(加1是因为dfs结果要加上已经选择的i^2代表的这个次数1)
//			res = min(dfs(i - 1, j), dfs(i, j - i * i) + 1);
//			
//		}
//		// 计算得到最小结果
//		return res;
//
//
//	}

public:
	// 主函数，计算最少的完全平方数个数
	int numSquares(int n) {
	
		init(); // 初始化 memo 数组
		// 注意这里的递归入口是sqrt(n)
		return dfs(int(sqrt(n)), n); // 调用dfs 函数，初始化从 sqrt(n) 开始递归， n 为目标值
	}

};

//#define DEBUG
#ifdef DEBUG
int main() {

	Solution solution;
	int n = 12;

	cout << "最少的完全平方数个数： " << solution.numSquares(n) << endl;

	return 0;

}
#endif // DEBUG

