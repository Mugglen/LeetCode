#include <vector>

using namespace std;
// https://leetcode.cn/problems/jump-game-ii/solutions/2926993/tu-jie-yi-zhang-tu-miao-dong-tiao-yue-yo-h2d4/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
// 注意题目说了，测试用例可以保证可达，下面就没考虑不可达的情况
class Solution {
public:
    int jump(vector<int>& nums) {

        // 在跳跃游戏1的基础上，每次选取当前步长范围内（右端点）最远步长，作为下一跳的步长
		// 注意不是选当前步长范围内的最大步长，而是最远步长！！！这个一开始想错了
        int ans = 0;
		int cur_right = 0; // 当前跳跃范围的右端点
        int next_right = 0; // 下一跳的右端点的最大值

        for (int i = 0; i + 1 < nums.size(); i++) {
            // 遍历过程中，记录下一跳可选的最远点
            next_right = max(next_right, i + nums[i]);
            // 遍历完当前一次跳跃范围内所有点，再更新下一次跳跃
            if (i == cur_right) {
				// 可以在这里考虑不可达的情况，如果到达cur_right时，next_right等于cur_right，应该就不可达，不可达应该最后一位都是0
                cur_right = next_right;
                ans++;
            }
        }
        return ans;

    }
};
#endif // DEBUG

//#define PRETICE
#ifdef PRETICE
class Solution {
public:
    int jump(vector<int>& nums) {

        int ans = 0;
		int cur_right = 0; // 当前跳跃范围的右端点
        int next_right = 0; // 下一跳右端点最大值

        // 核心思路就是遍历过程中，找到当前跳跃范围内，下一跳到达右端点最远的
        for (int i = 0; i + 1 < nums.size(); i++) {
            next_right = max(next_right, i + nums[i]);
            if (i == cur_right) {
                cur_right = next_right;
                ans++;
            }
        }
        return ans;
    }
};
#endif // PRETICE