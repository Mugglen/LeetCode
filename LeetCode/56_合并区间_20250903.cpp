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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans = {};
        if (intervals.size() == 0) return ans;
        // ×ó¶ËµãÅÅÐò
        ranges::sort(intervals);
        for (auto p : intervals) {
            if (!ans.empty() && p[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], p[1]);
            }
            else {
                ans.emplace_back(p); 
            }
        }
        return ans;

    }
};


#endif // DEBUG1