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
        // 使用双指针从后往前匹配
        string ans;
        int left = s.size() - 1;
        int right = 0;
        // 循环处理
        while (true) {
            // 先跳过空
            while (left >= 0 && s[left] == ' ') left--;
            // 如果是前导空，跳出循环
            if (left < 0) break;
            right = left;
            while (left >= 0 && s[left] != ' ') left--;
            ans += s.substr(left + 1, right - left) + ' ';
            // 无前导空，匹配结束
            if (left < 0) break;
        }
        // 此时ans还带了一个尾部空
        return ans.substr(0, ans.size() - 1);


    }
};



#endif // DEBUG1