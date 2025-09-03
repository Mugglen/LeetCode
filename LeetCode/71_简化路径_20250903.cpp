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
        // ����ջ(ջ˼�룬���������ջ)
        vector<string>stk;
        // ע��������ַ����ָ(��Ҫ����<sstream>)
        istringstream ss(path);
        string s;
        while (getline(ss, s, '/')) { // ��/�ŷָ�
            // �ϲ�������///�͡�.��
            if (s.empty() || s == ".") {
                continue;
            }
            // ���ڡ�..��������һ��
            if (s != "..") {
                stk.push_back(s);
            }
            else if(!stk.empty()){
                stk.pop_back();
            }
        }
        // �������ˣ���ջ�Ķ�����ʽ��ȡ��
        string ans;
        for (string& s : stk) {
            ans += '/';
            ans += s;
        }
        return stk.empty() ? "/" : ans;
    }
};



#endif // DEBUG1