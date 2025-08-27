#include <vector>
#include <string> 
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;



class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> mp;
		for (string& str:strs) { //C++中的范围for循环， (元素类型& 元素变量 : 容器)
			string key = str;
			sort(key.begin(), key.end());
			mp[key].emplace_back(str);
		
		}
		vector<vector<string>> ans;

		for (auto it = mp.begin(); it != mp.end(); ++it) {
			ans.emplace_back(it->second);
		}

		return ans;
	}

};


//#define DEBUG
#ifdef DEBUG

int main() {

	Solution solution;

	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<vector<string>> strsAnagrams = solution.groupAnagrams(strs);

	// 打印结果
	for (const auto& group : strsAnagrams) {
		for (const string& str : group) {
			cout << str << " ";
		}
		cout << endl;
	}

	return 0;
}


#endif // DEBUG

