#include <vector>
#include <unordered_set>
using namespace std;


//#define DEBUG
#ifdef DEBUG

// https://leetcode.cn/problems/intersection-of-two-arrays/solutions/3053420/yi-ci-bian-li-pythonjavacgojsrust-by-end-jstx/


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> ans;
        if (nums1.empty() || nums2.empty())return ans;

        // nums1入表,需要看值，不需要键值对，使用unorder_set
        //unordered_map<int, int> 
        unordered_set<int> set(nums1.begin(), nums1.end()); // 迭代器初始化（同时会去掉nums1里重复元素）
        // （如 [1,2,2,3,3,3]），构造 unordered_set 时会自动移除重复值，最终只包含唯一元素​（即 {1,2,3}）
        for (int x : nums2) {
            if (set.erase(x)) { // 注意！！！查找的同时删除，因为题目说相同元素只能出现一次
                ans.push_back(x);
            
            }
        }
        return ans;

    }
};

#endif // DEBUG
