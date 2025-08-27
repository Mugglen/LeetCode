#include <stack>
using namespace std;

#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/implement-queue-using-stacks/solutions/2363977/232-yong-zhan-shi-xian-dui-lie-qing-xi-t-pi4l/
class MyQueue {
public:
    MyQueue() {

    }

    // 核心思路，双栈里一个用来实现加入队尾，一个用来反序，实现队列头
    std::stack<int> tail, head;


    void push(int x) {
        tail.push(x);
    }

    int pop() {
        int peek = this->peek();
        head.pop();
        return peek;
    }

    // 注意点，tail可以持续保存队列尾部的数据，但是要等head清空后才能反向压入head中
    int peek() {

        // 如果head还有东西
        if (!head.empty())return head.top();

        // 如果head空了，看看tail空没空,空了队列就没数据了
        if (tail.empty())return -1;

        //如果head空但是tail还有，就压入head里
        while (!tail.empty()) {
            head.push(tail.top());
            tail.pop();
        }

        // 注意压入完要返还peek的结果
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
