#include <iostream>
#include <vector>
using namespace std;

// 暴力解法
// 时间复杂度：O(n)
// 空间复杂度：O(1)

class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            // 从小到大开始找
            // 分别处理如下三种情况
            // 目标值在数组所有元素之前
            // 目标值等于数组中某一个元素
            // 目标值插入数组中的位置
            if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                return i;
            }
        }
        // 目标值在数组所有元素之后的情况
        return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
    }
};

// 暴力解法
// 时间复杂度：O(n)
// 空间复杂度：O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
		return right + 1;// 与二分查找主要的区别点，二分查找找不到返回-1,注意是放在while循环外面的,放在里面就直接退出了
    }
};

//#define DEBUG
#ifdef DEBUG
int main() {
    vector<int> nums = { 1,3,5,6 };
    int target = 5;
    Solution solution;
    int result = solution.searchInsert(nums, target);
    cout << "目标值" << target << "的插入位置为" << result << endl;
    return 0;
};
#endif // DEBUG

