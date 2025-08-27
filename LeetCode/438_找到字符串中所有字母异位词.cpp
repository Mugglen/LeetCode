#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {

public:

	vector<int> myFindAnagrams(string s, string p) {
		
		// �����������
		vector<int> ans = {};

		// �쳣ֵ����
		if (s.size() < p.size()) return ans;

		// ʹ�ù�ϣ��洢ÿ����ĸ���ֵĴ���
		unordered_map<char, int> cacheMap;

		// ��ʼ����������ָ��
		int left = 0;
		int right = 0;

		// ��ʼ����������
		for (int i = 0; i < p.size(); i++) {
			cacheMap[s[right]]++;
			right++;
		}
		
		// �������ж�(Ҫ����right == p.size() - 1)
		while (right != s.size()) {
			for (char c : p) {
				if (cacheMap[c] == 1) continue; // ��������������������p�е��ַ���һ��ֻ����һ�Σ�
				else {
					// ��������
					cacheMap[s[left]]--;
					left++;
					right++;
					cacheMap[s[right]]++;
					break;
				}
			}
			// ������ʼ���
			ans.push_back(left);

			// ��������
			cacheMap[s[left]]--;
			left++;
			right++;
			cacheMap[s[right]]++;
		
		}

		return ans;
	
	}

	// GPT�޸ĵ�
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		int n = s.size(), m = p.size();

		// �쳣ֵ����
		if (n < m) return ans; // ��� s ����С�� p ���ȣ�ֱ�ӷ��ؿս��

		// ע�������ű�p�е��ַ���һ��ֻ����һ��
		unordered_map<char, int> cacheMap;
		unordered_map<char, int> pMap;

		// ��ʼ�� p ���ַ�Ƶ��
		for (char c : p) {
			pMap[c]++;
		}

		int left = 0, right = 0;
		while (right < n) {
			// �������ڣ������ұ߽��ַ��ļ���
			cacheMap[s[right]]++;

			// �жϵ�ǰ�����Ƿ���Ч
			if (right - left + 1 == m) { // ���ڴ�С�ﵽ p �Ĵ�С
				// ��鵱ǰ�����Ƿ��� p ����ĸ��ɵ�һ������
				// �����������������߼��Ƚϣ�ԭ����ֱ���ù�ϣ�����ȣ���������������
				if (cacheMap == pMap) {
					ans.push_back(left);
				}

				// �ƶ���߽磬��С����
				cacheMap[s[left]]--;
				// �������߼�����Ȼ����ֵΪ0�ļ����ڹ�ϣ��Ƚϵ�ʱ��ͻ��ж�Ϊ����ȣ�
				if (cacheMap[s[left]] == 0) {
					cacheMap.erase(s[left]); // ɾ��Ƶ��Ϊ 0 ���ַ������ֹ�ϣ�����
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
