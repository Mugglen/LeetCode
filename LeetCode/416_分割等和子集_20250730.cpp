#include <vector>
#include <numeric>
using namespace std;

//https://leetcode.cn/problems/partition-equal-subset-sum/solutions/2785266/0-1-bei-bao-cong-ji-yi-hua-sou-suo-dao-d-ev76/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
// 属于恰好装满的0-1背包问题(自顶向下递归)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 定义背包容量，这里是 nums的和/2，且必须为偶数，因为nums都是整数
        int sum = reduce(nums.begin(), nums.end());
        if (sum % 2) return false;
        // 记忆化搜索
        int n = nums.size();
        vector memo(n, vector<int>(sum / 2 + 1, -1));// -1表示没计算过
        // 递归搜索
        auto dfs = [&](this auto&& dfs, int i, int c) -> bool {
            // 如果选完了，检查背包容量
            if (i == 0) return c == 0;
            // 检查memo
            int& res = memo[i][c];
            if (res != -1) return res; // 错误点！！！注意是不等于-1才return
            // 背包装不下了，只能不选
            if (nums[i] > c) 
                res = dfs(i - 1, c);
            else { // 装的下，考虑选或不选
                res = dfs(i - 1, c - nums[i]) || dfs(i - 1, c); 
            }
            return res;
            };
        return dfs(n - 1, sum / 2);
    }
};

#endif // DEBUG



//#define DEBUG2
#ifdef DEBUG2
// 属于恰好装满的0-1背包问题(翻译成递推)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 定义背包容量，这里是 nums的和/2，且必须为偶数，因为nums都是整数
        int sum = reduce(nums.begin(), nums.end());
        if (sum % 2) return false;
        // 初始化dp数组
        int n = nums.size();
        vector dp(n + 1, vector<int>(sum / 2 + 1)); // 注意n + 1，为了处理下面原有i-1可能出现负值索引，整体的i加1
        dp[0][0] = true;
        // 迭代(自底向上)
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int c = 0; c <= sum / 2; c++) {
                if (c < x) { // 容量小于当前nums[i]，只能不选
                    //dp[i][c] = dp[i - 1][c];
                    dp[i + 1][c] = dp[i][c];
                }
                else {// 容量大于等于当前nums[i]，可选和不选
                    //dp[i][c] = dp[i - 1][c - x] || dp[i - 1][c];
                    dp[i + 1][c] = dp[i][c - x] || dp[i][c];
                }
            }
        }
        return dp[n][sum / 2];
    }
};

#endif // DEBUG2