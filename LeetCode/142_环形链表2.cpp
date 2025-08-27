#include <iostream>
using namespace std; // NULL也是std里的




struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}

};


// 快慢指针法（从头结点出发一个指针，从相遇节点 也出发一个指针，
// 这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点。）
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		// 创建快慢指针
		ListNode* fast = head;
		ListNode* slow = head; // 不用像只是检测环那样岔开，都从头节点开始才行

		// 环检测，找相遇点（注意差错控制，可能没环）
		while (fast != nullptr && fast->next != nullptr) {

			//步进
			slow = slow->next;
			fast = fast->next->next;

			// 相遇处理
			if (slow == fast) {
				// 从相遇点到入环点的距离加上 n−1 圈的环长，
				// 恰好等于从链表头部到入环点的距离。
				ListNode* index1 = fast;
				ListNode* index2 = head;

				// 查找环入口
				while (index1 != index2) {
					index1 = index1->next;
					index2 = index2->next;

				}
				return index2;
			}
		}
		// 处理无环的情况
		return NULL;


	}


};

//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	head->next->next->next->next->next->next->next = head->next->next->next;

	ListNode* result = solution.detectCycle(head);

	if (result != nullptr) {
		cout << "是环形链表，且入环点在：" << result << endl;

	}
	else {
		cout << "不是环形链表" << endl;
	}

	

}



#endif