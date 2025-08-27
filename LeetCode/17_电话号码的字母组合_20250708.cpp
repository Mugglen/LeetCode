#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

//#define DEBUG
#ifdef DEBUG

class Solution {

public:

	void backtrack(vector<string>& combinations, //回溯结果
		const unordered_map<char, string>& phoneMap, // 回溯需要的集合映射
		const string& digits,	// 需要回溯的集合
		int index,	// 当前的回溯位置（正在处理第几个数字）
		string& combination) {//（单条路径的结果）

		// 先写边界条件
		if (index == digits.size()) {
			combinations.push_back(combination);
			/*return;*/
		}
		else {// (这时已经超出索引了，表明当前已经遍历到树的叶子下一层了)

			// 取出当前处理的位置
			char curDigit = digits[index];

			// 取出该数字的组合
			const string& letters = phoneMap.at(curDigit);

			// 遍历，同时递归
			for (const char& letter : letters) {
			
				// 加入当前树的路径
				combination.push_back(letter);

				// 错误点1！！！！！！记得增加索引（但不是在这里加）
				//index++;

				// 递归(错误点2！！！！！！应该在这里加index,在上面加会导致for循环内的index变化，backtrack传入的index就不一致了)
				backtrack(combinations, phoneMap, digits, index + 1, combination);

				// 遍历完当前路径，要弹出底下的结果
				combination.pop_back();
		
			}
		}

	}


	vector<string> letterCombinations(string digits) {
		// 存放最后的组合结果
		vector<string> combinations;

		// 异常输入处理
		if (digits.empty()) {
			return combinations;
		}

		// 集合哈希表(也可以使用数组，下标对应电话号码)
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


#endif // DEBUG
