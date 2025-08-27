#include <vector>

using namespace std;

// https://leetcode.cn/problems/product-of-array-except-self/solutions/2783788/qian-hou-zhui-fen-jie-fu-ti-dan-pythonja-86r1
// �ֳ���������������˻�

class Solution {

public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		
		// ����۳�(��ǰ����ռ����������ܣ���ʼ��Ϊ1���ڳ˻�)
		vector<int> pre(n, 1);
		for (int i = 1; i < n; i++) {
			// ʹ����������ǰһλ���͵�ǰλ�õ�nums��ǰһλ��ˣ����ǵ�ǰλ�����Ԫ���۳�
			pre[i] = pre[i - 1] * nums[i - 1];
		}

		vector<int> suf(n, 1);
		// ע��n-2�ǵ����ڶ���Ԫ�أ�����������0��ʼ
		for (int i = n - 2; i >= 0; i--) {
			suf[i] = suf[i + 1] * nums[i + 1];
		
		}

		vector<int> ans(n);
		for (int i = 0; i < n; i++) {
			ans[i] = pre[i] * suf[i];
		
		}
		return ans;

	}




};