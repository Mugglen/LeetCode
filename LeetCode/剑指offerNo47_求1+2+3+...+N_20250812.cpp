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
    // ʹ���߼���Ķ�·����ʵ�ֵݹ���ֹ
    int Sum_Solution(int n) {
		int sum = n;
        // �� n > 0 ʱ���ݹ���� Sum_Solution(n - 1)�����򲻵���
		n > 0 && (sum += Sum_Solution(n - 1));
		return sum;
    }
};

#endif // DEBUG1


