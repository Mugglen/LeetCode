

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

	// 传入的就是链表表头，所以哑节点dummy还是得在方法里创建
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		
		// 创建哨兵
		ListNode dummy(-1, head);

		// 双指针
		ListNode* left = &dummy;
		ListNode* right = head; // 注意，这里是为了左右指针同时步进结束时,left指向要删除元素的上一个

		// 右指针步进
		for (int i = 0; i < n; i++) {
			// 不考虑链表长度不够的情况
			if (right == nullptr)return head;
			right = right->next;

		}

		// 同时步进
		while (right) {
			left = left->next;
			right = right->next;
		}

		ListNode* cur = left->next;
		// 注意错误点！！！！这样会删除包括倒数第N个元素后所有的节点
		//left->next = right;
		left->next = left->next->next;
		delete cur;

		return dummy.next;

	}
};

#endif // DEBUG
