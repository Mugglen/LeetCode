
#include <vector>

using namespace std;

// https://leetcode.cn/problems/trapping-rain-water/solutions/1974340/zuo-liao-nbian-huan-bu-hui-yi-ge-shi-pin-ukwm

// 相向双指针
// 时间复杂度O(n)
// 空间复杂度O(1)

//柱子高度：
//0 1 0 2 1 0 1 3 2 1 2 1
//
//最高柱子：
//- 左边：[0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]
//- 右边：[3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]
//
//接水量：
//0 0 1 0 1 2 1 0 1 2 1 0

//每个位置的接水量 = min(左边的最大高度, 右边的最大高度) - 当前柱子的高度




class Solution {

public:
	int trap(vector<int>& height) {
		
		int ans = 0;  // 存储总的接水量
		int left = 0, right = height.size() - 1;  // 左指针和右指针
		int pre_max = 0, suf_max = 0;  // 左边和右边的最大高度(前缀prefix, 后缀suffix)

		// 注意 while 循环可以不加等号，
		// 因为在「谁小移动谁」的规则下，相遇的位置一定是最高的柱子，这个柱子是无法接水的。
		while (left < right) {
			
			// 更新左右两边的最大高度
			pre_max = max(pre_max, height[left]);
			suf_max = max(suf_max, height[right]);

			// 判断左右最大高度哪个小（小的一边才有可能积水，最后积水多少看当前柱子高度）
			if (pre_max < suf_max) {
				// 计算左边柱子接的水量
				ans += pre_max - height[left];
				left++;
			}else{
				// 计算右边柱子接的水量
				ans += suf_max - height[right];
				right--;
			}
		
		}
		return ans;
	
	}
};