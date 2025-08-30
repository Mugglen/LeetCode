#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // 也是一一对应关系的题
        // 这里的s题目里说了不用考虑前导和尾随空格,而且每个单词由单个空格分割
        // 两个哈希表存映射
        unordered_map<char, string> mapC2S;
        unordered_map<string, char> mapS2C;
        // 双指针找string
        int left = 0, right = 0;
        for (char c : pattern) {
            // 如果pattern长度大于单词数量
            if (right >= s.size()) return false;
            // 提取当前单词
            while (right < s.size() && s[right] != ' ') right++;
            string sub = s.substr(left, right - left); //注意！！！substr第二个参数是长度
            // 双向判断
            if (mapC2S.find(c) != mapC2S.end()) {
                if (mapC2S[c] != sub) return false;
            }
            else {
                mapC2S[c] = sub;
            }
            if (mapS2C.find(sub) != mapS2C.end()) {
                if (mapS2C[sub] != c) return false;
            }
            else {
                mapS2C[sub] = c;
            }
            // 判断通过，移动双指针到下一个单词开头，题目说了只有一个空格
            left = ++right;
        }
        // 如果pattern 小于单词数量
        if (right < s.size()) return false;
        // 整好匹配成功
        return true;
    }
};

#endif // DEBUG1



