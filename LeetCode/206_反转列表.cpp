#include <iostream>
using namespace std;

struct ListNode {
	int value;
	ListNode* next;
	// ʹ�ó�Ա��ʼ���б�
	ListNode(int x) : value(x), next(NULL) {}// ע����int x���ǵ�����x��ע�⹹�캯��β����{}����
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// ������ָ�루ǰһ���ڵ㣬��ǰ�ڵ㣬��һ���ڵ㣩
		// ��Ҫ��������ʼ����ǰ�ڵ㣬ǰһ���ڵ㣬Ȼ�󱣴����һ���ڵ��
		// �Ͱ���һ���ڵ��滻��ǰһ���ڵ㣬ǰһ���ڵ��滻�ɵ�ǰ�ڵ㣬��ǰ�ڵ��滻����һ���ڵ�

		// �����δ��ת�ڵ�ı�ͷ��һ�η�תһ���ڵ㣬Ȼ���ƶ�pre��curr
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr != NULL) {
			ListNode* next_temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next_temp;
		}
		// ����������ķ�ת�Ľڵ㣨�����������һ���ڵ㣩��ָ�룬��Ϊ��ת��ı�ͷ�����Ƿ���curr��curr���Ϊ��
		return prev;
	}
};


//#define DEBUG
#ifdef DEBUG


int main() {
	// ��������
	ListNode* head = new ListNode(1); // ע��ʹ��new����������new�ķ���ֵ���Ǵ��������ָ��
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);

	//������ת����
	Solution solution;

	// ʹ�÷���
	ListNode* head_reverse = solution.reverseList(head);

	ListNode* ptr_temp = head_reverse;
	cout << "��ת�б��ֵ" << endl;
	while (ptr_temp-> next != NULL) {
		cout  << ptr_temp->value << endl;
		ptr_temp = ptr_temp->next;
	}
	cout << ptr_temp->value << endl; // ע�����һ���ڵ��next����NULL�ˣ�����Ҫ������ӡ

	ptr_temp = head_reverse;
	while (ptr_temp != NULL) {
		cout << ptr_temp->value << endl;
		ptr_temp = ptr_temp->next;
	}
	 // ע�������ſ���ֱ�ӱ�������
}
#endif // DEBUG
