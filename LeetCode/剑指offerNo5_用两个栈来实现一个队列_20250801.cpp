#include <stack>

using namespace std;


//#define DEBUG
#ifdef DEBUG

class Solution
{
public:
    void push(int node) {
        // ָ��stack1Ϊ��β
        stack1.push(node);
    }

    int pop() {
        int val;
        // ָ��stack2Ϊ��ͷ
        // ���ж϶�ͷջ�ղ��գ������ٴӶ�βջ����ѹ���ͷջ
        if (!stack2.empty()) {
            val = stack2.top();
            stack2.pop(); // ����㣡����֮ǰ����pop��
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
