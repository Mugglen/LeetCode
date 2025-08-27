#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//#define DEBUG
#ifdef DEBUG

class Solution {

public:

	void backtrack(vector<string>& combinations, //���ݽ��
		const unordered_map<char, string>& phoneMap, // ������Ҫ�ļ���ӳ��
		const string& digits,	// ��Ҫ���ݵļ���
		int index,	// ��ǰ�Ļ���λ�ã����ڴ���ڼ������֣�
		string& combination) {//������·���Ľ����

		// ��д�߽�����
		if (index == digits.size()) {
			combinations.push_back(combination);
			/*return;*/
		}
		else {// (��ʱ�Ѿ����������ˣ�������ǰ�Ѿ�����������Ҷ����һ����)

			// ȡ����ǰ�����λ��
			char curDigit = digits[index];

			// ȡ�������ֵ����
			const string& letters = phoneMap.at(curDigit);

			// ������ͬʱ�ݹ�
			for (const char& letter : letters) {
			
				// ���뵱ǰ����·��
				combination.push_back(letter);

				// �����1�������������ǵ�����������������������ӣ�
				//index++;

				// �ݹ�(�����2������������Ӧ���������index,������ӻᵼ��forѭ���ڵ�index�仯��backtrack�����index�Ͳ�һ����)
				backtrack(combinations, phoneMap, digits, index + 1, combination);

				// �����굱ǰ·����Ҫ�������µĽ��
				combination.pop_back();
		
			}
		}

	}


	vector<string> letterCombinations(string digits) {
		// ���������Ͻ��
		vector<string> combinations;

		// �쳣���봦��
		if (digits.empty()) {
			return combinations;
		}

		// ���Ϲ�ϣ��(Ҳ����ʹ�����飬�±��Ӧ�绰����)
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


#endif // DEBUG
