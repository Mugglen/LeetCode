// ����ַ https://www.programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html#%E6%80%9D%E8%B7%AF
#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
	bool isValid(std::string s) {
		if (s.size() % 2 != 0) { return false; } // ���s�ĳ���Ϊ����һ������
		std::stack<char> st;
		for (int i = 0; i < s.size(); i++) { // ��Ҫʹ��������ʱ����i 
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
	//std::string bracket = "()[]{}"; // ע��˫���Ų����ַ��������������ַ�7
	std::string bracket = "()[]{}}"; // ע��˫���Ų����ַ��������������ַ�7



	if (solution.isValid(bracket)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;// ֱ�����solution.isValid(bracket)��1
	}
	
	return 0;
}

#endif // DEBUG