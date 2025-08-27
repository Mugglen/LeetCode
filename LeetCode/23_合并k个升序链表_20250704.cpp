
#include <vector>
using namespace std;


//#define DEBUG
#ifdef DEBUG

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val(val), next(next) {};
};


class Solution {
public:
    // 合并两个有序链表
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

		// 
		ListNode* cur1 = list1;
		ListNode* cur2 = list2;


		ListNode* dummy = new ListNode(-1, nullptr);

		ListNode* cur3 = dummy;

		while (cur1 && cur2) {

			if (cur1->val <= cur2->val) { // 注意！！！！是值比较，不要写成指针比较了
				//if (cur1 <= cur2) {
				cur3->next = cur1;
				cur3 = cur3->next;
				cur1 = cur1->next;
			}
			else {
				cur3->next = cur2;
				cur3 = cur3->next;
				cur2 = cur2->next;
			}
			//cur1 = cur1->next; // 注意！！！！两个cur也要移动,但不是同时移动
			//cur2 = cur2->next;

		}

		if (cur1 == nullptr) {
			cur3->next = cur2;
		}
		else {
			cur3->next = cur1;
		}

		ListNode* temp = dummy->next;
		delete dummy;
		return temp;
	}


    ListNode* mergeKLists(vector<ListNode*>& lists) {

		if (lists.empty())return nullptr;

		ListNode* dummy = new ListNode(-INT_MAX, nullptr);

		for (ListNode* head : lists) {
			
			dummy = mergeTwoLists(dummy, head);
		
		}

		ListNode* temp = dummy->next;
		delete dummy;
		return temp;
    }
};

#endif // DEBUG
