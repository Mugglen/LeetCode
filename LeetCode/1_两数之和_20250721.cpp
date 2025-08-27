#include <vector>
#include <unordered_map>

using namespace std;
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		// 需要一个哈希表每次存储当前元素和它的索引
        unordered_map<int, int> map;
        // 答案唯一
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end()) {
                return { map[target - nums[i]], i };
            }
            else {
				map[nums[i]] = i;
            }
        }
		return {};
    }
};
#endif // DEBUG
