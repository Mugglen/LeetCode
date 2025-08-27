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

    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        // 题目要求时间复杂度O（nlogk），应该不能直接排序后取前k个，那应该是O(nlogn*k)
        // 不管先暴力一手
        if (k == 0) return{};
        if (k > input.size()) return input;
        sort(input.begin(), input.end());
        return { input.begin(), input.begin() + k };
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/29-%E5%89%91%E6%8C%87offer.html
class Solution {
public:
    // 优先级队列，求最小用大顶堆
    // 前置知识
    // priority_queue<T, Container, Compare> pq;
    //​​ T​​: 存储的元素类型（这里是 int）
    //​​ Container​​ : 底层容器（默认是 vector<T>）
    //​​ Compare​​ : 比较函数 / 函数对象（默认是 less<T>，即大顶堆，堆顶是最大元素）我们改成greater<int>​​: 表示堆顶是最小元素（小顶堆）


    //​​建堆​​：所有元素依次插入小顶堆，时间复杂度 O(nlogn)
    //​​取前k小​​：从堆顶依次取出k个最小元素，时间复杂度 O(klogn)

    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        // 特判
        if (k > input.size()) return {};
        // 优先级队列
        priority_queue<int, vector<int>, greater<int>> pq;
        // 建堆
        for (auto a : input) {
			pq.push(a);
        }
        // 取前k小
		vector<int> ans;
        while (k--) {
			ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};

#endif // DEBUG2