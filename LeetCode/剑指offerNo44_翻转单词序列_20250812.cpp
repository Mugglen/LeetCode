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
    string ReverseSentence(string str) {
        // 题目保证没有只包含空格的字符串，只需处理空字符串
        if (str.empty()) return str;
        // 先反转
        reverse(str.begin(), str.end());
        // 使用双指针定位一个单词
        int left = 0;
        for (int right = 0; right < str.size(); right++) {
            if (str[right] == ' ') {
				reverse(str.begin() + left, str.begin() + right);
				left = right + 1; // 更新左指针到下一个单词的起始位置
            }
        }
		// 最后一个单词需要单独处理
        reverse(str.begin() + left, str.end());
		return str;
    }
};

#endif // DEBUG1