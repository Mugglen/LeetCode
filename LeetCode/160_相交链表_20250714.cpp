#ifdef DEBUG
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        // 先求出两个链表的长度
        int lenA = 0, lenB = 0;

        ListNode* curA = headA;
        ListNode* curB = headB;

        while (curA) {
            lenA++;
            curA = curA->next;
        }
        while (curB) {
            lenB++;
            curB = curB->next;
        }

        // 为了让两个链表从同一位置开始比较，先让长的链表走lenA - lenB步
        curA = headA;
        curB = headB;
        if (lenA < lenB) {// A取较长的
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;

        while (gap--) {
            curA = curA->next;
        }

        while (curA) {
            if (curA == curB) {
                return curA; // 找到相交点
            }
            else {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr; // 没有相交点
    }
};
#endif // DEBUG
