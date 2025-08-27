#include <vector>

using namespace std;


// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solutions/1692872/by-jyd-cu90


class Solution {

public:
	int maxProfit(vector<int>& prices) {
		int cost = INT_MAX;
		int profit = 0;

		for (int price : prices) {
			cost = min(cost, price);
			profit = max(profit, price - cost);
		}
		return profit;
	}
};