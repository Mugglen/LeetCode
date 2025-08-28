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
        {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}, // 个位
        {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 十位
        {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 百位
        {"", "M", "MM", "MMM"}, // 千位
    };

public:
    string intToRoman(int num) {
        // 数字每一位长度相等，可以按位取
        return R[3][num / 1000] + R[2][num / 100 % 10] + R[1][num / 10 % 10] + R[0][num % 10];
    }
};



#endif // DEBUG1