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
		// ���� nums1 �� nums2 �����п��ܺͣ��ڼ���-num3-num4ʱ�Ϳ�ֱ�Ӳ���
        for (int x : nums1) {
            for (int y : nums2) {
                cnt[x + y]++;
            }
        }
		int ans = 0;
        for (int x : nums3) {
            for (int y : nums4) {
				ans += cnt[-(x + y)]; // ���� - (x + y) �ĳ��ִ���
            }
        }
		return ans;
    }
};
#endif // DEBUG
