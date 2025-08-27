


//#define DEBUG
#ifdef DEBUG

struct ListNode {

	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};

};

// ע�⣬���Ǵ���д��
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {

		// ��Ҫ����ָ�룬pre, cur, next
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* next = head->next;// �����1

		while (cur != nullptr) {
			// �޸�cur����һ��(��ǰ�����next)
			cur->next = pre;
			
			// �ƶ�����ָ��
			pre = cur;
			cur = next;
			next = cur->next; // �����2����cur�����һ��Ԫ�ص�ʱ��NextΪnullptr
		}

		return pre;
    }
};*/


class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		// ��Ҫ����ָ�룬pre, cur, next
		ListNode* pre = nullptr;
		ListNode* cur = head;
		//ListNode* next = head->next;

		while (cur != nullptr) {
			// �޸�cur����һ��(��ǰ�����next)
			ListNode* next = cur->next;
			cur->next = pre;

			// �ƶ�����ָ��
			pre = cur;
			cur = next;
			//next = cur->next;
		}

		return pre;
	}
};







#endif // DEBUG
