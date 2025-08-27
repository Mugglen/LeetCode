#include <stack>
using namespace std;

#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/implement-queue-using-stacks/solutions/2363977/232-yong-zhan-shi-xian-dui-lie-qing-xi-t-pi4l/
class MyQueue {
public:
    MyQueue() {

    }

    // ����˼·��˫ջ��һ������ʵ�ּ����β��һ����������ʵ�ֶ���ͷ
    std::stack<int> tail, head;


    void push(int x) {
        tail.push(x);
    }

    int pop() {
        int peek = this->peek();
        head.pop();
        return peek;
    }

    // ע��㣬tail���Գ����������β�������ݣ�����Ҫ��head��պ���ܷ���ѹ��head��
    int peek() {

        // ���head���ж���
        if (!head.empty())return head.top();

        // ���head���ˣ�����tail��û��,���˶��о�û������
        if (tail.empty())return -1;

        //���head�յ���tail���У���ѹ��head��
        while (!tail.empty()) {
            head.push(tail.top());
            tail.pop();
        }

        // ע��ѹ����Ҫ����peek�Ľ��
        return head.top();

    }

    bool empty() {
        return tail.empty() && head.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
#endif // DEBUG
