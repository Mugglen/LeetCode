#ifdef DEBUG
struct ListNode {

	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {};
};


class Solution {

public:
	ListNode* removeElements(ListNode* head, int val) {
		
		// 异常处理
		if (head == nullptr)return nullptr;

		// 创建哨兵
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		// 创建辅助指针
		ListNode* pre = dummy;
		ListNode* cur = head;

		while (cur != nullptr) {
			
			if (cur->val == val) {
				
				pre->next = cur->next;

				// 这里要释放cur吗
				cur = cur->next;
				
			}
			else {
				pre = pre->next;
				cur = cur->next;
			
			}
		
		}

		// 要释放哨兵吗
		ListNode* temp = dummy->next;
		delete dummy;
		return temp;
	
	}
};



#endif // DEBUG
