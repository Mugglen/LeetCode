#include <stack>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>  // �������������Ϣ

class MinStack {
    std::stack<int> x_stack;
    std::stack<int> min_stack;

    // �����������
    void debugPrint(const std::string& operation) {
        std::cout << operation << ": " << std::endl;
        std::cout << "  Top of x_stack: " << (x_stack.empty() ? "Empty" : std::to_string(x_stack.top())) << std::endl;
        std::cout << "  Min stack top: " << (min_stack.empty() ? "Empty" : std::to_string(min_stack.top())) << std::endl;
        std::cout << std::endl;
    }

public:
    MinStack() {
        min_stack.push(INT_MAX);  // ��ʼ�� min_stack��ȷ��ջΪ��ʱ��getMin() ������ȷ��ֵ
        debugPrint("Initial state");
    }

    void push(int x) {
        x_stack.push(x);
        min_stack.push(std::min(min_stack.top(), x));
        debugPrint("After pushing " + std::to_string(x));
    }

    void pop() {
        if (!x_stack.empty()) {
            std::cout << "Popped: " << x_stack.top() << std::endl;
            x_stack.pop();
            min_stack.pop();
        }
        debugPrint("After popping");
    }

    int top() {
        int topValue = x_stack.empty() ? -1 : x_stack.top();
        std::cout << "Top of stack: " << topValue << std::endl;
        return topValue;
    }

    int getMin() {
        int minValue = min_stack.empty() ? -1 : min_stack.top();
        std::cout << "Min value: " << minValue << std::endl;
        return minValue;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {
    MinStack minStack;

    minStack.push(-2);  // ���ÿ�β������ջ״̬
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();  // �����ǰ��Сֵ
    minStack.pop();     // ���ÿ�� pop ǰ���ջ״̬
    minStack.top();     // ���ջ��Ԫ��
    minStack.getMin();  // �����ǰ��Сֵ

    return 0;
}

#endif // DEBUG
