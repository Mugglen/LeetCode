#include <vector>

using namespace std;

// https://leetcode.cn/problems/product-of-array-except-self/solutions/2783788/qian-hou-zhui-fen-jie-fu-ti-dan-pythonja-86r1
// 分成左右两个部分求乘积

class Solution {

public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		
		// 左侧累乘(提前分配空间可以提高性能，初始化为1用于乘积)
		vector<int> pre(n, 1);
		for (int i = 1; i < n; i++) {
			// 使用左积数组的前一位，和当前位置的nums的前一位相乘，就是当前位置左侧元素累乘
			pre[i] = pre[i - 1] * nums[i - 1];
		}

		vector<int> suf(n, 1);
		// 注意n-2是倒数第二个元素，数组索引从0开始
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