#include <vector>
#include <unordered_map>

using namespace std;
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		// ��Ҫһ����ϣ��ÿ�δ洢��ǰԪ�غ���������
        unordered_map<int, int> map;
        // ��Ψһ
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
