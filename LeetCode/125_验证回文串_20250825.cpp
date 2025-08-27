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
    // 双指针判断的同时处理非字母数字字符，谁遇到了就步进
    // 题目没要求返回处理后的字符串，所以判断即可，不用删除
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            // 左指针
            if (!isalnum(s[left])) left++;
            // 右指针
            else if (!isalnum(s[right])) right--;
            // 都是字母数字
            else if (tolower(s[left]) == tolower(s[right])) {
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }

    // 如果要手写字母数字判断的话
    bool isAlphanumeric(char ch) {
        return (ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z');
    }
    // 如果需要手动实现大小到小写转换
    char toLower(char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return ch + 32;  // ASCII中大写字母比小写字母小32
        }
        return ch;
    }

};


#endif // DEBUG1
