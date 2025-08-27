#include <vector>

using namespace std;

// https://leetcode.cn/problems/container-with-most-water/solutions/11491/container-with-most-water-shuang-zhi-zhen-fa-yi-do
//在每个状态下，无论长板或短板向中间收窄一格，都会导致水槽 底边宽度 −1​ 变短：
//
//若向内 移动短板 ，水槽的短板 min(h[i], h[j]) 可能变大，因此下个水槽的面积 可能增大 。
//若向内 移动长板 ，水槽的短板 min(h[i], h[j])​ 不变或变小，因此下个水槽的面积 一定变小 。
// 每轮向内移动短板，所有消去的状态都 不会导致面积最大值丢失 
// 时间复杂度O(N)
// 空间复杂度O(1)
class Solution {

public:
	int maxArea(vector<int>& height) {
		// 初始化左右指针
		int left = 0, right = height.size() - 1;

		// 初始化结果
		int maxWater = 0;

		// 只要左指针小于右指针就继续
		while (left < right) {
			// 找到短板
			maxWater = height[left] < height[right] ?
				// 使用短板高度更新最大值
				max(maxWater, (right - left) * height[left++]) :
				max(maxWater, (right - left) * height[right--]);
		}
		return maxWater;
	}
};