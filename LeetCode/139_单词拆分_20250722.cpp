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
        // ���� wordDict �������ַ�������
		int max_len = ranges::max(wordDict, {}, &string::length).length();
        unordered_set<string> words(wordDict.begin(), wordDict.end());

		int n = s.length();
        vector<int> memo(n + 1, - 1); // -1 ��ʾû�м����
        function<bool(int)> dfs = [&](int i) -> bool {
            // �߽紦��
            if (i == 0) return true; // �����ַ���ĩβ��˵�����Բ�ֳɹ�
			
            int& res = memo[i]; // ע������ʹ�����ã�ֱ���޸� memo[i] ��ֵ
			if (res != -1) return res; // ����Ѿ��������ֱ�ӷ��ؽ��
            
            // û����Ļ���ע��substr��һ����������ʼλ�ã��ڶ��������ǳ��ȣ�
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (words.count(s.substr(j, i - j)) && dfs(j)) {
                    return res = true;
                }
            }
			return res = false; // ���û���ҵ����ʵĲ�֣����� false

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
        
		// ���� wordDict �������ַ�������
		int max_len = ranges::max(wordDict, {}, &string::length).length();
		unordered_set<string> words(wordDict.begin(), wordDict.end()); // �������ٲ����ַ���

        int n = s.length(); // �������
		vector<int> memo(n + 1, -1); // -1 ��ʾû�м����

		// ��ʾ��ǰi���ַ��ܷ��ֳɹ�
        function<bool(int)> dfs = [&](int i)-> bool{
            // �߽紦��
			if (i == 0) return true; // �����ַ���ĩβ��˵�����Բ�ֳɹ�
            // ���memo
			int& res = memo[i]; // ע������ʹ�����ã�ֱ���޸� memo[i] ��ֵ
            if (res != -1)return res; // �����

            //û����Ļ�(���ڵ�ǰλ��i��ֻ�����i - max_len �� i - 1���Ӵ�����������max_len��)
            // ͬʱע�⵱ǰ������s.substr(j, i - j)
			// ����for ѭ���� max(i - max_len, 0) ����˼�ǵ�ǰ������i�������max_len���ͼ��i - max_len �� i - 1���Ӵ������С��max_len���ͼ���0��i - 1���Ӵ�
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (words.count(s.substr(j, i - j)) && dfs(j)) {
                    return res = true;
                }
            }
			return res = false; // ���û���ҵ����ʵĲ�֣����� false
            };
        return dfs(n);
    }
};
#endif // PRETICE

// ���ɵ���
//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        // ���� wordDict �������ַ�������
        int max_len = ranges::max(wordDict, {}, &string::length).length();
        unordered_set<string> words(wordDict.begin(), wordDict.end()); // �������ٲ����ַ���

        int n = s.length(); // �������
        vector<int> dp(n + 1); 

        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (dp[j] && words.count(s.substr(j, i - j))) {
					dp[i] = true; // �����j��i���Ӵ����ֵ��У�����dp[j]Ϊtrue��˵�����Բ�ֳɹ�
					break; // �ҵ�һ�����Բ�ֳɹ����Ӵ���ֱ������ѭ��
                }
            }
        }
		return dp[n]; // �����Ƿ���Բ�ֳɹ�
    }
};
#endif // DEBUG2