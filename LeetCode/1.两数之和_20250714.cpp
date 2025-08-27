#ifdef DEBUG
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            // 不能使用两个相同的元素
            if (it != map.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
            }
            else {
                // 存入哈希表
                map[nums[i]] = i;
            }

        }
        return ans;
    }
};
#endif // DEBUG
