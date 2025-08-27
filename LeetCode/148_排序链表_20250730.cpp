

//#define DEBUG
#ifdef DEBUG


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 分治思路，分成子链，分别排序
class Solution {
public:

    // 查找链表中间节点(快慢指针，而且要断成两个链表，不只是返回中间节点)
    ListNode* middleNode(ListNode* head) {
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // 断开 slow 的前一个节点和 slow 的连接
        return slow; // 此时返回的是第二段链表的头
    }

    // 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* cur = dummy;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next; // 统一移动cur
        }
        cur->next = cur1 ? cur1 : cur2; // 拼接剩余链表
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }


    ListNode* sortList(ListNode* head) {
        // 异常处理（也是边界处理）(只有一个节点或者直接为空)
        if (head == nullptr || head->next == nullptr) return head;
        // 断成两个链表
        ListNode* head2 = middleNode(head);
        // 分治
        head = sortList(head);
        head2 = sortList(head2);
        // 合并
        return mergeTwoLists(head, head2);
    }
};
#endif // DEBUG
