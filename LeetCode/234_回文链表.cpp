// ��ֵ���Ƶ������к���˫ָ�뷨��
// ������������һ��ָ�룬�ڽ�β����һ��ָ�룬ÿһ�ε����ж�����ָ��ָ���Ԫ���Ƿ���ͬ��

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};


class solution {
public:
	bool isPlindrome(ListNode* head) {
		// �������飬ȡ������Ԫ��
		vector<int> vals_array;
		while (head != NULL) {
			vals_array.emplace_back(head->val);
		}

		// ˫ָ��Ա�
		for (int i = 0, j = vals_array.size() - 1; i < j; ++i, --j) {
			if (vals_array[i] != vals_array[j]) {
				return false;// ƴд����,����faulse
			}
		}

		
		return true; 
	}
};

//#define DEBUG
#ifdef DEBUG

int main() {

	solution solution;

	// �����б�
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(1);

	if (solution.isPlindrome(head)) {
		cout << "�ǻ�������" << endl;
	}
	else {
		cout << "���ǻ�������" << endl; // д���ˣ�����>>���������������
	}



	return 0;
}
#endif // DEBUG
