#include<iostream>
#include<vector>
using namespace std;

// 题目强调了是有序数组，所以可以使用二分查找
// 搜索区间为[left, right]，左闭右闭
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
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
        return -1;
    }
};


//#define DEBUG

#ifdef DEBUG
int main() {
    vector<int> nums = { -1,0,3,5,9,12 };
    int target = 19;
    Solution solution;
    int result = solution.search(nums, target);
    if (result != -1) {
        cout << "目标值" << target << "的索引是：" << result << endl;
    }
    else {
        cout << "目标值" << target << "未找到" << endl;
    }

    return 0;
}
#endif // DEBUG

