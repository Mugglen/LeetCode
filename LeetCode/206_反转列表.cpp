#include <iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* next;
	// 使用成员初始化列表
	ListNode(int x) : value(x), next(NULL) {}// 注意是int x不是单纯的x，注意构造函数尾部是{}不是
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// 有三个指针（前一个节点，当前节点，后一个节点）
		// 主要操作：初始化当前节点，前一个节点，然后保存好下一个节点后，
		// 就把下一个节点替换成前一个节点，前一个节点替换成当前节点，当前节点替换成下一个节点

		// 保存好未反转节点的表头，一次反转一个节点，然后移动pre和curr
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != NULL) {
			ListNode* next_temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next_temp;
		}
		// 返回最后参与的反转的节点（就是链表最后一个节点）的指针，即为反转后的表头，不是返回curr，curr最后为空
		return prev;
	}
};


//#define DEBUG
#ifdef DEBUG


int main() {
	// 创建链表
	ListNode* head = new ListNode(1); // 注意使用new创建，而且new的返回值就是创建对象的指针
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	//创建反转对象
	Solution solution;

	// 使用方法
	ListNode* head_reverse = solution.reverseList(head);

	ListNode* ptr_temp = head_reverse;
	cout << "反转列表的值" << endl;
	while (ptr_temp-> next != NULL) {
		cout  << ptr_temp->value << endl;
		ptr_temp = ptr_temp->next;
	}
	cout << ptr_temp->value << endl; // 注意最后一个节点的next就是NULL了，所以要单独打印

	ptr_temp = head_reverse;
	while (ptr_temp != NULL) {
		cout << ptr_temp->value << endl;
		ptr_temp = ptr_temp->next;
	}
	 // 注意这样才可以直接遍历链表。
}
#endif // DEBUG
