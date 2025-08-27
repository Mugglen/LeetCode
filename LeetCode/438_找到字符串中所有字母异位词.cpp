#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {

public:

	vector<int> myFindAnagrams(string s, string p) {
		
		// 创建结果向量
		vector<int> ans = {};

		// 异常值处理
		if (s.size() < p.size()) return ans;

		// 使用哈希表存储每个字母出现的次数
		unordered_map<char, int> cacheMap;

		// 初始化定长窗口指针
		int left = 0;
		int right = 0;

		// 初始化定长窗口
		for (int i = 0; i < p.size(); i++) {
			cacheMap[s[right]]++;
			right++;
		}
		
		// 滑动和判断(要包含right == p.size() - 1)
		while (right != s.size()) {
			for (char c : p) {
				if (cacheMap[c] == 1) continue; // （！！！！！！！错误，p中的字符不一定只出现一次）
				else {
					// 滑动窗口
					cacheMap[s[left]]--;
					left++;
					right++;
					cacheMap[s[right]]++;
					break;
				}
			}
			// 保存起始结果
			ans.push_back(left);

			// 滑动窗口
			cacheMap[s[left]]--;
			left++;
			right++;
			cacheMap[s[right]]++;
		
		}

		return ans;
	
	}

	// GPT修改的
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int n = s.size(), m = p.size();

		// 异常值处理
		if (n < m) return ans; // 如果 s 长度小于 p 长度，直接返回空结果

		// 注意是两张表，p中的字符不一定只出现一次
		unordered_map<char, int> cacheMap;
		unordered_map<char, int> pMap;

		// 初始化 p 的字符频率
		for (char c : p) {
			pMap[c]++;
		}

		int left = 0, right = 0;
		while (right < n) {
			// 滑动窗口，增加右边界字符的计数
			cacheMap[s[right]]++;

			// 判断当前窗口是否有效
			if (right - left + 1 == m) { // 窗口大小达到 p 的大小
				// 检查当前窗口是否是 p 的字母组成的一个排列
				// （！！！！！核心逻辑比较，原来能直接用哈希表来比！！！！！！！）
				if (cacheMap == pMap) {
					ans.push_back(left);
				}

				// 移动左边界，缩小窗口
				cacheMap[s[left]]--;
				// （核心逻辑，不然会多出值为0的键，在哈希表比较的时候就会判断为不相等）
				if (cacheMap[s[left]] == 0) {
					cacheMap.erase(s[left]); // 删除频率为 0 的字符，保持哈希表清洁
				}
				left++;
			}

			right++;
		}

		return ans;
	}


};


//#define DEBUG
#ifdef DEBUG

int main() {

	string s = "cbaebabacd";
	string p = "abc";

	//string s = "abab";
	//string p = "ab";

	Solution solution;

	vector<int> ans = solution.findAnagrams(s, p);

	cout << "ans:";
	for (int i : ans) {
		cout << i << ',';
	}

	return 0;
}




#endif // DEBUG
