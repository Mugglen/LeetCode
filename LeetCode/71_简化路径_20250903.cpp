#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

// https://leetcode.cn/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    string simplifyPath(string path) {
        // 辅助栈(栈思想，不是真的用栈)
        vector<string>stk;
        // 注意这里的字符串分割法(需要引入<sstream>)
        istringstream ss(path);
        string s;
        while (getline(ss, s, '/')) { // 按/号分割
            // 合并处理多个///和‘.’
            if (s.empty() || s == ".") {
                continue;
            }
            // 对于“..”返回上一级
            if (s != "..") {
                stk.push_back(s);
            }
            else if(!stk.empty()){
                stk.pop_back();
            }
        }
        // 处理完了，把栈的东西格式化取出
        string ans;
        for (string& s : stk) {
            ans += '/';
            ans += s;
        }
        return stk.empty() ? "/" : ans;
    }
};



#endif // DEBUG1