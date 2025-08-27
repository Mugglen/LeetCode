#include <vector>
#include <algorithm>

using namespace std;

// 排序法
// 时间复杂度 O(NlogN) ： 其中 N 为数组元素数量。
// 空间复杂度： 取决于内置排序算法的具体设计。
class Solution_sort {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

//https://leetcode.cn/problems/kth-largest-element-in-an-array/solutions/2361969/215-shu-zu-zhong-de-di-k-ge-zui-da-yuan-d786p
// 方法2：快速选择(哨兵划分和递归)
//时间复杂度：O(N)
//空间复杂度：O(logN)

class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

private:
    int quickSelect(vector<int>& nums, int k) {
        //随机选择基准数
        int pivot = nums[rand() % nums.size()];

        // 将大于、小于、等于 pivot的元素划分至big, small, equal 中
        vector<int> big, equal, small;

        for (int num : nums) {
            if (num > pivot) {
                big.push_back(num);
            }
            else if (num < pivot) {
                small.push_back(num);
            }
            else {
                equal.push_back(num);
            }

        }

        // 第k大元素在big中，递归划分
        if (k <= big.size()) {
            return quickSelect(big, k);
        }

        // 第k大元素在small中，递归划分
        if (nums.size() - small.size() < k) {
            return quickSelect(small, k - nums.size() + small.size());
        }
        return pivot;
    
    }

};