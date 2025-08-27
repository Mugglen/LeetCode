#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/2950686/tu-jie-xun-xu-jian-jin-cong-shuang-zhi-z-p2gd/?envType=study-plan-v2&envId=top-100-likedv
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
			swap(nums1, nums2); // 保证 nums1 是较小的数组,这样保证下面的i 可以从0 开始枚举
        }

		int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), INT_MIN); // 最左边插入
        nums2.insert(nums2.begin(), INT_MIN);
		nums1.push_back(INT_MAX); // 最右边插入
		nums2.push_back(INT_MAX);

        // 枚举 nums1 有 i 个数在第一组
        // nums2 有 j = (m + n + 1) / 2 - i 个数在第一组
        int i = 0, j = (m + n + 1) / 2; // 注意这里的 j 是向下取整的
        while (true) {
            if (nums1[i] <= nums2[j + 1] && nums1[i + 1] > nums2[j]) { // 写 >= 也可以
				int max1 = max(nums1[i], nums2[j]); // 第一组的最大值
				int min2 = min(nums1[i + 1], nums2[j + 1]); // 第二组的最小值
				return (m + n) % 2 ? max1 : (max1 + min2) / 2.0; // 奇数个数返回最大值，偶数个数返回平均值
            }
            i++;
            j--;
        
        }
    }
};
#endif // DEBUG
