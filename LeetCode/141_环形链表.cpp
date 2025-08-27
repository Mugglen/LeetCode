// 使用快慢指针法，我们定义两个指针，一快一慢。慢指针每次只移动一步，而快指针每次移动两步。

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}

};


// 时间复杂度O(N)
// 空间复杂度O(1)
class Solution {
public:
	bool solution(ListNode* head) {
	// 差错处理
		if ( head == nullptr || head->next == nullptr) {
			return false;
		
		}

		// 创建快慢指针
		ListNode* ptr_fast = head->next;
		ListNode* ptr_slow = head;

		// 进行不同步长的遍历
		while (ptr_fast != ptr_slow) {
			if (ptr_fast != nullptr || ptr_fast->next != nullptr) { //判断只有当前和下一级，如果是最后两个节点，ptr_fast->next->next是空
				ptr_fast = ptr_fast->next->next;
				ptr_slow = ptr_slow->next;
			}
			else {
				return false;
			}

		}
		return true;

	
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

	if (solution.solution(head)) {
		cout << "是环形链表" << endl;
	
	}
	else {
		cout << "不是环形链表" << endl;
	}



}



#endif
