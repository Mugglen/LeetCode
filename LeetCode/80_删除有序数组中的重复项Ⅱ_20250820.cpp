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
    // https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solutions/3060042/yong-zhan-si-kao-yuan-di-shi-xian-python-zw8l/?envType=study-plan-v2&envId=top-interview-150
    // 用栈的思维来思考，感觉本质也是双指针实现
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int stack_size = 2; // 当前栈大小，前两个元素默认保留，因为数组有序，不管怎么样前两个元素一定满足
        for (int i = 2; i < n; i++) {
            // 和栈顶下方元素比较，其实就是因为数组有序，重复元素一定连续排列
            // 这个比较就是比较已存入的倒数第二个元素
            if (nums[i] != nums[stack_size - 2]) { 
                nums[stack_size] = nums[i];
                stack_size++;
            }
        }
        return min(stack_size, n);
    }
};


#endif // DEBUG1