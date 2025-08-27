#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;


// https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/1959540/xia-biao-zong-suan-cuo-qing-kan-zhe-by-e-iaks

class Solution {

public:
	// д��1�� ��ϣ���������飩
	// ʱ�临�Ӷ�O��n����nΪ����ĳ���
	int lengthOfLongestSubstring(string s) {
		// std::string �� .size() �� .length() ������ C++ ���ǵ�Ч�ģ�
		// û��ʵ�ʵ��������ǵ����úͷ���ֵ��һ���ģ����Ƿ����ַ������ַ��ĸ�����
		// ֻ��size��C++����������������length��C����������
		int n = s.size(), ans = 0, left = 0;
		
		// ά�����±� left���±�right���ַ�, key ���ַ���value�ǳ��ֵĴ���
		unordered_map<char, int> cnt; 

		for (int right = 0; right < n; right++) {
			
			// ȡ�������ұ߽���ַ�
			char c = s[right];
			
			// ���¹�ϣ����ͳ��
			cnt[c]++;

			// �ظ��߼���⣬�����󴰿ڣ���С��û���ظ�Ԫ��Ϊֹ
			while (cnt[c] > 1) {

				// ����С�߼����󴰿ڱ߽����ַ��ĳ��ִ�����һֱ����û���Ҵ��ڱ߽��ϵ��ַ�Ϊֹ
				cnt[s[left]]--;
				left++;
			
			}
			
			// ÿ���ƶ��Ҵ��ڻ����һ������Ҫ����Ӵ���Ҫÿ�ζ���������Ҫ����ִ�����
			// ��1�ǵ�right��left��ָ��ͬһ��Ԫ��ʱ���ִ���С����1
			ans = max(ans, right - left + 1);
		
		}
		return ans;

	}

};


//#define DEBUG
#ifdef DEBUG

int main() {

	string s = "abcabcbb";
	Solution solution;

	cout << "count:" << solution.lengthOfLongestSubstring(s) << endl;

}



#endif