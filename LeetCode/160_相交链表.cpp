#include <iostream>
using namespace std;

// 定义链表节点结构
struct ListNode {
    int val; // 节点值
    ListNode* next; // 指向下一个节点的指针（注意是结构体指针）
    ListNode(int x) : val(x), next(NULL) {} // 构造函数
};

// 方法1——双指针法
// 解题核心在于相交链表从相交元素往后都是重合的！！！
// 要注意，交点不是数值相等，而是指针相等。
// 我们求出两个链表的长度，并求出两个链表长度的差值，然后让curA移动到，和curB 末尾对齐的位置。
// 此时我们就可以比较curA和curB是否相同，如果不相同，
// 同时向后移动curA和curB，如果遇到curA == curB，则找到交点。否则循环退出返回空指针。

// 解决方案类
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;

        // 计算链表A的长度
        while (curA != NULL) {
            lenA++;
            curA = curA->next;
        }

        // 计算链表B的长度
        while (curB != NULL) {
            lenB++;
            curB = curB->next;
        }

        // 重置指针到链表头部
        curA = headA;
        curB = headB;

        // 让curA指向较长的链表
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // 计算长度差
        int gap = lenA - lenB;

        // 将curA移动到与curB对齐的位置
        while (gap--) {
            curA = curA->next;
        }

        // 同时移动curA和curB，寻找交点
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        // 如果没有交点，返回NULL
        return NULL;
    }
};

//#define DEBUG
#ifdef DEBUG

// 测试代码
int main() {
    // 创建链表A: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // 创建链表B: 6 -> 7 -> 8 -> 4 -> 5（与链表A在节点4相交）
    ListNode* headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = new ListNode(8);
    headB->next->next->next = headA->next->next->next; // 链表B与链表A在节点4相交

    // 调用函数寻找交点
    Solution solution;
    ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

    // 输出结果
    if (intersectionNode != NULL) {
        cout << "交点的值为: " << intersectionNode->val << endl;
    }
    else {
        cout << "链表没有交点" << endl;
    }

    // 释放内存（简单示例，实际项目中需更复杂的资源管理）
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB->next->next->next;
    delete headB->next->next;
    delete headB->next;
    delete headB;

    return 0;
}

#endif // 

