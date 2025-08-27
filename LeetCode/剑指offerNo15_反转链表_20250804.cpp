#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;

//#define DEBUG1
#ifdef DEBUG1


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param head ListNode��
     * @return ListNode��
     */
    ListNode* ReverseList(ListNode* head) {
        
        if (head == nullptr && head->next == nullptr)return head;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};

#endif // DEBUG1