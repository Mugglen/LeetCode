#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

// �����㷨��û�д����������������������Ч
// ʱ�临�Ӷ� O(3^m * 4^n)
// �ռ临�Ӷ� O(m + n)

class Solution {

public:

	// debug�������current״̬
	void debug(const vector<string>& combinations, const string& combination) {
		cout << "Current combination: " << combination << endl;
		cout << "Combinations so far: ";
		for (const string& comb : combinations) {
			cout << comb << " ";
		}
		cout << endl;
	}

	void backtrack(vector<string>& combinations, //���ݽ��
		const unordered_map<char, string>& phoneMap, // ������Ҫ�ļ���ӳ��
		const string& digits,	// ��Ҫ���ݵļ���
		int index,	// ��ǰ�Ļ���λ�ã����ڴ���ڼ������֣�
		string& combination) { //���α����Ľ���м������ÿ��ı������push��combination��
		//������������������ʱpush_back��combinations

// ������ֹ���������汣�浥�λ��ݽ��
		if (index == digits.length()) {
			combinations.push_back(combination);
			debug(combinations, combination);  // ����debug�����ǰ״̬
		}
		else {
			char digit = digits[index]; // ԭ�������������ַ���ȡ���ַ�
			const string& letters = phoneMap.at(digit);
			for (const char& letter : letters) {
				// ÿ�������ʱ�����ĸ�������combination�������������ݵ�ʱ��Ͱ��������Ľ��������
				combination.push_back(letter); // һ�α�����һ����ĸ
				backtrack(combinations, phoneMap, digits, index + 1, combination); // ע��indexҪ��1
				combination.pop_back();  // ����ʱ�Ƴ����һ����ĸ
				debug(combinations, combination);  // ����debug�����ǰ״̬
			}
		}
	}

	vector<string> letterCombinations(string digits) {
		// ���������Ͻ��
		vector<string> combinations;

		// �쳣���봦��(ע����ʵ�����еô���һ���쳣����1��*��#)
		if (digits.empty()) {
			return combinations;
		}

		// ���Ϲ�ϣ��
		unordered_map<char, string> phoneMap{
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};

		// ���ڴ洢��ǰ��ϵ���ʱ����
		string combination;

		// ��ʼ����
		backtrack(combinations, phoneMap, digits, 0, combination);

		return combinations;
	}
};

//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;
	string digits;
	getline(cin, digits);
	vector<string> result = solution.letterCombinations(digits);

	// ������յ���Ͻ��
	cout << "Final combinations: ";
	for (const string& comb : result) {
		cout << comb << " ";
	}
	cout << endl;

	return 0;
}

#endif // DEBUG



