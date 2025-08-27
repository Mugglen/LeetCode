

//#define DEBUG
#ifdef DEBUG
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x, ListNode* next) : val(x), next(next) {};
};


class Solution
{
public:

	// ����ľ��������ͷ�������ƽڵ�dummy���ǵ��ڷ����ﴴ��
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		
		// �����ڱ�
		ListNode dummy(-1, head);

		// ˫ָ��
		ListNode* left = &dummy;
		ListNode* right = head; // ע�⣬������Ϊ������ָ��ͬʱ��������ʱ,leftָ��Ҫɾ��Ԫ�ص���һ��

		// ��ָ�벽��
		for (int i = 0; i < n; i++) {
			// �����������Ȳ��������
			if (right == nullptr)return head;
			right = right->next;

		}

		// ͬʱ����
		while (right) {
			left = left->next;
			right = right->next;
		}

		ListNode* cur = left->next;
		// ע�����㣡������������ɾ������������N��Ԫ�غ����еĽڵ�
		//left->next = right;
		left->next = left->next->next;
		delete cur;

		return dummy.next;

	}
};

#endif // DEBUG
