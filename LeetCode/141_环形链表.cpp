// ʹ�ÿ���ָ�뷨�����Ƕ�������ָ�룬һ��һ������ָ��ÿ��ֻ�ƶ�һ��������ָ��ÿ���ƶ�������

#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}

};


// ʱ�临�Ӷ�O(N)
// �ռ临�Ӷ�O(1)
class Solution {
public:
	bool solution(ListNode* head) {
	// �����
		if ( head == nullptr || head->next == nullptr) {
			return false;
		
		}

		// ��������ָ��
		ListNode* ptr_fast = head->next;
		ListNode* ptr_slow = head;

		// ���в�ͬ�����ı���
		while (ptr_fast != ptr_slow) {
			if (ptr_fast != nullptr || ptr_fast->next != nullptr) { //�ж�ֻ�е�ǰ����һ�����������������ڵ㣬ptr_fast->next->next�ǿ�
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
		cout << "�ǻ�������" << endl;
	
	}
	else {
		cout << "���ǻ�������" << endl;
	}



}



#endif
