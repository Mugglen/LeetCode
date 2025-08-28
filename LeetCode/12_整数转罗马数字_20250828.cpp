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

// https://leetcode.cn/problems/integer-to-roman/solutions/2848775/jian-ji-xie-fa-pythonjavaccgojsrust-by-e-kmp6/?envType=study-plan-v2&envId=top-interview-150

class Solution {
    string R[4][10] = {
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // ��λ
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // ʮλ
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // ��λ
        {"", "M", "MM", "MMM"}, // ǧλ
    };

public:
    string intToRoman(int num) {
        // ����ÿһλ������ȣ����԰�λȡ
        return R[3][num / 1000] + R[2][num / 100 % 10] + R[1][num / 10 % 10] + R[0][num % 10];
    }
};



#endif // DEBUG1