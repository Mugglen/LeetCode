#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // 本题注意k是可以大于链表长度的，和删除链表倒数k个节点还不太一样
    ListNode* rotateRight(ListNode* head, int k) {
        // 其实是断开倒数第k个节点，尾部连接到第一个节点
        // 为了兼容旋转个数等于链表节点个数的情况，引入哨兵
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(-1, head);
        // 需要头指针，倒数k个节点前一位的指针，已经走了k步的指针
        // 注意k超过链表长度需要取模
        ListNode* left = dummy;
        ListNode* right = head;
        int count = 0;
        // 先获取链表长度
        while (right) {
            count++;
            right = right->next;
        }
        k = k % count; // 对k取模
        if (k == 0) return head; // 不用旋转，直接返回
        right = dummy; // 复位右指针（注意是复位到dummy上，兼容k = 0的情况，复位到head上就是默认k = 1了）
        while (k--) {
            right = right->next;
        }
        // 同时移动左右指针
        while (right) {
            left = left->next;
            right = right->next;
            // 遇到最后一个节点时，把链表尾部和头部连接，并退出循环
            if (right->next == nullptr) {
                right->next = head;
                break;
            }
        }
        // 保存结果头指针，断开
        ListNode* newHead = left->next;
        left->next = nullptr;
        delete dummy; // 释放哨兵
        return newHead;
    }
};


#endif // DEBUG1