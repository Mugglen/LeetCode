#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {

public:

	// 暴力破解
	// 时间复杂度：O(n^2)。循环运行n(n-1)/2次
	// 空间复杂度：O(1)。只使用了常数个变量。
	int maxProfitViolence(vector<int>& prices) {
		int n = (int)prices.size(), ans = 0; // 注意不要写成.max_size()了，返回的是容器的最大储量
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, prices[j] - prices[i]);
			}
		}
		return ans;
	}

	// 并不是求全局历史最低点，而是每次都假设是今天卖出，然后求今天之前的历史最低点。
	// 而这个历史最低点并不需要额外遍历，而是每天考虑的时候顺带记录的。
	// 因此时间复杂度还是O(N)而不是O(N^2)。
	int maxProfit(vector<int>& prices) {
		int minPrice = INT_MAX;
		int maxProfit = 0;

		// 贪心的局部最有优可能是一直保存局部最优和下一次计算局部最优的参数
		for (int price : prices) {
			maxProfit = max(maxProfit, price - minPrice);
			minPrice = min(price, minPrice);
		}
		return maxProfit;
	}
};

//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;
	vector<int> prices;



	cout << solution.maxProfitViolence(prices) << endl;
	return 0;

}

#endif // DEBUG
