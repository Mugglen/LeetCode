#include <vector>
#include <unordered_map>
using namespace std;



// https://leetcode.cn/problems/4sum-ii/
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
		unordered_map<int, int> cnt;
		// 计算 nums1 和 nums2 的所有可能和，在计算-num3-num4时就可直接查找
        for (int x : nums1) {
            for (int y : nums2) {
                cnt[x + y]++;
            }
        }
		int ans = 0;
        for (int x : nums3) {
            for (int y : nums4) {
				ans += cnt[-(x + y)]; // 查找 - (x + y) 的出现次数
            }
        }
		return ans;
    }
};
#endif // DEBUG
