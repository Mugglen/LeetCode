#include <stack>
#include <vector>

using namespace std;


// 通常是一维数组，要寻找任一个元素的右边或者左边第一个比自己大或者小的元素的位置，此时我们就要想到可以用单调栈了
// 单调栈里只需要存放元素的下标i就可以了，如果需要使用对应的元素，直接T[i]就可以获取。
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // 从左到右的写法
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // 创建辅助栈(存放元素下标)
        stack<int> st;
        // 结果数组
        vector<int> res(temperatures.size(), 0);
        // 初始化栈顶
        st.push(0);

        // 从左到右遍历，
        for (int i = 0; i < temperatures.size(); i++) {
        
            // 情况1，当前元素小于栈顶元素（比栈内元素都小，压入栈）
            if (temperatures[i] < temperatures[st.top()]) {
                // 只推入元素下标
                st.push(i);
            }
            // 情况2，当前元素等于栈顶元素（比栈内其他元素都小，还是要压入栈）
            else if (temperatures[i] == temperatures[st.top()]) {
                st.push(i);
            }
            // 情况3，当前元素大于栈顶元素（处理）
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    
                    // 当前位置的下标减去栈顶元素的下标
                    res[st.top()] = i - st.top();
                    st.pop();
                
                }
                st.push(i);
            
            }

        }
        return res;
    }
};
#endif // DEBUG
