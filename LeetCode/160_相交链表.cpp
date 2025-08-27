#include <iostream>
using namespace std;

// ��������ڵ�ṹ
struct ListNode {
    int val; // �ڵ�ֵ
    ListNode* next; // ָ����һ���ڵ��ָ�루ע���ǽṹ��ָ�룩
    ListNode(int x) : val(x), next(NULL) {} // ���캯��
};

// ����1����˫ָ�뷨
// ������������ཻ������ཻԪ���������غϵģ�����
// Ҫע�⣬���㲻����ֵ��ȣ�����ָ����ȡ�
// ���������������ĳ��ȣ���������������ȵĲ�ֵ��Ȼ����curA�ƶ�������curB ĩβ�����λ�á�
// ��ʱ���ǾͿ��ԱȽ�curA��curB�Ƿ���ͬ���������ͬ��
// ͬʱ����ƶ�curA��curB���������curA == curB�����ҵ����㡣����ѭ���˳����ؿ�ָ�롣

// ���������
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;

        // ��������A�ĳ���
        while (curA != NULL) {
            lenA++;
            curA = curA->next;
        }

        // ��������B�ĳ���
        while (curB != NULL) {
            lenB++;
            curB = curB->next;
        }

        // ����ָ�뵽����ͷ��
        curA = headA;
        curB = headB;

        // ��curAָ��ϳ�������
        if (lenB > lenA) {
            swap(lenA, lenB);
            swap(curA, curB);
        }

        // ���㳤�Ȳ�
        int gap = lenA - lenB;

        // ��curA�ƶ�����curB�����λ��
        while (gap--) {
            curA = curA->next;
        }

        // ͬʱ�ƶ�curA��curB��Ѱ�ҽ���
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }

        // ���û�н��㣬����NULL
        return NULL;
    }
};

//#define DEBUG
#ifdef DEBUG

// ���Դ���
int main() {
    // ��������A: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(2);
    headA->next->next = new ListNode(3);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);

    // ��������B: 6 -> 7 -> 8 -> 4 -> 5��������A�ڽڵ�4�ཻ��
    ListNode* headB = new ListNode(6);
    headB->next = new ListNode(7);
    headB->next->next = new ListNode(8);
    headB->next->next->next = headA->next->next->next; // ����B������A�ڽڵ�4�ཻ

    // ���ú���Ѱ�ҽ���
    Solution solution;
    ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

    // ������
    if (intersectionNode != NULL) {
        cout << "�����ֵΪ: " << intersectionNode->val << endl;
    }
    else {
        cout << "����û�н���" << endl;
    }

    // �ͷ��ڴ棨��ʾ����ʵ����Ŀ��������ӵ���Դ����
    delete headA->next->next->next->next;
    delete headA->next->next->next;
    delete headA->next->next;
    delete headA->next;
    delete headA;
    delete headB->next->next->next;
    delete headB->next->next;
    delete headB->next;
    delete headB;

    return 0;
}

#endif // 

