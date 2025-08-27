#include "stddef.h"

//#define DEBUG
#ifdef DEBUG

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// https://leetcode.cn/problems/linked-list-cycle-ii/solutions/12616/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		
		// ��������ָ��
		ListNode* slow = head;
		ListNode* fast = head;

		// ��һ��ѭ��
		while (true) {
			if (fast == nullptr || fast->next == nullptr)return nullptr; // �����޻�
			fast = fast->next->next; // ��ָ��ÿ��������
			slow = slow->next; // ��ָ��ÿ����һ��
			if (slow == fast)break; // ��������ˣ�˵���л�
		}

		// �ڶ���ѭ�����ҵ��������
		fast = head; // ����ָ�����õ�ͷ�ڵ�
		while (slow != fast) {
			slow = slow->next; // ��ָ��ÿ����һ��
			fast = fast->next; // ��ָ��ÿ����һ��
		}

		return fast;
	}
};
#endif // DEBUG
