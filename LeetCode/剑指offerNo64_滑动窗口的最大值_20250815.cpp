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
    // 使用大顶堆
    vector<int> maxInWindows(vector<int>& num, int size) {
        // 异常处理
        if (size > num.size() || size == 0 || num.size() == 0) return {};
        // 初始化
        int len = num.size(), count = 0;
        priority_queue<int> pq;
        vector<int> ans;

        // 滑动(大根堆维护窗，但每次都是独立塞入size个元素，判断结束再弹出，而不是动态加入)
        for (int i = 0; i <= len - size; ++i) {
            // 元素入窗
            while (count < size) {
                pq.push(num[i + count]);
                count++;
            }
            // 重置计数器，保存结果
            count = 0;
            ans.push_back(pq.top());
            while (!pq.empty()) {
                pq.pop();
            }
        }
        return ans;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2

class Solution {
public:
    // 使用双端队列
    vector<int> maxInWindows(vector<int>& num, int size) {
        vector<int> ans;
        int len = num.size();
        if (len == 0 || size == 0 || size > len) return ans;
        deque<int> dq; // 存储num的下标（维护最大元素下标，可以来判断最大元素在不在窗内）
        // 开始滑动(规定当前队列从后往前依次递增)
        for (int i = 0; i < len; ++i) {
            
            // 队列处理1：从后往前，小于当前元素的都pop掉
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            // 队列处理2：从前往后，判断最大元素有没有超出窗口
            while (!dq.empty() && i - dq.front() + 1 > size) {
                dq.pop_front();
            }
            // 处理完毕，直接插入(第二步处理等插入后再弄应该也行)
            dq.push_back(i);
            // 建窗完成后才开始压入答案
            if (i + 1 >= size) {
                ans.push_back(num[dq.front()]);
            }
        }
        return ans;
    }
};

#endif // DEBUG2