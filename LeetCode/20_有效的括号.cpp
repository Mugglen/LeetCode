// 题解地址 https://www.programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html#%E6%80%9D%E8%B7%AF
#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
	bool isValid(std::string s) {
		if (s.size() % 2 != 0) { return false; } // 如果s的长度为奇数一定不对
		std::stack<char> st;
		for (int i = 0; i < s.size(); i++) { // 需要使用索引的时候用i 
			if (s[i] == '(') { st.push(')'); }
			else if (s[i] == '{') { st.push('}'); }
			else if (s[i] == '[') { st.push(']'); }

			else if (st.empty() || st.top() != s[i]) { return false; }
			else st.pop();
		
		
		}
		return st.empty();
	
	
	}



};

//#define DEBUG
#ifdef DEBUG

int main() {

	Solution solution;
	//std::string bracket = "()[]{}"; // 注意双引号才是字符串，单‘’是字符7
	std::string bracket = "()[]{}}"; // 注意双引号才是字符串，单‘’是字符7



	if (solution.isValid(bracket)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;// 直接输出solution.isValid(bracket)是1
	}
	
	return 0;
}

#endif // DEBUG