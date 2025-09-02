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
        // ˫ָ��
        int left = 0, right = 0;
        // �ж��������䣬��ֵ�Ĳ����������֮�����Ƚ�
        while (true) {
            if (right == nums.size()) break;
            // right���������������Ҷ˵�
            // �� long long �������
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
            
            // ��������һ��������ʼλ��
            right++;
            left = right;
        }
        return ans;
    }
};


#endif // DEBUG1