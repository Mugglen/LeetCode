#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/group-anagrams/solutions/2718519/ha-xi-biao-fen-zu-jian-ji-xie-fa-pythonj-1ukv/?envType=study-plan-v2&envId=top-100-liked
// ʱ�ո��Ӷȷ���������
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// ��Ҫһ����ϣ��key ���������ַ�����value ��ԭ�ַ����ļ���
        unordered_map<string, vector<string>> map;
        for (const string& str : strs) {
            // ��Ҫһ������
			string key = str;
			// ��������λ�����������ͬ��
            sort(key.begin(), key.end());
			// ��ԭ�ַ�����ӵ���Ӧ�� key �� vector ��
			map[key].emplace_back(str);
        }

		// ׼�����ؽ��
		vector<vector<string>> ans;
		for (auto it = map.begin(); it != map.end(); it++) {
			ans.emplace_back(it->second);
		}
		return ans;
    }
};
#endif