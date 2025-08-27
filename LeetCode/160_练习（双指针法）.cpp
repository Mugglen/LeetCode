#include <iostream>
using namespace std;

// ��������
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		// ����˫ָ��
		ListNode*  curA = headA;
		ListNode* curB = headB;
		int lenA = 0, lenB = 0;
		//��������
		while (curA != NULL) {
			lenA++;
			curA = curA->next;
		}

		while (curB != NULL) {
			lenB++;
			curB = curB->next;
		}

		// ��������ָ��(��Ҫ©��)
		curA = headA;
		curB = headB;
		
		//ָ��������ָ�루Ҫ�Ƚ�ָ�����õ���ͷ��
		if (lenB > lenA) {
			swap(lenA, lenB);
			swap(curA, curB);

		}

		//��������ָ��
		int gap = lenA - lenB;
		while (gap--) {
			curA = curA->next;
		}

		// �ֱ����
		while (curA != NULL) {
			if (curA == curB) {
				return curA;
			}
			else {
				curA = curA->next;
				curB = curB->next;
			}
		}

		// û�н���
		return NULL;
	}
};

//#define DEBUG
#ifdef DEBUG
int main() {
	// ��������
	ListNode* headA = new ListNode(1); // new �����ڶ��Ϸ����ڴ棬��������ջ�ϡ�
	// �����ʹ��ջ�Ϸ��䣬ListNode headA(1);�� headA ��һ���ֲ����������ڵ�ǰ���������ʱ�����١���
	headA->next = new ListNode(2);
	headA->next->next = new ListNode(3);
	headA->next->next->next = new ListNode(4);
	headA->next->next->next->next = new ListNode(5);

	// ��������B
	ListNode* headB = new ListNode(6);
	headB->next = new ListNode(7);
	headB->next->next = new ListNode(8);
	headB->next->next->next = headA->next->next->next; // ����B������A�ڽڵ�4�ཻ

	Solution solution;
	ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

	// ������
	if (intersectionNode != NULL) {
		cout << "�����ֵΪ" << intersectionNode->val << endl;
	}
	else {
		cout << "����û�н���" << endl;
	}

	// �ֶ��ͷ��ڴ棨ע����Ҫ�����ͷţ���������ָ�����գ�
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
#endif // DEBUG
