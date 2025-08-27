#include<vector>
#include<unordered_map>
#include<climits>
#include<iostream>

using namespace std;

// https://leetcode.cn/problems/coin-change/solutions/6568/dong-tai-gui-hua-tao-lu-xiang-jie-by-wei-lai-bu-ke
// ����������ͣ�https://leetcode.cn/problems/coin-change/solutions/778891/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-sq9n

// ��̬�滮�ĺ������������
// ��Ϊ����������ڡ��ص������⡹�����������ٵĻ�Ч�ʻἫ����£�
// ������Ҫ������¼�����ߡ�DP table�����Ż���ٹ��̣����ⲻ��Ҫ�ļ��㡣

// �Զ����µ�д��
// ʱ�临�Ӷ�Ϊ������������ * ÿ���������ʱ�䣺O��n*m��,n ΪĿ���mΪӲ��������
// �ռ临�Ӷȣ�����ÿ�ζ�Ҫ�ݹ飬�ܵݹ����Ϊn������ջ�ռ临�Ӷ�ΪO��n����ͬʱ����¼����n���������ܿռ临�Ӷ�ΪO��n��
class Solution_t2b {

public:
	
	unordered_map<int, int> memo; // ֻ��Ҫһ���������м�¼���ù�ϣ��

	int dp(int amount, const vector<int>& coins){
		// ���ұ���¼�������ظ�����
		if (memo.find(amount) != memo.end()) return memo[amount];

		// base case
		if (amount == 0) return 0;
		if (amount < 0) return -1;

		int res = INT_MAX; // ��ʼֵΪ��������������forѭ������Ч��
		for (int coin : coins) {
			int subproblem = dp(amount - coin, coins); // ע�����ȫƽ������ͬ���������ֵ�仯��������ȥ���������Ĵ�С
			if (subproblem == -1) continue; // ����������޽⣬������
			res = min(res, 1 + subproblem); // ȡ��Сֵ

		}

		// ���뱸��¼
		memo[amount] = (res == INT_MAX) ? -1 : res;
		return memo[amount];
	}

	int coinChange(vector<int>& coins, int amount) {
	
		return dp(amount, coins);
	}

};

// �Ե����ϵķ���
// ʱ�临�Ӷȣ����������ΪO��n * m��
// �ռ临�Ӷȣ�ʹ��һ��dp���飬�ռ临�Ӷ�ΪO��n��
class Solution_b2t {

public:
	int coinChande(vector<int>& coins, int amount) {
		// ��ʼ��dp���飬dp[i]����Ϊ�����i����Ǯ���ٵ�����(����Ϊ״̬ + 1��ֹ���)
		vector<int> dp(amount + 1, amount + 1);

		// base case
		dp[0] = 0;

		// ������ڱ�������dp��������״̬
		for (int i = 0; i < dp.size(); i++) {
			// �ڲ����ڶ���ÿ��dp�����ڵ�״̬���������������
			for (int coin : coins) {
				
				// �������޽⣬����
				if (i - coin < 0) continue; //ע�����ﲻ��return !!!
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
	cout << "Minimum number of coins: " << result << endl;  // �������Ӳ������
	return 0;
}
#endif // DEBUG
