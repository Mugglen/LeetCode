#include <vector>
#include <unordered_set>
using namespace std;
// https://leetcode.cn/problems/longest-consecutive-sequence/solutions/3005726/ha-xi-biao-on-zuo-fa-pythonjavacgojsrust-whop/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

		int ans = 0;
        unordered_set<int> set(nums.begin(), nums.end()); // 把nums转成哈希集合
        // 注意是遍历哈希集合（可以避免对重复元素的计算）
        for (int x : set) {
			if (set.contains(x - 1)) continue; // 如果当前数字的前一个数字在集合中，说明当前数字不是连续序列的起点，跳过
            
			// 没有比x更小的连续数字，说明x是一个连续序列的起点
			int y = x + 1; // 当前数字的下一个数字
            while (set.contains(y)) { y++; }// 不断查找下一个数字

			// 注意循环后， y - 1是最后一个连续数字
			// 结果直接用 y - x 来计算当前连续序列的长度
			ans = max(ans, y - x); // 更新最长连续序列的长度
        
        }
        return ans;

    }
};
#endif // DEBUG

//#define PRETICE
#ifdef PRETICE
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // 题目要求O（n），不能排序O(nlogn)
        int ans = 0;
        unordered_set<int> set(nums.begin(), nums.end());

		// 注意遍历哈希集合
        for(int x : set){
            if (set.contains(x - 1)) continue;

			int y = x + 1; // 当前数字的下一个数字
            while (set.contains(y)) { y++; }

			ans = max(ans, y - x); // 更新最长连续序列的长度
        }
        return ans;

    }
};
#endif // PRETICE
