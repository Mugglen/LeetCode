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
    // https://leetcode.cn/problems/valid-palindrome/solutions/3053284/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-1za0/?envType=study-plan-v2&envId=top-interview-150
    // ˫ָ���жϵ�ͬʱ�������ĸ�����ַ���˭�����˾Ͳ���
    // ��ĿûҪ�󷵻ش������ַ����������жϼ��ɣ�����ɾ��
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // ��ָ��
            if (!isalnum(s[left])) left++;
            // ��ָ��
            else if (!isalnum(s[right])) right--;
            // ������ĸ����
            else if (tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }

    // ���Ҫ��д��ĸ�����жϵĻ�
    bool isAlphanumeric(char ch) {
        return (ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z');
    }
    // �����Ҫ�ֶ�ʵ�ִ�С��Сдת��
    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 32;  // ASCII�д�д��ĸ��Сд��ĸС32
        }
        return ch;
    }

};


#endif // DEBUG1
