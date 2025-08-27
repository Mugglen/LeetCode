#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG

class Solution {

public:

	// 为了不每次删除元素都要移动后面的元素，使用双指针
	int removeElement(vector<int>& nums, int val) {

		// 快指针遍历，慢指针保存上一个确认不是目标元素的位置的下一个位置
		int slow = 0;
		int fast = 0;
		// 保存元素数量
		int res = 0;
		if (nums.empty())return res;

		for (fast; fast < nums.size(); fast++) {
			
			// 找到了就删掉
			if (nums[fast] == val) {
				nums[fast] = 0;
				//fast++;//（注意！！！错误点，for循环内已经自增了）
			}
			else {
				nums[slow] = nums[fast];
				slow++;
				//fast++;//（注意！！！错误点，for循环内已经自增了）
				res++;
			}
		
		
		}
		return res;

	}
};




#endif // DEBUG
