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
// 方法一：直接把字符串拼接到后面，然后取子串
class Solution {
public:

    string LeftRotateString(string str, int n) {
        int len = str.size();
		if (len == 0) return str; // 特殊情况处理
		if (n >= len) n = n % len; // 处理 n 大于字符串长度的情况
		str += str; // 将字符串拼接到后面
		return str.substr(n, len); // 返回从 n 开始的长度为 len 的子串
    }
};

#endif // DEBUG1




//#define DEBUG2
#ifdef DEBUG2
// 方法二：字符串整体反转，再反转两部分
class Solution {
public:

	string LeftRotateString(string str, int n) {
		int len = str.size();
		if (len == 0) return str; // 特殊情况处理
		if (n >= len) n = n % len; // 处理 n 大于字符串长度的情况
		// 反转整个字符串
		reverse(str.begin(), str.end());
		// 分别反转前半部分和后半部分
		reverse(str.begin(), str.begin() + len - n); // 反转前半部分
		reverse(str.begin() + len - n, str.end()); // 反转后半部分
		return str; // 返回最终结果
	}
};

#endif // DEBUG2