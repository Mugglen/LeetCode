#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {
public:
    // 注意是非降序数组，而且数组有序，所以相同的数字是连续的
    // 时间复杂度要求O(logn)
    int GetNumberOfK(vector<int>& nums, int k) {
        // 先来一种STL里的写法
        auto pos = equal_range(nums.begin(), nums.end(), k);
		return pos.second - pos.first; // 返回的是迭代器，所以要相减
    }
};


#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// 正经二分法
class Solution {
public:
    // 注意是非降序数组，而且数组有序，所以相同的数字是连续的
    // 时间复杂度要求O(logn)
    int GetNumberOfK(vector<int>& nums, int k) {
        // 异常
        if (nums.empty()) return 0;
		// 二分法
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
			int mid = left + (right - left) / 2; // 防止溢出
            if (nums[mid] > k) right = mid - 1; // 大了
            else if (nums[mid] < k) left = mid + 1; // 小了
            else { // 落到k的区间里了，从中间往两边延伸
                int count = 1;
                // 向左遍历
                int index = mid - 1;
                while (index >= 0 && nums[index] == k) { // 加上index >= 0 防止越界
                    count++;
                    index--;
                }
                // 向右遍历
                index = mid + 1; // 注意Index不要重复定义
                while (index <= nums.size() - 1 && nums[index] == k) {
                    count++;
                    index++;
                }
                return count;
            }
        }
        return 0; // 没找到
    }
};


#endif // DEBUG2