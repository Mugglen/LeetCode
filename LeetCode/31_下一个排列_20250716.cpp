#include <vector>
using namespace std;
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

		int n = nums.size();

		// ��һ�������ұ߿�ʼ���ҵ���һ�������������Ԫ�أ�����˵��һ��С���Ҳ�����Ԫ�ص�����
		int i = n - 2; // �ӵ����ڶ���Ԫ�ؿ�ʼ
		while (i >= 0 && nums[i] >= nums[i + 1]) {
			i--;
		}

		// ����ҵ��˽���ڶ�����û�ҵ�˵������Ϊ���򣬱�������������У�ֱ�ӷ�ת
		if (i >= 0) {
			// �ڶ��������������ҵ� nums[i] �ұ���С�Ĵ��ڣ�����˵��һ�����ڣ� nums[i]���� nums[j]
			int j = n - 1; // �����һ��Ԫ�ؿ�ʼ
			while (nums[j] <= nums[i]) { 
				// ע��������С�ڵ��ڣ���ΪҪ�ҵ����� nums[i] ������ͬʱ����������nums[i]�Ҳ౾���ǽ������е�����
				j--;
			}
			// ���� nums[i] �� nums[j]
			swap(nums[i], nums[j]);
		}

		// ����������ת nums[i]�Ҳ��Ԫ�أ��������ǽ����ŵ���һ������
		reverse(nums.begin() + i + 1, nums.end());

    }
};
#endif // DEBUG
