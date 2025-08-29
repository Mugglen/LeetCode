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
    // ע����Ŀ˵���Ƿǵ������飬��ʵ���Ǻ�Ϊs�������������⣨��ָoffer42��
    vector<int> twoSum(vector<int>& numbers, int target) {
        // ����ָ��
        int left = 0, right = numbers.size() - 1;
        // �ƶ����������˵�
        while (true) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) return { left + 1, right + 1 }; // ��ĿҪ���1
            else sum > target ? right-- : left++;
        }
    }
};


#endif // DEBUG1



