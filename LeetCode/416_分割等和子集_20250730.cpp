#include <vector>
#include <numeric>
using namespace std;

//https://leetcode.cn/problems/partition-equal-subset-sum/solutions/2785266/0-1-bei-bao-cong-ji-yi-hua-sou-suo-dao-d-ev76/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
// ����ǡ��װ����0-1��������(�Զ����µݹ�)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // ���屳�������������� nums�ĺ�/2���ұ���Ϊż������Ϊnums��������
        int sum = reduce(nums.begin(), nums.end());
        if (sum % 2) return false;
        // ���仯����
        int n = nums.size();
        vector memo(n, vector<int>(sum / 2 + 1, -1));// -1��ʾû�����
        // �ݹ�����
        auto dfs = [&](this auto&& dfs, int i, int c) -> bool {
            // ���ѡ���ˣ���鱳������
            if (i == 0) return c == 0;
            // ���memo
            int& res = memo[i][c];
            if (res != -1) return res; // ����㣡����ע���ǲ�����-1��return
            // ����װ�����ˣ�ֻ�ܲ�ѡ
            if (nums[i] > c) 
                res = dfs(i - 1, c);
            else { // װ���£�����ѡ��ѡ
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
// ����ǡ��װ����0-1��������(����ɵ���)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // ���屳�������������� nums�ĺ�/2���ұ���Ϊż������Ϊnums��������
        int sum = reduce(nums.begin(), nums.end());
        if (sum % 2) return false;
        // ��ʼ��dp����
        int n = nums.size();
        vector dp(n + 1, vector<int>(sum / 2 + 1)); // ע��n + 1��Ϊ�˴�������ԭ��i-1���ܳ��ָ�ֵ�����������i��1
        dp[0][0] = true;
        // ����(�Ե�����)
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int c = 0; c <= sum / 2; c++) {
                if (c < x) { // ����С�ڵ�ǰnums[i]��ֻ�ܲ�ѡ
                    //dp[i][c] = dp[i - 1][c];
                    dp[i + 1][c] = dp[i][c];
                }
                else {// �������ڵ��ڵ�ǰnums[i]����ѡ�Ͳ�ѡ
                    //dp[i][c] = dp[i - 1][c - x] || dp[i - 1][c];
                    dp[i + 1][c] = dp[i][c - x] || dp[i][c];
                }
            }
        }
        return dp[n][sum / 2];
    }
};

#endif // DEBUG2