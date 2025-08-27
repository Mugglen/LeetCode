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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        // ˫ָ��ͬʱ������ע��������||����&&��
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (true) {
            if (fast->next == nullptr || fast->next->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
    }
};


#endif // DEBUG1
