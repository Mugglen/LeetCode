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
    // 创建一个哈希表存储映射
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
            // 将6种异常规则合成这一个，后面的比前面的大，就反向
            ans += x < y ? -x : x; // 取后一个原始来判断
        }
        // 还有最后一个没加
        return ans += ROMAN[s.back()];
    }
};

#endif // DEBUG1