#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/single-number/solutions/2361995/136-zhi-chu-xian-yi-ci-de-shu-zi-wei-yun-iyd0/?envType=study-plan-v2&envId=top-100-liked
// 要求时间复杂度O（N）
// 空间复杂度O(1)
// 排除 暴力法 和 辅助哈希表法
class Solution {
public:
    // 
    int singleNumber(vector<int>& nums) {

        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x;


    }
};
#endif // DEBUG
