#include <vector>
#include <algorithm>
#include <iostream>

// 双指针法
// 对left和right的处理有点像2分法，对排序后的数组的三数和如果>0或者<0就对left和right做相应的处理
// 接下来如何移动left 和right呢， 如果nums[i] + nums[left] + nums[right] > 0 
// 就说明 此时三数之和大了，因为数组是排序后了，所以right下标就应该向左移动，这样才能让三数之和小一些。



class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            // 错误去重a方法，将会漏掉-1,-1,2 这种情况
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */  
            // 正确去重a方法(要和后一个元素比来去重)
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // 找到答案时，双指针同时收缩(检查中间剩下的结果里还有没有别的答案)
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {

    Solution solution;
    std::vector<int> nums = { -1,0,1,2,-1,-4 };
    std::vector<std::vector<int>> result = solution.threeSum(nums);
    for (std::vector<int> vector : result) {
        std::cout << "(";
        for (int num : vector) {
            std::cout << num << ",";
        }
        std::cout << ")" << std::endl;
    
    }
}


#endif // DEBUG
