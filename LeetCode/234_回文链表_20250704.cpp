


//#define DEBUG
#ifdef DEBUG

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x, ListNode* next) :val(x), next(next) {};

};


class Solution {
public:
    ListNode* findMid(ListNode* head) {
        
        if (head == nullptr)return head;
        ListNode* slow = head;
        ListNode* fast = head;;
    
        while (fast->next != nullptr) {
            
            if (fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            else {
                slow = slow->next;
                fast = fast->next;
            }

        }

        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        
        if (head == nullptr)return head;
       

        // ��������ָ��
        ListNode* pre = nullptr;
        ListNode* cur = head;
        

        while (cur) {
            
            ListNode* next = cur->next;
            // ����
            cur->next = pre;
            pre = cur;
            cur = next;
        
        }

        return pre;
    }

    // https://leetcode.cn/problems/palindrome-linked-list/solutions/2952645/o1-kong-jian-zuo-fa-xun-zhao-zhong-jian-rv0f3/?envType=study-plan-v2&envId=top-100-liked
    bool isPalindrome(ListNode* head) {

        // �����м�ڵ�
        ListNode* mid = findMid(head);

        // ��ת�м�ڵ㿪ʼ������(ע�⣡����������������mid�ڵ��ǰһ���ڵ���reverse֮��Ҳ����Ͽ���
        // ��ż���ڵ������»�������������ȳ�������ѭ����������Ҫʹ��head2���ж�)
        ListNode* head2 = reverseList(mid);

        ListNode* cur1 = head;
        ListNode* cur2 = head2;
        while (cur2) {
            
            if (cur1->val == cur2->val) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else {
                return false;
            }
        }
        return true;


    }
};



#endif // DEBUG
