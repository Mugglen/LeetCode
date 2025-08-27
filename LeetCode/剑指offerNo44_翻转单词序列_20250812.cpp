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
class Solution {
public:
    string ReverseSentence(string str) {
        // ��Ŀ��֤û��ֻ�����ո���ַ�����ֻ�账����ַ���
        if (str.empty()) return str;
        // �ȷ�ת
        reverse(str.begin(), str.end());
        // ʹ��˫ָ�붨λһ������
        int left = 0;
        for (int right = 0; right < str.size(); right++) {
            if (str[right] == ' ') {
				reverse(str.begin() + left, str.begin() + right);
				left = right + 1; // ������ָ�뵽��һ�����ʵ���ʼλ��
            }
        }
		// ���һ��������Ҫ��������
        reverse(str.begin() + left, str.end());
		return str;
    }
};

#endif // DEBUG1