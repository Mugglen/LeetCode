#include <stack>
#include <string>
#include <iostream>  // 需要引入iostream来使用cout

using namespace std;

// https://leetcode.cn/problems/decode-string/solutions/6274/ti-jie-czhan-by-youlookdeliciousc

class Solution {
public:
	// 构造类似分配律的计算器，看到括号匹配可以考虑使用栈
	string decodeString(string s) {

		// 创建辅助栈和中间变量
		string res = ""; // 结果变量
		stack<int> nums;
		stack<string> strs;

		int num = 0;

		for (int i = 0; i < s.size(); ++i) {

			// 字符串转换数字，注意多位数写法
			//	如果我们有字符串 "123"，那么：
			//	当处理到第一个字符 '1' 时，num = 0 * 10 + 1 = 1
			//	当处理到第二个字符 '2' 时，num = 1 * 10 + 2 = 12
			//	当处理到第三个字符 '3' 时，num = 12 * 10 + 3 = 123
			if (s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
				cout << "数字字符，更新 num: " << num << endl;  // 打印更新的 num
			}

			// 处理字母
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				res = res + s[i];
				cout << "字母字符，更新 res: " << res << endl;  // 打印更新的 res
			}

			// 将‘[’前的数字压入nums栈内，字符串压入strs栈内
			else if (s[i] == '[') {
				nums.push(num);
				cout << "遇到 '['，将 num 压入 nums 栈，nums.top(): " << nums.top() << endl;  // 打印压入栈后的 num
				num = 0;
				strs.push(res);
				cout << "遇到 '['，将 res 压入 strs 栈，strs.top(): " << strs.top() << endl;  // 打印压入栈后的 res
				res = ""; // （注意“”才是空字符串的字面量，不要写成''了）
			}

			// 遇到']'时，操作与之相配的‘[’之间的字符，使用分配率
			else {
				int times = nums.top();
				nums.pop();
				cout << "遇到 ']'，取出 nums 栈中的数字: " << times << endl;  // 打印取出的 times
				for (int j = 0; j < times; ++j) {
					// 会和当前[]外的字母在栈顶中合并
					strs.top() += res;
					cout << "将 res 拼接到 strs.top()，更新 strs.top(): " << strs.top() << endl;  // 打印拼接后的 strs.top()
				}
				res = strs.top();
				cout << "将 strs.top() 赋值给 res，更新 res: " << res << endl;  // 打印更新的 res
				strs.pop();
			}

		}
		cout << "最终解码结果: " << res << endl;  // 打印最终解码结果
		return res;
	}
};


//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;

	//string s = "3[a2[bc]]";  // 示例输入
	string s = "3[a]2[bc]";
	cout << "输入字符串: " << s << endl;
	string result = solution.decodeString(s);

	cout << "解码结果: " << result << endl;  // 打印最终的解码结果

	return 0;
}

#endif // DEBUG


