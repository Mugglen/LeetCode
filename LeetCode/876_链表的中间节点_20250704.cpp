





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

        // 创建双指针
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr) {

            // 奇数节点
            if (fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            // 偶数节点
            else {
                slow = slow->next;
                fast = fast->next;
            
            }


        }
        return slow;

    }
};
#endif // DEBUG
