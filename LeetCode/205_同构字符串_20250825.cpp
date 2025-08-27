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
    bool isIsomorphic(string s, string t) {
        // 使用哈希表来存第一个string中字符和映射后的字符
        // 如果出现了第一个string 中相同字符（相同key）映射到的字符不同（value不同）就是false；
        if (s.size() == 0 || t.size() == 0) return s == t;
        if (s.size() != t.size()) return false;
        // 注意映射是双向一一对应的，
        unordered_map<char, char> mapLtoR;
        unordered_map<char, char> mapRtoL;
        for (int i = 0; i < s.size(); i++) {
            if (mapLtoR.find(s[i]) != mapLtoR.end()) {
                if (t[i] != mapLtoR[s[i]]) return false;
            }
            else if (mapRtoL.find(t[i]) != mapRtoL.end()) {
                if (s[i] != mapRtoL[t[i]]) return false;
            }
            else {
                mapLtoR[s[i]] = t[i];
                mapRtoL[t[i]] = s[i];
            }
        }
        return true;
    }
};


#endif // DEBUG1

//#define DEBUG2
#ifdef DEBUG2
// https://leetcode.cn/problems/isomorphic-strings/solutions/1645867/by-jyd-i4wt/?envType=study-plan-v2&envId=top-interview-150
// 更为简洁的写法，和debug1思路一样
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s, s2t;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            // 对于已有映射 a -> s2t[a]，若和当前字符映射 a -> b 不匹配，
            // 说明有一对多的映射关系，则返回 false ；
            // 对于映射 b -> a 也同理
            if (s2t.find(a) != s2t.end() && s2t[a] != b ||
                t2s.find(b) != t2s.end() && t2s[b] != a)
                return false;
            s2t[a] = b;
            t2s[b] = a;
        }
        return true;
    }
};




#endif // DEBUG2