#include <vector>

using namespace std;

// https://leetcode.cn/problems/pascals-triangle/solutions/2784222/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-z596

// ʱ�临�Ӷȣ�O(numRows^2)
// �ռ临�Ӷȣ�O(1)

class Solution {

public:
	vector<vector<int>> generate(int numRows) {
		
		// ��ʼ��������󣬵��ǲ��涨�п�
		vector<vector<int>> c(numRows);
		
		for (int i = 0; i < numRows; i++) {
			// �������ʣ��۲��ÿ���п�Ϊ�к�+1����0��ʼ��ͬʱ��ʼ��Ϊ1��ֱ�ӽ��ÿ�е�һ�����һ��Ԫ��
			c[i].resize(i + 1, 1);

			// ����������룬���ֳ���ÿ�е�һ�����һ��Ԫ����1�⣬ʣ�µ�ÿ��Ԫ����ǰһ��ͬλ��Ԫ�غ�ǰһ��Ԫ�صĺ�
			for (int j = 1; j < i; j++) { // (!!!!ע��j��1��ʼ��С��i����С��i+1)
				// ���Ϸ����� + ���Ϸ�����
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
		return c;
	
	}

};