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
    string reverseWords(string s) {

        if (s.size() == 0) return "";
        // ʹ��˫ָ��Ӻ���ǰƥ��
        string ans;
        int left = s.size() - 1;
        int right = 0;
        // ѭ������
        while (true) {
            // ��������
            while (left >= 0 && s[left] == ' ') left--;
            // �����ǰ���գ�����ѭ��
            if (left < 0) break;
            right = left;
            while (left >= 0 && s[left] != ' ') left--;
            ans += s.substr(left + 1, right - left) + ' ';
            // ��ǰ���գ�ƥ�����
            if (left < 0) break;
        }
        // ��ʱans������һ��β����
        return ans.substr(0, ans.size() - 1);


    }
};



#endif // DEBUG1