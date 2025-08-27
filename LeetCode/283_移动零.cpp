#include <vector>
#include <algorithm>
#include <iostream>  // 用于 std::cout 打印

class Solution {
public:
    // 打印数组和指针状态的方法
    void debug(const std::vector<int>& nums, int left, int right, const std::string& tag) {
        std::cout << tag << " - Array: ";
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << ", left = " << left << ", right = " << right << std::endl;
    }

    void moveZeroes(std::vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            // 在每次循环前打印调试信息
            debug(nums, left, right, "Before swap");

			// 核心操作，交换非零元素到左边
            if (nums[right]) {
                std::swap(nums[left], nums[right]);
                left++;
            }
            right++;// 记得每次循环右指针都要进一步

            // 在每次循环后打印调试信息
            debug(nums, left, right, "After swap");
        }
    }
};

//#define DEBUG
#ifdef DEBUG
int main() {
    std::vector<int> nums = { 0, 1, 0, 3, 12 };
    Solution solution;
    solution.moveZeroes(nums);
    return 0;
}
#endif 