#include <vector>
#include <unordered_map>

using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // ��һ����ͳ��ÿ��Ԫ�صĳ��ִ���
        unordered_map<int, int> cnt;
        int max_cnt = 0;
        for (int x : nums) {
            cnt[x]++;
            // �������Ƶ��
            max_cnt = max(max_cnt, cnt[x]);
        }

        // �ڶ������ѳ��ִ�����ͬ��Ԫ�أ��ŵ�ͬһ��Ͱ��
        vector<vector<int>> buckets(max_cnt + 1);
        for (auto& [x, c] : cnt) {
            buckets[c].push_back(x);
        }

        // ���������������buckets���ѳ��ִ���ǰk���Ԫ�ؼ����
        vector<int> ans;
        for (int i = max_cnt; i >= 0 && ans.size() < k; i--) {
            ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;

    }
};
#endif // DEBUG
