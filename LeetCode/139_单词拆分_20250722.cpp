#include <unordered_set>
#include <vector>
#include <string>
#include <functional>
using namespace std;
// https://leetcode.cn/problems/word-break/solutions/2968135/jiao-ni-yi-bu-bu-si-kao-dpcong-ji-yi-hua-chrs/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 查找 wordDict 中最大的字符串长度
		int max_len = ranges::max(wordDict, {}, &string::length).length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());

		int n = s.length();
        vector<int> memo(n + 1, - 1); // -1 表示没有计算过
        function<bool(int)> dfs = [&](int i) -> bool {
            // 边界处理
            if (i == 0) return true; // 到达字符串末尾，说明可以拆分成功
			
            int& res = memo[i]; // 注意这里使用引用，直接修改 memo[i] 的值
			if (res != -1) return res; // 如果已经计算过，直接返回结果
            
            // 没算过的话（注意substr第一个参数是起始位置，第二个参数是长度）
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (words.count(s.substr(j, i - j)) && dfs(j)) {
                    return res = true;
                }
            }
			return res = false; // 如果没有找到合适的拆分，返回 false

            };
        return dfs(n);
    }
};
#endif // DEBUG1



//#define PRETICE
#ifdef PRETICE
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
		// 查找 wordDict 中最大的字符串长度
		int max_len = ranges::max(wordDict, {}, &string::length).length();
		unordered_set<string> words(wordDict.begin(), wordDict.end()); // 用来快速查找字符串

        int n = s.length(); // 动规入口
		vector<int> memo(n + 1, -1); // -1 表示没有计算过

		// 表示从前i个字符能否拆分成功
        function<bool(int)> dfs = [&](int i)-> bool{
            // 边界处理
			if (i == 0) return true; // 到达字符串末尾，说明可以拆分成功
            // 检查memo
			int& res = memo[i]; // 注意这里使用引用，直接修改 memo[i] 的值
            if (res != -1)return res; // 算过了

            //没算过的话(对于当前位置i，只需检查从i - max_len 到 i - 1的子串，即长度在max_len内)
            // 同时注意当前检查的是s.substr(j, i - j)
			// 所以for 循环里 max(i - max_len, 0) 的意思是当前检查起点i如果大于max_len，就检查i - max_len 到 i - 1的子串，如果小于max_len，就检查从0到i - 1的子串
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (words.count(s.substr(j, i - j)) && dfs(j)) {
                    return res = true;
                }
            }
			return res = false; // 如果没有找到合适的拆分，返回 false
            };
        return dfs(n);
    }
};
#endif // PRETICE

// 换成递推
//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // 查找 wordDict 中最大的字符串长度
        int max_len = ranges::max(wordDict, {}, &string::length).length();
        unordered_set<string> words(wordDict.begin(), wordDict.end()); // 用来快速查找字符串

        int n = s.length(); // 动规入口
        vector<int> dp(n + 1); 

        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
					dp[i] = true; // 如果从j到i的子串在字典中，并且dp[j]为true，说明可以拆分成功
					break; // 找到一个可以拆分成功的子串，直接跳出循环
                }
            }
        }
		return dp[n]; // 返回是否可以拆分成功
    }
};
#endif // DEBUG2