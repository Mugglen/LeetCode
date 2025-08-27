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
// Լɪ�����⣨�����ⷨ��
class Solution {
public:

    int LastRemaining_Solution(int n, int m) {
        // û��С����,��
        if (n == 0 || m == 0) return -1;
		int ans = 0; // Լɪ�򻷵Ľ�
        // ��С���󣬸���x
        for (int i = 2; i <= n; i++) {
			ans = (m + ans) % i; 
        }
        return ans;
    }
};
#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// Լɪ�����⣨�ݹ�ⷨ��
class Solution {
public:

    int LastRemaining_Solution(int n, int m) {
        // û��С����,��
        if (n == 0 || m == 0) return -1;
        function<int(int, int)> josephus = [&](int n, int m) -> int {
            if (n == 1) return 0; // ֻ��һ��С����
            return (josephus(n - 1, m) + m) % n; // �ݹ鹫ʽ
			};

        return josephus(n ,m);
    }
};
#endif // DEBUG2