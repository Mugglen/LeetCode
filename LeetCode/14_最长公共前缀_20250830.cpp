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
        for (int j = 0; j < s0.size(); j++) { // ö��ÿ����ĸ
            for (string& s : strs) {          // ��ÿ�����ʱȶ�
                if (j == s.size() || s[j] != s0[j]) {
                    return s0.substr(0, j);// ���ﷵ�ص���0��j-1
                }
            }
        }
        // ȫ�ȶ����ˣ����ߺ���ĵ��Ǳ�s0���Ұ���s0
        return s0;
    }
};

#endif // DEBUG1



