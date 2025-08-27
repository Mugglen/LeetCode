





//#define DEBUG
#ifdef DEBUG

struct ListNode {

    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(nullptr) {};

};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if (head == nullptr)return head;

        // ����˫ָ��
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr) {

            // �����ڵ�
            if (fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            // ż���ڵ�
            else {
                slow = slow->next;
                fast = fast->next;
            
            }


        }
        return slow;

    }
};
#endif // DEBUG
