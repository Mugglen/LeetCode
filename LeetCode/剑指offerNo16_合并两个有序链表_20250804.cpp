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

    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        
        int cin = 0;
        ListNode* cur1 = pHead1;
        ListNode* cur2 = pHead2;
        ListNode dummy(-1);
        ListNode* dum = &dummy;
        ListNode* cur3 = &dummy;

        while (cur1 && cur2) {
            // 合并
            if (cur1->val <= cur2->val) {
                cur3->next = cur1;
                cur1 = cur1->next;
            }
            else {
                cur3->next = cur2;
                cur2 = cur2->next;
            }
            cur3 = cur3->next;
        }
        // 不等长处理
        cur3->next = cur1 ? cur1 : cur2;
        return dum->next;

    }
};


#endif // DEBUG1