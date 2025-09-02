#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <string>
#include <functional>
using namespace std;


#define DEBUG1
#ifdef DEBUG1

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // ���Ȳ����϶�false
        if (nums.size() < 2) return false;
        // ������ϣ��key������������219���ã�����˳���
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) return true;
            else map[nums[i]] = i;
        }
        return false;
    }
};



#endif // DEBUG1