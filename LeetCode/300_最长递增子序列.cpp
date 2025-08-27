#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/longest-increasing-subsequence/solutions/24173/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2


// ע�Ȿ��Ҫ�󣺲�û��Ҫ��һ�����������Ӵ�������Ҫ�ϸ��������Ԫ��˳�򲻱�
// ʱ�临�Ӷ�O��n^2���������ڲ����n��
// �ռ临�Ӷ�O��n��:dp���鳤��

class Solution_dp {

public:
	int lengthOfLIS(vector<int>& nums) {
		
		// �쳣����
		if (nums.empty()) return 0;

		// ����DP���飨dp[i]��ʾnums����nums[i]��β��������г��ȣ�
		vector<int> dp(nums.size(), 1);
	
		// ��ʼ�Ե����ϼ���(����dp�����ÿ��ֵ������j�ķ�Χ��i������)
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				// ע�⣡��������Ҫ©��״̬ת������
				if (nums[j] < nums[i]) {
					// ״̬ת�Ʒ���
					dp[i] = max(dp[i], dp[j] + 1);
				}

			}
		}
		// ע�⣡������������max,max�ǱȽ������������ֵ���ҷ��ص��Ǹ���������*���øõ���������ֵ
		return *max_element(dp.begin(), dp.end());

	
	}

};


// �Ż��汾
// dp �Ӷ��ֲ���
class Solution {

public:
	int lengthOfLIS(vector<int>& nums) {

		// �쳣����
		if (nums.empty()) return 0;

		// ����DP���飨dp_tails[k]��ʾ����Ϊ k+1 ��������β��Ԫ�ص�ֵ����
		vector<int> dpTails;
		//int length = 0; //�洢LIS�ĳ���

		// ��ʼ�Ե����ϼ���(����dp�����ÿ��ֵ������j�ķ�Χ��i������)
		for (int num : nums) {
			//���ֲ���[0,res) �б����䣬�ҳ� nums[k] �Ĵ�С�ֽ�㣬ע���ǲ�
			int left = 0, right = dpTails.size();

			// Ҫ��dpTails���ҵ���һ���ȵ�ǰnum���
			while (left < right) {
				int mid = left + (right - left) / 2; // (right - left) / 2 ���Զ�����ȡ��

				if (dpTails[mid] < num) {
					left = mid + 1;
				}
				else { // deTails[mid] >= num
					right = mid;
				}
			}

			// ����ҵ����ʵ�λ��
			if (left < dpTails.size()) {
				dpTails[left] = num;
			}
			else {
				// ���δ�ҵ�����λ�ã���ζ�� num ������Ϊ�µ����ֵ
				dpTails.push_back(num);
				//length++;
			}


		}
		
		return dpTails.size();


	}

};

//#define DEBUG
#ifdef DEBUG
int main() {

	Solution solution;
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << "����������г��ȣ�" << solution.lengthOfLIS(nums) << endl;

	return 0;
}
#endif // DEBUG
