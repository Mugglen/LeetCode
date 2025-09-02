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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // 长度不够肯定false
        if (nums.size() < 2) return false;
        // 创建哈希表，key存索引，在题219中用，这里顺便存
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
                return true;
            }
            // 如果没有或者有重复但是间距过大，更新哈希表
            else map[nums[i]] = i;
        }
        return false;
    }
};


#endif // DEBUG1