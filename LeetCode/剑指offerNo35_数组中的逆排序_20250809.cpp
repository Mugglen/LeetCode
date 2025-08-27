#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/35-%E5%89%91%E6%8C%87offer.html
    int InversePairs(vector<int>& nums) {
        // 时间复杂度要求O(n),不能暴力算,但先写个暴力
        const int kmod = 1000000007;
        int ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    ret += 1;
                    ret %= kmod; // 有可能算的时候超,得每次都mod一次
                }
            }
        }
        return ret;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/35-%E5%89%91%E6%8C%87offer.html
    // 可以用归并排序，这题WXG好像手撕过
    int InversePairs(vector<int>& nums) {
        // 特判
        if (nums.size() == 0) return 0;
		vector<int> copy(nums);// 辅助数组，每次递归后有序
        return recursion(nums, copy, 0, nums.size() - 1);
    }

    int recursion(vector<int>& data, vector<int>& copy, int begin, int end) {
		if (begin == end) return 0; // 只有一个元素,没有逆序对
		int mid = begin + (end - begin) / 2; // 中间位置
		// 分治，分别求左右部分的逆序对数量
        // 为什么这里要交换data和copy？因为每次递归后，data是有序的，copy是无序的
		// 同时这样可以避免每次都要显式交换数组
        int left = recursion(copy, data, begin, mid); 
		int right = recursion(copy, data, mid + 1, end);

        // 再比较左右两半之间的逆序对
		int end1 = mid; // 左边的末尾
		int end2 = end; // 右边的末尾
        int index_copy = end; // 比较结果存入辅助数组的尾端
        long res = 0;

        // 归并排序：相当于两个有序数组合并成一个有序表（从尾端开始是为了计数）
        while (begin <= end1 && mid + 1 <= end2) {
            // 左右两半，尾端大的依次存入辅助数组尾部
            if (data[end1] > data[end2]) {
                copy[index_copy--] = data[end1--];
				res += end2 - mid; // 右边的元素比左边的元素小，说明右边的所有元素都比左边的这个元素小
				res %= 1000000007; // 防止溢出
            }
            else {
				copy[index_copy--] = data[end2--];
            }
        }
		while (begin <= end1) copy[index_copy--] = data[end1--]; // 左边的元素全部存入辅助数组
		while (mid + 1 <= end2) copy[index_copy--] = data[end2--]; // 右边的元素全部存入辅助数组
		return (left + right + res) % 1000000007; // 返回结果
    }

};

#endif // DEBUG2