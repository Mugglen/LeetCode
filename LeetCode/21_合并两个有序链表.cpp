#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}

};

// ������
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		// ��һ��ǣͷ�ڵ㣬֮��ֻ������ڵ��ָ����һ���ڵ��ָ�룻
		ListNode* preHead = new ListNode(-1);

		// ��������ʱ���ݴ�ָ��
		ListNode* prev = preHead;

		//�ֱ�Ƚ������������ݣ�ƴ�ӵ�ǣͷ�ڵ����
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


	cout << "�ϲ���������ַΪ��" << result << endl;

	ListNode* ptrPrint = result;
	
	while (ptrPrint != nullptr) {
		cout << "�ϲ������������"<< ptrPrint->val << endl;
		ptrPrint = ptrPrint->next;
	
	}





}



#endif

