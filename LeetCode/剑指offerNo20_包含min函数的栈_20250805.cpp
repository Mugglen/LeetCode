#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {

private:
    int minVal = INT_MAX;
    stack<int> st;

public:
    void push(int value) {
        // 维护全栈最小，注意当前类也有min，指定命名空间
        minVal = std::min(value, minVal);
        // 关键，每次插入前同时插入维护当前最小状态
        st.push(minVal);
        st.push(value);
    }

    void pop() {
        // 记得现在一组是两个值，当时value和插入value时的最小值
        st.pop();
        int preMin = st.top();
        st.pop();
        // 弹出来更新一下最小值（应该也可以检查弹出的是不是最小值，再更新吧）
        if (!st.empty() && preMin == minVal) {
            int temp = st.top();
            st.pop();
            minVal = st.top();
            st.push(temp);
        }

    }
    int top() {
        return st.top();
    }
    int min() {
        return minVal;
    }
};

#endif // DEBUG1