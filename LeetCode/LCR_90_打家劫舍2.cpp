#include<vector>

using namespace std;


// https://leetcode.cn/problems/PzWKhm/solutions/984824/jian-zhi-offer-ii-090-huan-xing-fang-wu-0znjv
// https://leetcode.cn/problems/PzWKhm/solutions/2128140/gao-bie-te-pan-jian-ji-xie-fa-pythonjava-ameq

// 优化过空间的版本
// 时间复杂度O（n）
// 空间复杂度O（1）
class Solution {

private:

	// 辅助函数，计算普通打家劫舍
	int rob1(vector<int>& nums, int start, int end) {
		// 在前一个位置和当前位置抢到的最大值
		int pre = 0, cur = 0;

		// 子问题
		// f(k) = 偷[0,k)房间中的最大金额

		// f(0) = 0;
		// f(1) = nums[0];
		// f(k) = max{rob(k-1), nums[k - 1] + rob(k-2)}
		for (int i = start; i < end; i++) {
			int newValue = max(cur, pre + nums[i]);

			pre = cur;
			cur = newValue;
		}
		return cur;
	}



public:

	int rob(vector<int> nums) {
		int n = nums.size();

		// 环形问题可以分成偷第一间和不偷第一间
		return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));

	}


};