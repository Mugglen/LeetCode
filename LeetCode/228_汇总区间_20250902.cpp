#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans = {};
        if (nums.empty()) return ans;
        // 双指针
        int left = 0, right = 0;
        // 判断连续区间，用值的差和两个索引之差来比较
        while (true) {
            if (right == nums.size()) break;
            // right步进到连续区间右端点
            // 用 long long 避免溢出
            while (right < nums.size() - 1 &&
                (long long)nums[right + 1] - (long long)nums[left] == (right + 1 - left)) {
                right++;
            }
            string tmp;
            if (left != right) {
                tmp = to_string(nums[left]) + "->" + to_string(nums[right]);
            }
            else {
                tmp = to_string(nums[left]);
            }
            
            ans.push_back(tmp);
            
            // 步进到下一个连续开始位置
            right++;
            left = right;
        }
        return ans;
    }
};


#endif // DEBUG1