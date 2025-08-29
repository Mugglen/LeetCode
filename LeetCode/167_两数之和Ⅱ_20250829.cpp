#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


#define DEBUG1
#ifdef DEBUG1

// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    // 注意题目说了是非递增数组，其实就是和为s的两个数字这题（剑指offer42）
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 左右指针
        int left = 0, right = numbers.size() - 1;
        // 移动窗口两个端点
        while (true) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return { left + 1, right + 1 }; // 题目要求加1
            else sum > target ? right-- : left++;
        }
    }
};


#endif // DEBUG1



