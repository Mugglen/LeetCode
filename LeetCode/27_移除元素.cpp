#include <vector>

using namespace std;



class Solution {

public:

	int removeElement(vector<int>& nums, int val) {

		// 慢指针要标记已经处理好的元素的末尾
		int slowPtr = 0;

		// 快指针用于遍历
		for (int fastPtr = 0; fastPtr < nums.size(); fastPtr++) {
			if (val != nums[fastPtr]) {
				nums[slowPtr] = nums[fastPtr];
				slowPtr = slowPtr + 1;
			}
		
		}
		return slowPtr;
	
	}


};