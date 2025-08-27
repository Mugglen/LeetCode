#ifdef DEBUG
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            // ����ʹ��������ͬ��Ԫ��
            if (it != map.end()) {
                ans.push_back(it->second);
                ans.push_back(i);
            }
            else {
                // �����ϣ��
                map[nums[i]] = i;
            }

        }
        return ans;
    }
};
#endif // DEBUG
