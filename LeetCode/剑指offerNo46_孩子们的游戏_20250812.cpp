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
// 约瑟夫环问题（迭代解法）
class Solution {
public:

    int LastRemaining_Solution(int n, int m) {
        // 没有小朋友,或
        if (n == 0 || m == 0) return -1;
		int ans = 0; // 约瑟夫环的解
        // 从小到大，更新x
        for (int i = 2; i <= n; i++) {
			ans = (m + ans) % i; 
        }
        return ans;
    }
};
#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// 约瑟夫环问题（递归解法）
class Solution {
public:

    int LastRemaining_Solution(int n, int m) {
        // 没有小朋友,或
        if (n == 0 || m == 0) return -1;
        function<int(int, int)> josephus = [&](int n, int m) -> int {
            if (n == 1) return 0; // 只有一个小朋友
            return (josephus(n - 1, m) + m) % n; // 递归公式
			};

        return josephus(n ,m);
    }
};
#endif // DEBUG2