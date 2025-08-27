#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

// 回溯算法，没有错误结果，遍历结果都可以生效
// 时间复杂度 O(3^m * 4^n)
// 空间复杂度 O(m + n)

class Solution {

public:

	// debug方法输出current状态
	void debug(const vector<string>& combinations, const string& combination) {
		cout << "Current combination: " << combination << endl;
		cout << "Combinations so far: ";
		for (const string& comb : combinations) {
			cout << comb << " ";
		}
		cout << endl;
	}

	void backtrack(vector<string>& combinations, //回溯结果
		const unordered_map<char, string>& phoneMap, // 回溯需要的集合映射
		const string& digits,	// 需要回溯的集合
		int index,	// 当前的回溯位置（正在处理第几个数字）
		string& combination) { //单次遍历的结果中间变量，每层的遍历结果push进combination里
		//，最后遍历结束保存结果时push_back进combinations

// 回溯终止条件，里面保存单次回溯结果
		if (index == digits.length()) {
			combinations.push_back(combination);
			debug(combinations, combination);  // 调用debug输出当前状态
		}
		else {
			char digit = digits[index]; // 原来可以这样从字符串取出字符
			const string& letters = phoneMap.at(digit);
			for (const char& letter : letters) {
				// 每层遍历的时候把字母结果存入combination，遍历结束回溯的时候就把这层遍历的结果弹出来
				combination.push_back(letter); // 一次遍历存一个字母
				backtrack(combinations, phoneMap, digits, index + 1, combination); // 注意index要加1
				combination.pop_back();  // 回溯时移除最后一个字母
				debug(combinations, combination);  // 调用debug输出当前状态
			}
		}
	}

	vector<string> letterCombinations(string digits) {
		// 存放最后的组合结果
		vector<string> combinations;

		// 异常输入处理(注意真实面试中得处理一下异常输入1，*，#)
		if (digits.empty()) {
			return combinations;
		}

		// 集合哈希表
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

		// 用于存储当前组合的临时变量
		string combination;

		// 开始回溯
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

	// 输出最终的组合结果
	cout << "Final combinations: ";
	for (const string& comb : result) {
		cout << comb << " ";
	}
	cout << endl;

	return 0;
}

#endif // DEBUG



