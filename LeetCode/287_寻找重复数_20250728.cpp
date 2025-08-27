#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/find-the-duplicate-number/solutions/2361404/287-xun-zhao-zhong-fu-shu-yuan-di-jiao-h-0eja/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    vector<int> nums;

    int next(int index){
        // 直接返回当前索引处的值作为下一个索引
        return nums[index];
    }

    int findDuplicate(vector<int>& nums) {
        // 原地对数组使用环形链表Ⅱ的思路，双指针
        this->nums = nums;
        int slow = 0;
        int fast = 0;
        // 第一次相遇(用do和while是因为一开始slow和fast初始化为一个起点，不能直接使用while(slow != fast))
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast);
        slow = 0;
        // 第二次相遇
        while (slow != fast) {
            slow = next(slow);
            fast = next(fast);
        }
        return slow;
    }
};
#endif // DEBUG
