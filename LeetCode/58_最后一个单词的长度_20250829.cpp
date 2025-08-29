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

// 倒序寻找最后一个单词的最后一位和前一位空格
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;
        int left, right = s.size() - 1;
        while (s[right] == ' ') { right--; }
        left = right;
        // 注意 && 的短路特性，判断是有优先级的
        // 这里如果s[left] != ' '在前面，left < 0时仍会越界访问
        //while (s[left] != ' ' && left >= 0) { 
        while (left >= 0 && s[left] != ' ') {
            left--; 
        }
        return right - left;

    }
};

// 库函数写法
// https://leetcode.cn/problems/length-of-last-word/solutions/2787453/liang-chong-xie-fa-shou-xie-xun-huan-ku-nmzli/?envType=study-plan-v2&envId=top-interview-150
class Solution_1 {
public:
    int lengthOfLastWord(string s) {
        int i = s.find_last_not_of(' ');
        int j = s.find_last_of(' ', i);
        return i - j;
    }
};



#endif // DEBUG1



