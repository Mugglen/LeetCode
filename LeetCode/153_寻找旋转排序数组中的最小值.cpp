#include <iostream>
#include <vector>
using namespace std;

// 是33题的简化版,33题思路中一开始二分法找到了左侧有序数组的最后一个,在旋转数组中,最小值永远是左侧有序数组的最后一个的下一个,
// 也可以说是右侧有序数组的第一个,如果是{1,2,3}的正序数组就需要取模

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2 + 1;
            // mid 在左有序数组中
            if (nums[mid] >= nums[0]) { left = mid; }
            else { right = mid - 1; }
        }
        // 注意题目要求的是值，取模来循环取索引，防止类似{1，2，3}的正序数组
        int result = nums[(right + 1) % nums.size()];
        return result;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    Solution solution;
    int result = solution.findMin(nums);
    cout << "算法输出的结果为：" << result << endl;
}

#endif // DEBUG
