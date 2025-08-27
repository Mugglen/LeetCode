#include <vector>
#include <algorithm>
#include <iostream>  // ���� std::cout ��ӡ

class Solution {
public:
    // ��ӡ�����ָ��״̬�ķ���
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
            // ��ÿ��ѭ��ǰ��ӡ������Ϣ
            debug(nums, left, right, "Before swap");

			// ���Ĳ�������������Ԫ�ص����
            if (nums[right]) {
                std::swap(nums[left], nums[right]);
                left++;
            }
            right++;// �ǵ�ÿ��ѭ����ָ�붼Ҫ��һ��

            // ��ÿ��ѭ�����ӡ������Ϣ
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