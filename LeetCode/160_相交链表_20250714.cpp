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

        // �������������ĳ���
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

        // Ϊ�������������ͬһλ�ÿ�ʼ�Ƚϣ����ó���������lenA - lenB��
        curA = headA;
        curB = headB;
        if (lenA < lenB) {// Aȡ�ϳ���
            swap(lenA, lenB);
            swap(curA, curB);
        }
        int gap = lenA - lenB;

        while (gap--) {
            curA = curA->next;
        }

        while (curA) {
            if (curA == curB) {
                return curA; // �ҵ��ཻ��
            }
            else {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr; // û���ཻ��
    }
};
#endif // DEBUG
