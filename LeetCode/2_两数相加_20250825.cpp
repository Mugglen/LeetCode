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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        int cin = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while (cur1 || cur2 || cin) {
            int num1 = cur1 ? cur1->val : 0;
            int num2 = cur2 ? cur2->val : 0;
            int sum = num1 + num2 + cin;
            if (sum >= 10) {
                sum = sum % 10;
                cin = 1;
            }
            else {
                cin = 0;
            }
            cur->next = new ListNode(sum);
            cur = cur->next;
            cur1 = cur1 ? cur1->next : nullptr;
            cur2 = cur2 ? cur2->next : nullptr;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};


#endif // DEBUG1
