

#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // https://leetcode.cn/problems/first-missing-positive/solutions/3655377/huan-zuo-wei-tong-guo-li-zi-li-jie-suan-qa94e/?envType=study-plan-v2&envId=top-100-liked
    int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
        for (int i = 0; i < n; i++) {
            // �����ǰѧ����ѧ���� [1, n] �е��ǣ�����û��������ȷ����λ��
            // nums[i](��ǰѧ��) != nums[nums[i] - 1]����ǰѧ��Ӧ�����ڵ���λ�ϣ��������ŵ�ѧ��ѧ�ţ���ע������������0��ʼ������0�������ǹ�ϵ�ķ�Χ�ڣ����Դ洢������Ҫ-1��
            while (1 <= nums[i] && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                // ��ô�ͽ��� nums[i] �� nums[j]������j��i��ѧ��
				int j = nums[i] - 1; // j��i��ѧ�ţ�ע������������0��ʼ������Ҫ-1
                swap(nums[i], nums[j]);
            }
        }

        // ��λ������������ʼ���ҵ�һ��ѧ������λ��Ų�ƥ���ѧ��
        for (int i = 0; i < n; i++) {
			if (nums[i] != i + 1) { // ע����λ���+1���ܺ�ѧ�Ŷ�Ӧ
				return i + 1; // ���ص�һ��ѧ������λ��Ų�ƥ���ѧ����ѧ��s
            }
        }

		// �������ѧ����ѧ�Ŷ�����λ���ƥ�䣬��ô��һ��ȱʧ������������n + 1
		return n + 1;
    }
};
#endif // DEBUG
