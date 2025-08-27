#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {

public:

	// �����ƽ�
	// ʱ�临�Ӷȣ�O(n^2)��ѭ������n(n-1)/2��
	// �ռ临�Ӷȣ�O(1)��ֻʹ���˳�����������
	int maxProfitViolence(vector<int>& prices) {
		int n = (int)prices.size(), ans = 0; // ע�ⲻҪд��.max_size()�ˣ����ص��������������
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans = max(ans, prices[j] - prices[i]);
			}
		}
		return ans;
	}

	// ��������ȫ����ʷ��͵㣬����ÿ�ζ������ǽ���������Ȼ�������֮ǰ����ʷ��͵㡣
	// �������ʷ��͵㲢����Ҫ�������������ÿ�쿼�ǵ�ʱ��˳����¼�ġ�
	// ���ʱ�临�ӶȻ���O(N)������O(N^2)��
	int maxProfit(vector<int>& prices) {
		int minPrice = INT_MAX;
		int maxProfit = 0;

		// ̰�ĵľֲ������ſ�����һֱ����ֲ����ź���һ�μ���ֲ����ŵĲ���
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
