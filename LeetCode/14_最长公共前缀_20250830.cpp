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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string s0 = strs[0];
        for (int j = 0; j < s0.size(); j++) { // 枚举每个字母
            for (string& s : strs) {          // 对每个单词比对
                if (j == s.size() || s[j] != s0[j]) {
                    return s0.substr(0, j);// 这里返回的是0到j-1
                }
            }
        }
        // 全比对上了，或者后面的但是比s0长且包含s0
        return s0;
    }
};

#endif // DEBUG1



