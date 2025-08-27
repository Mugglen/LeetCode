#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* cur1 = list1;
        ListNode* cur2 = list2;

        while (cur1 && cur2) {
            if (cur1->val <= cur2->val) {
                cur->next = cur1;
                cur = cur->next;
                cur1 = cur1->next;
            }
            else {
                cur->next = cur2;
                cur = cur->next;
                cur2 = cur2->next;
            }
        }
        cur->next = cur1 ? cur1 : cur2;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

#endif // DEBUG1