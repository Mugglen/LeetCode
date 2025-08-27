#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// 使用辅助栈，和自己验证的思路一样，按照入栈顺序加入辅助栈，但是遇到出栈顺序的栈顶的元素的时候，让这个元素弹出
// 就是模拟一次入栈出栈，看最后能不能对应上
class Solution {
public:
    // 压入栈的所有数字均不相等
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // 先判断序列长度等不等（这道题已经说明了长度相等了，也可能不是全部元素出栈，注意看题就行）
        if (pushV.size() != popV.size()) return false;
        int n = pushV.size();
        // 辅助栈
        stack<int> st;
        // 入栈下标
        int in = 0;
        // 开始模拟出入栈，对出栈下标枚举
        for (int out = 0; out < n; out++) {
            // 入栈规则：栈为空或者栈顶不等于当前出栈元素
            while (in < n && (st.empty() || st.top() != popV[out])) {
                st.push(pushV[in]);
                in++;
            }
            // 不满足入栈规则，情况1：栈顶现在是当前出栈元素，给它弹出来
            if (st.top() == popV[out]) {
                st.pop();
            }
            else { // in == n了，入栈元素已经压完了，但是当前出栈元素不等于栈顶元素，说明出栈顺序是错的
                return false;
            }
        }
        // 全部出栈，顺序正确
        return true;
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// 辅助栈，练习
class Solution {
public:
    // 压入栈的所有数字均不相等
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // 不同特判，长度相等
        // 需要维护入栈索引和出栈索引，加辅助占
        stack<int> st;
        int in = 0;
        // 对出栈元素索引枚举
        for (int out = 0; out < popV.size(); out++) {
            // 入栈：元素没取完 && （栈为空 || 栈顶元素不出栈
            while (in < pushV.size() && (st.empty() || st.top() != popV[out])) {
                st.push(pushV[in]);
                in++;
            }
            // 需要出栈
            if (st.top() == popV[out]) {
                st.pop();
                // out的增加给外部for循环来做
            }
            else {// 全部压栈完毕，但当前栈顶元素和出栈元素不匹配
                return false;
            }
        }
        return true;
    }
};

#endif // DEBUG2