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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        // 新建两个链表，一个存 < x，一个存 >= x
        ListNode* minor = new ListNode(-1, nullptr);
        ListNode* greater = new ListNode(-1, nullptr);\
        // 工作指针
        ListNode* cur = head; 
        ListNode* curMin = minor;
        ListNode* curBig = greater;

        while (cur) {
            if (cur->val < x) {
                curMin->next = cur; // 接入
                curMin = curMin->next; // 移动
                cur = cur->next;
            }
            else {
                curBig->next = cur; // 接入
                curBig = curBig->next; // 移动
                cur = cur->next;
            }
        }
        // 遍历结束，先把两个链表尾可能连着的关系断了
        curMin->next = nullptr;
        curBig->next = nullptr;
        // 拼接
        curMin->next = greater->next;
        // 返回结果，清空资源
        ListNode* ans = minor->next;
        delete minor;
        delete greater;
        return ans;
    }
};


#endif // DEBUG1