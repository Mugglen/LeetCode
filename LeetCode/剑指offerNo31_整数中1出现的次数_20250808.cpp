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
// https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&&tqId=11184&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// 先来一次暴力统计，使用连除法判断最后一位数字是否为1，并计数

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int ans = 0;
		// 统计每一位数字(从1开始吧，从0开始没意义)
        for (int i = 1; i <= n; ++i) {
			// 遍历每一位
            for (int j = i; j > 0; j = j / 10) {
                // 遇到最后一位数字（个位）是1计数
                if (j % 10 == 1) ans++;
            }
        }
        return ans;
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&&tqId=11184&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// 优化方案：对n的每一位进行分析，每一位上出现1的次数可以通过数学公式计算出来。

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int res = 0;
		long long MulBase = 1; // 计算每一位的基数10^i
        for (int i = 0; MulBase <= n; i++) { // 是 <=n，因为n可能刚好是100这样的基数
            // 根据公式
			// 1. 计算比当前位位数高的数字，在当前位贡献1的个数(n / (MulBase * 10)) * MulBase
			// 2. 计算当前位数字对1的贡献，其中有3种情况
			//   a. 当前位数字为0，则当前位贡献0个1
			//   b. 当前位数字为1，则当前位贡献(n % (MulBase * 10)) + 1个1
			//   c. 当前位数字大于1，则当前位贡献MulBase个1，且最多贡献MulBase个1
            res += (n / (MulBase * 10)) * MulBase + min(max(n % (MulBase * 10) - MulBase + 1, (long long)0), MulBase);
            // 计算完后扩大一位数
            MulBase *= 10;
        }
        return res;
    }
};

#endif // DEBUG2


//#define DEBUG3
#ifdef DEBUG3
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/31-%E5%89%91%E6%8C%87offer.html
// 阿秀的方法，使用递归，从高到低分析每一位数字对1的贡献
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n <= 0) return 0;
        if (n < 10) return 1;
        int high = n, pow = 1;
		// 计算最高位和最高位的基数
        while (high >= 10) {
            high = high / 10;
            pow = pow * 10;
        }
        // 计算除去最高位剩下的数
        int last = n - high * pow;
		// 计算最高位的贡献
        int ans = (high == 1 ? last + 1 : pow);
		return ans + high * NumberOf1Between1AndN_Solution(pow - 1) + NumberOf1Between1AndN_Solution(last);
    }
};

#endif // DEBUG3