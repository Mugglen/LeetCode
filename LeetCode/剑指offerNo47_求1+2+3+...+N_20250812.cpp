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
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/47-%E5%89%91%E6%8C%87offer-2.html
    // 使用逻辑与的短路特性实现递归终止
    int Sum_Solution(int n) {
		int sum = n;
        // 当 n > 0 时，递归调用 Sum_Solution(n - 1)，否则不调用
		n > 0 && (sum += Sum_Solution(n - 1));
		return sum;
    }
};

#endif // DEBUG1


