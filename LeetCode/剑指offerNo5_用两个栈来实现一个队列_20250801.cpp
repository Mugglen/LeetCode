#include <stack>

using namespace std;


//#define DEBUG
#ifdef DEBUG

class Solution
{
public:
    void push(int node) {
        // 指定stack1为队尾
        stack1.push(node);
    }

    int pop() {
        int val;
        // 指定stack2为队头
        // 先判断队头栈空不空，空了再从队尾栈反向压入队头栈
        if (!stack2.empty()) {
            val = stack2.top();
            stack2.pop(); // 错误点！！！之前忘记pop了
        }
        else {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
            val = stack2.top();
            stack2.pop();
        }
        return val;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};


#endif // DEBUG
