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

// 这题原题没了，写写看看思路
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/49-%E5%89%91%E6%8C%87offer.html
// 采用阿秀二刷的做法
class Solution {
public:
	int StrToInt(string str) {
		int len = str.size();
		if (len == 0) return 0; // 空字符串

		int i = 0, flag = 1, isSignal = 0; // siSignal用于标记是否有符号位，flag为正负标志位
		long res = 0; // 使用long防止溢出
		while (i < len && str[i] == ' ') i++; // 跳过前导空格
		if (i >= len) return 0; // 全是空格的情况

		// 符号位以及合法性判断
		while (i < len && (str[i] == '-' || str[i] == '+')) { // 判断正负标志位
			if (str[i] == '-') flag = -1; // 负数
			i++; // 跳过符号位
			isSignal++; // 标记有符号位
			if (isSignal > 1) return 0; // 如果有多个符号位，返回0
		}
		// 核心转换逻辑
		for (; i < len; i++) {
			if (str[i] > '9' || str[i] < '0') return 0; // 非数字字符，返回0
			res = res * 10 + (str[i] - '0'); // 累加数字(从高位开始的，每次要将前一次的结果乘10)
			if (res > INT_MAX && flag == 1) return INT_MAX; // 正数溢出
			if (res > INT_MAX + 1 && flag == -1) return INT_MIN; // 负数溢出
		}
		return res * flag; // 返回结果
	}
};

#endif // DEBUG1


