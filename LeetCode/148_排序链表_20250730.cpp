

//#define DEBUG
#ifdef DEBUG


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ����˼·���ֳ��������ֱ�����
class Solution {
public:

    // ���������м�ڵ�(����ָ�룬����Ҫ�ϳ�����������ֻ�Ƿ����м�ڵ�)
    ListNode* middleNode(ListNode* head) {
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; // �Ͽ� slow ��ǰһ���ڵ�� slow ������
        return slow; // ��ʱ���ص��ǵڶ��������ͷ
    }

    // �ϲ�������������
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
            cur = cur->next; // ͳһ�ƶ�cur
        }
        cur->next = cur1 ? cur1 : cur2; // ƴ��ʣ������
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }


    ListNode* sortList(ListNode* head) {
        // �쳣����Ҳ�Ǳ߽紦��(ֻ��һ���ڵ����ֱ��Ϊ��)
        if (head == nullptr || head->next == nullptr) return head;
        // �ϳ���������
        ListNode* head2 = middleNode(head);
        // ����
        head = sortList(head);
        head2 = sortList(head2);
        // �ϲ�
        return mergeTwoLists(head, head2);
    }
};
#endif // DEBUG
