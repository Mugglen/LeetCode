#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG

class Solution {

public:

	// Ϊ�˲�ÿ��ɾ��Ԫ�ض�Ҫ�ƶ������Ԫ�أ�ʹ��˫ָ��
	int removeElement(vector<int>& nums, int val) {

		// ��ָ���������ָ�뱣����һ��ȷ�ϲ���Ŀ��Ԫ�ص�λ�õ���һ��λ��
		int slow = 0;
		int fast = 0;
		// ����Ԫ������
		int res = 0;
		if (nums.empty())return res;

		for (fast; fast < nums.size(); fast++) {
			
			// �ҵ��˾�ɾ��
			if (nums[fast] == val) {
				nums[fast] = 0;
				//fast++;//��ע�⣡��������㣬forѭ�����Ѿ������ˣ�
			}
			else {
				nums[slow] = nums[fast];
				slow++;
				//fast++;//��ע�⣡��������㣬forѭ�����Ѿ������ˣ�
				res++;
			}
		
		
		}
		return res;

	}
};




#endif // DEBUG
