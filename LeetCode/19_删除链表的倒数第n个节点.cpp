#include <string>
#include <sstream>
#include <iostream>

using namespace std;



struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x = -1, ListNode* ptr = nullptr) : val(x), next(ptr) {}
};

// ����1������������(ʱ�临�Ӷ�O(L)���ռ临�Ӷ�O(L))
// ����2��ջ��ʱ�临�Ӷ�O(L)���ռ临�Ӷ�O(L)��
// ����3��˫ָ�루ʱ�临�Ӷ�O(L)���ռ临�Ӷ�O(1)��һ��������������ģ�

class Solution
{
public:

	// ����ľ��������ͷ�������ƽڵ�dummy���ǵ��ڷ����ﴴ��
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(-1, head);

		// ��ʼ��˫ָ��
		ListNode* first = head;
		ListNode* second = dummy; // ע��second����dummy������first�����������second��ָ������n���ڵ��ǰһ��

		// ע�⣡����forѭ�����ǰ����Ҫ�ӷֺţ���Ҫ����д�ɶ���
		// ��Ŀ�涨ȷ����n���ᳬ������ĳ���
		for (int i = 0; i < n; i++) {
			// ��������Ϊn
			first = first->next;
		}

		// ����ָ�����n����(��ָ����Ҫ��n+1������ָ���λ��)����ʼͬʱ����
		while (first) {
			first = first->next;
			second = second->next;
		}

		// ��ָ���ߵ��ף���ָ��ֱ��������һ���ڵ�
		second->next = second->next->next;
		
		// Ϊ���ͷ�dummy�ռ䣬����ans�����ͷ
		ListNode* ans = dummy->next;
		delete dummy;
		return ans;

	}

	void buildList(ListNode*& listHead1) {

		// ��һ�����봦��
		string line1;
		getline(cin, line1);
		stringstream ss1(line1);
		string token1;
		ListNode* curr1 = listHead1;
		while (getline(ss1, token1, ',')) {
			//!!!! ע��ԭ���Ĵ���д�������Ѿ�����curr�˵���û����
			//listHead1->next = new ListNode(stoi(token1)); 
			curr1->next = new ListNode(stoi(token1));
			curr1 = curr1->next;
		}
	}

};

//#define DEBUG
#ifdef DEBUG

int main() {

	Solution solution;

	ListNode* dummy = new ListNode();

	solution.buildList(dummy);

	int n;
	cin >> n;

	solution.removeNthFromEnd(dummy->next, n);

	ListNode* curr = dummy->next;

	cout << "ɾ���������Ϊ��";
	while (curr) {

		cout << curr->val << ' ';
		curr = curr->next;
	}



	return 0;
}


#endif // DEBUG
