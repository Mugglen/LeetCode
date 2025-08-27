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
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/48-%E5%89%91%E6%8C%87offer.html
    int Add(int num1, int num2) {
        while (num2 != 0) {
			int sum = num1 ^ num2; // 异或操作，计算不进位的和
			int carry = (num1 & num2) << 1; // 与操作，计算进位
			num1 = sum; // 更新num1为不进位的和
			num2 = carry; // 更新num2为进位
        }
		return num1; // 返回最终的和
    }
};

#endif // DEBUG1


