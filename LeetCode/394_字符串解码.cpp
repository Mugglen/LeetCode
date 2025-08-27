#include <stack>
#include <string>
#include <iostream>  // ��Ҫ����iostream��ʹ��cout

using namespace std;

// https://leetcode.cn/problems/decode-string/solutions/6274/ti-jie-czhan-by-youlookdeliciousc

class Solution {
public:
	// �������Ʒ����ɵļ���������������ƥ����Կ���ʹ��ջ
	string decodeString(string s) {

		// ��������ջ���м����
		string res = ""; // �������
		stack<int> nums;
		stack<string> strs;

		int num = 0;

		for (int i = 0; i < s.size(); ++i) {

			// �ַ���ת�����֣�ע���λ��д��
			//	����������ַ��� "123"����ô��
			//	��������һ���ַ� '1' ʱ��num = 0 * 10 + 1 = 1
			//	�������ڶ����ַ� '2' ʱ��num = 1 * 10 + 2 = 12
			//	�������������ַ� '3' ʱ��num = 12 * 10 + 3 = 123
			if (s[i] >= '0' && s[i] <= '9') {
				num = num * 10 + s[i] - '0';
				cout << "�����ַ������� num: " << num << endl;  // ��ӡ���µ� num
			}

			// ������ĸ
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
				res = res + s[i];
				cout << "��ĸ�ַ������� res: " << res << endl;  // ��ӡ���µ� res
			}

			// ����[��ǰ������ѹ��numsջ�ڣ��ַ���ѹ��strsջ��
			else if (s[i] == '[') {
				nums.push(num);
				cout << "���� '['���� num ѹ�� nums ջ��nums.top(): " << nums.top() << endl;  // ��ӡѹ��ջ��� num
				num = 0;
				strs.push(res);
				cout << "���� '['���� res ѹ�� strs ջ��strs.top(): " << strs.top() << endl;  // ��ӡѹ��ջ��� res
				res = ""; // ��ע�⡰�����ǿ��ַ���������������Ҫд��''�ˣ�
			}

			// ����']'ʱ��������֮����ġ�[��֮����ַ���ʹ�÷�����
			else {
				int times = nums.top();
				nums.pop();
				cout << "���� ']'��ȡ�� nums ջ�е�����: " << times << endl;  // ��ӡȡ���� times
				for (int j = 0; j < times; ++j) {
					// ��͵�ǰ[]�����ĸ��ջ���кϲ�
					strs.top() += res;
					cout << "�� res ƴ�ӵ� strs.top()������ strs.top(): " << strs.top() << endl;  // ��ӡƴ�Ӻ�� strs.top()
				}
				res = strs.top();
				cout << "�� strs.top() ��ֵ�� res������ res: " << res << endl;  // ��ӡ���µ� res
				strs.pop();
			}

		}
		cout << "���ս�����: " << res << endl;  // ��ӡ���ս�����
		return res;
	}
};


//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;

	//string s = "3[a2[bc]]";  // ʾ������
	string s = "3[a]2[bc]";
	cout << "�����ַ���: " << s << endl;
	string result = solution.decodeString(s);

	cout << "������: " << result << endl;  // ��ӡ���յĽ�����

	return 0;
}

#endif // DEBUG


