#include <vector>
#include <queue>
using namespace std;



//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // https://leetcode.cn/problems/sliding-window-maximum/solutions/2499715/shi-pin-yi-ge-shi-pin-miao-dong-dan-diao-ezj6/?envType=study-plan-v2&envId=top-100-liked
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // 初始化结果
        vector<int> ans;
        deque<int> q;

        // 使用单调队列(注意只维护下标)
        for (int i = 0; i < nums.size(); i++) {
            // 1.右边入（元素进入队尾，同时维护队列单调性）
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            // 2.左边出（元素离开队首）
            if (q.front() <= i - k) {
                q.pop_front();
            }

            // 3.记录答案(从k-1索引才开始每次滑动记录答案，没到这之前窗长不足k)
            if (i >= k - 1) {
                // 由于队首到队尾单调递减，所以窗口最大值就在队首
                ans.push_back(nums[q.front()]);
            }

        }
        return ans;

    }
};
#endif // DEBUG


//#define PRETICE
#ifdef PRETICE

class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // 题目提示了k < nums.length不用考虑
        // 初始化结果
        vector<int> ans;

        // 使用单调队列（因为每个循环要兼顾出入）
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
        
            // 1.队尾加入时进行比较，保存队列从队首到队尾单调减(注意队列存放的是索引)

            // 错误写法！！！！！！！！！只比较了一次，要把队列里所有小于当前值的都pop掉
            /*if (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
                dq.push_back(i);
            }*/
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            // 2.检查队首元素索引是否已经超出当前窗口，超出就去掉(其实就是等于的情况)
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // 3. 从窗的长度足够时开始记录答案
            if (i >= k - 1) {
                //ans.push_back(dq.front()); // 错误写法2！！！！！又只存了索引没存数组值
                ans.push_back(nums[dq.front()]);
            }
        
        }
        return ans;

    }
};




#endif // PRETICE