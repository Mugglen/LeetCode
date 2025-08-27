#include<vector>

using namespace std;


// https://leetcode.cn/problems/PzWKhm/solutions/984824/jian-zhi-offer-ii-090-huan-xing-fang-wu-0znjv
// https://leetcode.cn/problems/PzWKhm/solutions/2128140/gao-bie-te-pan-jian-ji-xie-fa-pythonjava-ameq

// �Ż����ռ�İ汾
// ʱ�临�Ӷ�O��n��
// �ռ临�Ӷ�O��1��
class Solution {

private:

	// ����������������ͨ��ҽ���
	int rob1(vector<int>& nums, int start, int end) {
		// ��ǰһ��λ�ú͵�ǰλ�����������ֵ
		int pre = 0, cur = 0;

		// ������
		// f(k) = ͵[0,k)�����е������

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

		// ����������Էֳ�͵��һ��Ͳ�͵��һ��
		return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));

	}


};