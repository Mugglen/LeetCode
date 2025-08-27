#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x = 0, ListNode* ptr = nullptr) : val(x), next(ptr) {}
};

class SolutionLF
{

public:
	// �����������ˣ����������ʱ�򱨴��ˣ���֪��Ϊɶ��ȡ����vector����������������
	ListNode* sortList_violence(ListNode* head) {
		
		// �쳣ֵ�����գ�
		if (head == nullptr) return head;

		// ����vector�洢����ֵ
		vector<int> vals;

		// ��ʱָ��
		ListNode* curr = head;

		// ��������
		while (curr != nullptr) {
			vals.push_back(curr->val);
			curr = curr->next;
			
		}

		// �ͷ��ڴ�
		curr = head;
		while (curr != nullptr) {
			ListNode* temp = curr;
			curr = curr->next;
			delete temp;  // �ͷŵ�ǰ�ڵ���ڴ�
		}

		// ����
		sort(vals.begin(), vals.end());

		// ����������ͷ
		ListNode* headSort = new ListNode();

		// ������ʱָ��
		curr = headSort;

		for (int i : vals) {
			if (curr == nullptr) continue;
			curr->val = i;

			// ����������ע������߽紦����⵽�����һ��val����Ҫ��nullptr
			curr->next = i != vals.back() ? new ListNode() : nullptr;
			curr = curr->next;
			

		}
		return headSort;
	}

	void vectorDebug(vector<int> vals) {
		for (int i : vals) {
			cout << i << ' ' << endl;
		
		}
	
	}
	
	// ��Ҫѧϰһ�¹鲢


};

//���ߣ����ɽ����
//���ӣ�https ://leetcode.cn/problems/sort-list/solutions/2993518/liang-chong-fang-fa-fen-zhi-die-dai-mo-k-caei/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

// �鲢���򣨷��Σ�
class Solution {
	// 876. ������м��㣨����ָ�룩
	ListNode* middleNode(ListNode* head) {
		ListNode* pre = head;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			pre = slow; // ��¼ slow ��ǰһ���ڵ�
			slow = slow->next;
			fast = fast->next->next;
		}
		// ע������˶Ͽ�
		pre->next = nullptr; // �Ͽ� slow ��ǰһ���ڵ�� slow ������
		return slow;
	}

	// 21. �ϲ�������������˫ָ�룩
	// �ڱ��ڵ�ʹ�ô�����������ĺϲ���ø���ͳһ�������˶����ָ��ļ�顣
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

		// ���Ϸ����ڱ��������dummy���ǽṹ��ָ���ˣ�
		//ListNode* dummy = new ListNode();
		//ListNode* curr = dummy;

		// ջ�Ϸ����ڱ�
		ListNode dummy; // ���ڱ��ڵ�򻯴����߼���ע������Ǹ��ṹ�壩
		ListNode* cur = &dummy; // cur ָ���������ĩβ

		// �ֱ�Ƚ���������ڵ��ֵ��С��ժ���������ڱ����棬Ȼ���ƶ�ԭ����ָ��
		while (list1 && list2) {
			if (list1->val < list2->val) {
				cur->next = list1; // �� list1 �ӵ���������
				list1 = list1->next;
			}
			else { // ע����ȵ�������ĸ��ڵ㶼�ǿ��Ե�
				cur->next = list2; // �� list2 �ӵ���������
				list2 = list2->next;
			}
			// �������������ƶ��ڱ������β�ͽڵ�ָ��
			cur = cur->next;
		}

		// ���������ȳ��������������������
		cur->next = list1 ? list1 : list2; // ƴ��ʣ������
		return dummy.next;
	}

public:
	ListNode* sortList(ListNode* head) {
		// �������Ϊ�ջ���ֻ��һ���ڵ㣬��������
		if (head == nullptr || head->next == nullptr) {
			return head;
		}
		// �ҵ��м�ڵ� head2�����Ͽ� head2 ����ǰһ���ڵ������
		// ���� head=[4,2,1,3]����ô middleNode ���ý����� head=[4,2] head2=[1,3]
		ListNode* head2 = middleNode(head);
		// ����
		head = sortList(head);
		head2 = sortList(head2);
		// �ϲ�
		return mergeTwoLists(head, head2);
	}
};

//#define DEBUG
#ifdef DEBUG

int main() {


return 0;
}

#endif // DEBUG
