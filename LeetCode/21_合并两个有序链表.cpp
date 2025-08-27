#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}

};

// 迭代法
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// 造一个牵头节点，之后只用这个节点的指向下一个节点的指针；
		ListNode* preHead = new ListNode(-1);

		// 处理链表时的暂存指针
		ListNode* prev = preHead;

		//分别比较两个链表内容，拼接到牵头节点后面
		while (list1 != nullptr && list2 != nullptr) {
			if (list1->val < list2->val) {
				prev->next = list1;
				list1 = list1->next;
			
			}
			else
			{
				prev->next = list2;
				list2 = list2->next;
			}
			prev = prev->next;
		
		
		}
		prev->next = list1 == nullptr ? list2 : list1;

		return preHead->next;
	
	}

};


//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(4);
	head1->next->next->next->next = new ListNode(5);
	head1->next->next->next->next->next = new ListNode(6);
	head1->next->next->next->next->next->next = new ListNode(7);

	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(2);
	head2->next->next = new ListNode(3);
	head2->next->next->next = new ListNode(4);
	head2->next->next->next->next = new ListNode(5);


	ListNode* result = solution.mergeTwoLists(head1, head2);


	cout << "合并后的链表地址为：" << result << endl;

	ListNode* ptrPrint = result;
	
	while (ptrPrint != nullptr) {
		cout << "合并后的链表内容"<< ptrPrint->val << endl;
		ptrPrint = ptrPrint->next;
	
	}





}



#endif

