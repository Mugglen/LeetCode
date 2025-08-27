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

// 需要快速取出中间值，属于对顶堆算法的典型应用
// 先用暴力法做做
class Solution {
public:
    vector<int> nums;

    void Insert(int num) {
        nums.push_back(num);
    }

    double GetMedian() {
		sort(nums.begin(), nums.end());
        int len = nums.size();
        // 偶数
        if (len % 2 == 0) 
			// 注意这里是2.0 ,这样才能返回double类型
            return (nums[len / 2] + nums[-1 + len / 2]) / 2.0;
        else// 奇数
			return nums[len / 2];
    }

};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

// 使用两个堆来维护数据流的中位数
class Solution {

private:
	int count = 0; // 奇偶计数
	priority_queue<int, vector<int>, less<int>> big_heap; // 大顶堆（根节点最大）
    priority_queue<int, vector<int>, greater<int>> small_heap; // 小顶堆（根节点最小）

public:
    // 注意当前的约定，不同的约定代码实现不同
    // 对于中位数的求取（和阿秀一样）
    // 如果是偶数：中位数为 mid = (leftMax + rightMin)/2
    // 如果是奇数：中位数为 mid = leftMax
    // 所以应该是优先插入左侧大根堆，保证在奇数的时候大根堆比小根堆元素多1
    // 而且两个堆元素相差不能超过1，所以下面会有动态调整的过程

    void Insert(int num) {
        // 计数
		count++;
        // 当前是第奇数个元素
        if (count % 2 == 1) {
            // 空堆无脑插入左侧
            if (big_heap.empty()) big_heap.push(num);
            // 非空需要考虑堆平衡，直接插入左侧，不比较的话可能导致 leftMax > rightMin
            else {
                // 和rightMin先比一下
                int rightMin = small_heap.top();
                if (num <= rightMin) big_heap.push(num); // 安全的，直接插入左侧即可
                else {// 比rightMin大了，要交换一下，把rightMin拿出来插入左侧
                    // 注意，这里说成（交换）也不对！！！！,有可能比rightMin大很多，插入small_heap中有可能不是倒数第二小的，
                    // 这里直接插入后pop，让最小堆来自动选出最小的
                    small_heap.push(num);
                    small_heap.pop();
                    big_heap.push(rightMin);
                }
                
            }
        }
        // 当前是第偶数个元素，已经保证大根堆里有东西了，要插入右侧才能补齐
        // 但同样无脑插入可能导致rightMin < leftMax，都需要判断一下，
        // 这里small_heap空不空应该都是一个判断逻辑
        else {
            int leftMax = big_heap.top();
            if (num >= leftMax) small_heap.push(num); // 合法，可以插入右侧
            else { // 比leftMax小了，把leftMax插入右侧
                big_heap.push(num);
                big_heap.pop();
                small_heap.push(leftMax);
            }
        }

    }

    double GetMedian() {
        // 处理奇数
        if (count % 2 == 1) {
            return big_heap.top();
        }
        else {
            return double((small_heap.top() + big_heap.top()) / 2.0);
        }

    }
};

#endif // DEBUG2