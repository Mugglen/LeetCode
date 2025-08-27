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
        // 这里集成了很多操作，i相当于左指针，for循环维护c右指针
        for (char c : t) {
            // 这里只有s[i] == c 的时候i 才会++步进，s匹配结束后结束循环
            if (s[i] == c && ++i == s.length()) {
                return true;
            }
        }
        return false;
    }
};


#endif // DEBUG1