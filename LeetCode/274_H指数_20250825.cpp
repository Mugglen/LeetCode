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
    // https://leetcode.cn/problems/h-index/solutions/2502837/mei-kan-dong-ti-yi-yi-zhang-tu-miao-dong-8zps/?envType=study-plan-v2&envId=top-interview-150
    int hIndex(vector<int>& citations) {
        // 注意到 h 指数一定不会大于n
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int c : citations) {
            // 统计引用次数恰好为 k 的论文数
            cnt[min(c, n)]++; // 引用次数 > n，等价于引用次数为 n
        }
        int s = 0;
        for (int i = n; ; i--) { // i = 0的时候， s >= i一定成立
            s += cnt[i]; // s 就表示当前引用数大于i的论文有几篇
            if (s >= i) { // 说明有至少 i 篇论文的引用次数至少为i
                return i;
            }
        }
    }
};

#endif // DEBUG1
