#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/group-anagrams/solutions/2718519/ha-xi-biao-fen-zu-jian-ji-xie-fa-pythonj-1ukv/?envType=study-plan-v2&envId=top-100-liked
// 时空复杂度分析见链接
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// 需要一个哈希表，key 是排序后的字符串，value 是原字符串的集合
        unordered_map<string, vector<string>> map;
        for (const string& str : strs) {
            // 需要一个拷贝
			string key = str;
			// 先排序，异位词排序后是相同的
            sort(key.begin(), key.end());
			// 将原字符串添加到对应的 key 的 vector 中
			map[key].emplace_back(str);
        }

		// 准备返回结果
		vector<vector<string>> ans;
		for (auto it = map.begin(); it != map.end(); it++) {
			ans.emplace_back(it->second);
		}
		return ans;
    }
};
#endif