#ifdef DEBUG
struct ListNode {

	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {};
};


class Solution {

public:
	ListNode* removeElements(ListNode* head, int val) {
		
		// �쳣����
		if (head == nullptr)return nullptr;

		// �����ڱ�
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		// ��������ָ��
		ListNode* pre = dummy;
		ListNode* cur = head;

		while (cur != nullptr) {
			
			if (cur->val == val) {
				
				pre->next = cur->next;

				// ����Ҫ�ͷ�cur��
				cur = cur->next;
				
			}
			else {
				pre = pre->next;
				cur = cur->next;
			
			}
		
		}

		// Ҫ�ͷ��ڱ���
		ListNode* temp = dummy->next;
		delete dummy;
		return temp;
	
	}
};



#endif // DEBUG
