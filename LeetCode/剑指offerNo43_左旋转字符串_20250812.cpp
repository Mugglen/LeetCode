#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1
// ����һ��ֱ�Ӱ��ַ���ƴ�ӵ����棬Ȼ��ȡ�Ӵ�
class Solution {
public:

    string LeftRotateString(string str, int n) {
        int len = str.size();
		if (len == 0) return str; // �����������
		if (n >= len) n = n % len; // ���� n �����ַ������ȵ����
		str += str; // ���ַ���ƴ�ӵ�����
		return str.substr(n, len); // ���ش� n ��ʼ�ĳ���Ϊ len ���Ӵ�
    }
};

#endif // DEBUG1




//#define DEBUG2
#ifdef DEBUG2
// ���������ַ������巴ת���ٷ�ת������
class Solution {
public:

	string LeftRotateString(string str, int n) {
		int len = str.size();
		if (len == 0) return str; // �����������
		if (n >= len) n = n % len; // ���� n �����ַ������ȵ����
		// ��ת�����ַ���
		reverse(str.begin(), str.end());
		// �ֱ�תǰ�벿�ֺͺ�벿��
		reverse(str.begin(), str.begin() + len - n); // ��תǰ�벿��
		reverse(str.begin() + len - n, str.end()); // ��ת��벿��
		return str; // �������ս��
	}
};

#endif // DEBUG2