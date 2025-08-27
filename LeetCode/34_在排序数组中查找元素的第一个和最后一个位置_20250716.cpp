#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {
public:

	// 闭区间写法，返回最小的满足 nums[i] >= target 的 i
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; 
        while (left <= right) { // 区间不为空
            // 更新中值（记得处理溢出）
			int mid = left + (right - left) / 2; // 防止溢出
            if(nums[mid] >= target)right = mid - 1; // 右边界收缩(在检测到target后仍然移动)
			else left = mid + 1; // 左边界收缩（右边界最终会收敛到第一个target的左边一个，等left和right相等时，left + 1就指向了第一个target，此时返回left）
        }
		return left; // 返回左边界
    }

    int higher_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) { // 区间不为空
            // 更新中值（记得处理溢出）
            int mid = left + (right - left) / 2; // 防止溢出
            if (nums[mid] <= target) left = mid + 1; // 左边界收缩(在检测到target后仍然移动)
            else right = mid - 1; // 右边界收缩（左边界最终会收敛到最后一个target的右边一个，等left和right相等时，right - 1就指向了最后一个target，此时返回right）
        }
        return right; // 返回右边界
    }

    vector<int> searchRange(vector<int>& nums, int target) {
		int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return { -1, -1 };
        }
        // 如果start存在，那么end 一定存在
		//int end = lower_bound(nums, target + 1) - 1; // 找到第一个大于target的元素的下标，减一就是最后一个等于target的元素
		
        // 直接找上界，感觉还是使用下界函数找上界精妙一点
        int end = higher_bound(nums, target);
        return { start, end };
    }
};
#endif