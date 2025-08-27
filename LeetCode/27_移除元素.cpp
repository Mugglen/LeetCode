#include <vector>

using namespace std;



class Solution {

public:

	int removeElement(vector<int>& nums, int val) {

		// ��ָ��Ҫ����Ѿ�����õ�Ԫ�ص�ĩβ
		int slowPtr = 0;

		// ��ָ�����ڱ���
		for (int fastPtr = 0; fastPtr < nums.size(); fastPtr++) {
			if (val != nums[fastPtr]) {
				nums[slowPtr] = nums[fastPtr];
				slowPtr = slowPtr + 1;
			}
		
		}
		return slowPtr;
	
	}


};