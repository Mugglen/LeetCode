#include <vector>
#include <unordered_map>

using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // 第一步：统计每个元素的出现次数
        unordered_map<int, int> cnt;
        int max_cnt = 0;
        for (int x : nums) {
            cnt[x]++;
            // 保存最大频率
            max_cnt = max(max_cnt, cnt[x]);
        }

        // 第二步：把出现次数相同的元素，放到同一个桶里
        vector<vector<int>> buckets(max_cnt + 1);
        for (auto& [x, c] : cnt) {
            buckets[c].push_back(x);
        }

        // 第三步：倒序遍历buckets，把出现次数前k大的元素加入答案
        vector<int> ans;
        for (int i = max_cnt; i >= 0 && ans.size() < k; i--) {
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;

    }
};
#endif // DEBUG
