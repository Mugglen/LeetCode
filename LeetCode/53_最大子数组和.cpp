#include <vector>
#include <iostream>
using namespace std;

// ǰ׺�ͽ�������
// https://leetcode.cn/problems/maximum-subarray/solutions/2533977/qian-zhui-he-zuo-fa-ben-zhi-shi-mai-mai-abu71
// ʱ�临�Ӷȣ�O(n)������ n Ϊ nums �ĳ��ȡ�
// �ռ临�Ӷȣ�O(1)�����õ����ɶ��������
class Solution{

public:

	int maxSubArray(vector<int>& nums) {

		// ��ʼ����С��ǩ
		int ans = INT_MIN;
		
		int min_pre_sum = 0;
		int pre_sum = 0;

		// ����ת����̰���㷨��121������Ʊ�����ʱ����
		for (int x : nums) {
			// ����ǰ׺��
			pre_sum += x; 
			// ��������������
			ans = max(ans, pre_sum - min_pre_sum);
			// ������Сǰ���
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
