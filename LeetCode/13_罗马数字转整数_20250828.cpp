#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


class Solution {

private:
    // ����һ����ϣ��洢ӳ��
    unordered_map<char, int> ROMAN = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };


public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            int x = ROMAN[s[i]];
            int y = ROMAN[s[i + 1]];
            // ��6���쳣����ϳ���һ��������ı�ǰ��Ĵ󣬾ͷ���
            ans += x < y ? -x : x; // ȡ��һ��ԭʼ���ж�
        }
        // �������һ��û��
        return ans += ROMAN[s.back()];
    }
};

#endif // DEBUG1