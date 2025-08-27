#include <vector>

using namespace std;

// 方法1：双指针法
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
	// 注意看题是移动到数组的末尾
    void moveZeroes(vector<int>& nums) {

        // 需要双指针，一个维护0元素左界，一个遍历数组
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
				left++;
            }
            else {
				continue; // 右指针遇到0就跳过
            }
        }

    }
};
#endif // DEBUG

// 方法2：把nums当成栈
//#define PRETICE
#ifdef PRETICE
class Solution {
public:
    // 注意看题是移动到数组的末尾
    void moveZeroes(vector<int>& nums) {

		int stackSize = 0; // 栈的大小
        for (int x : nums) {
			if (x) nums[stackSize++] = x; // 非0元素入栈（注意stackSize要增加）
        }
		fill(nums.begin() + stackSize, nums.end(), 0); // 填充剩余元素为0
    }
};
#endif // PRETICE
