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
        // ʹ�ù�ϣ�������һ��string���ַ���ӳ�����ַ�
        // ��������˵�һ��string ����ͬ�ַ�����ͬkey��ӳ�䵽���ַ���ͬ��value��ͬ������false��
        if (s.size() == 0 || t.size() == 0) return s == t;
        if (s.size() != t.size()) return false;
        // ע��ӳ����˫��һһ��Ӧ�ģ�
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
// ��Ϊ����д������debug1˼·һ��
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s, s2t;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            // ��������ӳ�� a -> s2t[a]�����͵�ǰ�ַ�ӳ�� a -> b ��ƥ�䣬
            // ˵����һ�Զ��ӳ���ϵ���򷵻� false ��
            // ����ӳ�� b -> a Ҳͬ��
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