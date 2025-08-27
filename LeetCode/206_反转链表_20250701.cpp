


//#define DEBUG
#ifdef DEBUG

struct ListNode {

	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {};

};

// 注意，这是错误写法
/*class Solution {
public:
    ListNode* reverseList(ListNode* head) {

		// 需要三个指针，pre, cur, next
		ListNode* pre = nullptr;
		ListNode* cur = head;
		ListNode* next = head->next;// 错误点1

		while (cur != nullptr) {
			// 修改cur的下一个(提前保存好next)
			cur->next = pre;
			
			// 移动三个指针
			pre = cur;
			cur = next;
			next = cur->next; // 错误点2，当cur是最后一个元素的时候Next为nullptr
		}

		return pre;
    }
};*/


class Solution {
public:
	ListNode* reverseList(ListNode* head) {

		// 需要三个指针，pre, cur, next
		ListNode* pre = nullptr;
		ListNode* cur = head;
		//ListNode* next = head->next;

		while (cur != nullptr) {
			// 修改cur的下一个(提前保存好next)
			ListNode* next = cur->next;
			cur->next = pre;

			// 移动三个指针
			pre = cur;
			cur = next;
			//next = cur->next;
		}

		return pre;
	}
};







#endif // DEBUG
