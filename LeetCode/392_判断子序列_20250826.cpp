#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        int i = 0;
        // ���Ｏ���˺ܶ������i�൱����ָ�룬forѭ��ά��c��ָ��
        for (char c : t) {
            // ����ֻ��s[i] == c ��ʱ��i �Ż�++������sƥ����������ѭ��
            if (s[i] == c && ++i == s.length()) {
                return true;
            }
        }
        return false;
    }
};


#endif // DEBUG1