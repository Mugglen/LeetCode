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
// ����һ�α���ͳ�ƣ�ʹ���������ж����һλ�����Ƿ�Ϊ1��������

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int ans = 0;
		// ͳ��ÿһλ����(��1��ʼ�ɣ���0��ʼû����)
        for (int i = 1; i <= n; ++i) {
			// ����ÿһλ
            for (int j = i; j > 0; j = j / 10) {
                // �������һλ���֣���λ����1����
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
// �Ż���������n��ÿһλ���з�����ÿһλ�ϳ���1�Ĵ�������ͨ����ѧ��ʽ���������

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int res = 0;
		long long MulBase = 1; // ����ÿһλ�Ļ���10^i
        for (int i = 0; MulBase <= n; i++) { // �� <=n����Ϊn���ܸպ���100�����Ļ���
            // ���ݹ�ʽ
			// 1. ����ȵ�ǰλλ���ߵ����֣��ڵ�ǰλ����1�ĸ���(n / (MulBase * 10)) * MulBase
			// 2. ���㵱ǰλ���ֶ�1�Ĺ��ף�������3�����
			//   a. ��ǰλ����Ϊ0����ǰλ����0��1
			//   b. ��ǰλ����Ϊ1����ǰλ����(n % (MulBase * 10)) + 1��1
			//   c. ��ǰλ���ִ���1����ǰλ����MulBase��1������๱��MulBase��1
            res += (n / (MulBase * 10)) * MulBase + min(max(n % (MulBase * 10) - MulBase + 1, (long long)0), MulBase);
            // �����������һλ��
            MulBase *= 10;
        }
        return res;
    }
};

#endif // DEBUG2


//#define DEBUG3
#ifdef DEBUG3
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/31-%E5%89%91%E6%8C%87offer.html
// ����ķ�����ʹ�õݹ飬�Ӹߵ��ͷ���ÿһλ���ֶ�1�Ĺ���
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        if (n <= 0) return 0;
        if (n < 10) return 1;
        int high = n, pow = 1;
		// �������λ�����λ�Ļ���
        while (high >= 10) {
            high = high / 10;
            pow = pow * 10;
        }
        // �����ȥ���λʣ�µ���
        int last = n - high * pow;
		// �������λ�Ĺ���
        int ans = (high == 1 ? last + 1 : pow);
		return ans + high * NumberOf1Between1AndN_Solution(pow - 1) + NumberOf1Between1AndN_Solution(last);
    }
};

#endif // DEBUG3