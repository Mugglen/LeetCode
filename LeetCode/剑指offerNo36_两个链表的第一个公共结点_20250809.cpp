#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		// �쳣
		if (pHead1 == nullptr || pHead2 == nullptr) return nullptr;
		// ȷ��������
		ListNode* cur1 = pHead1;
		ListNode* cur2 = pHead2;
		int len1 = 0, len2 = 0;
		while (cur1) {
			len1++;
			cur1 = cur1->next;
		}
		while (cur2) {
			len2++;
			cur2 = cur2->next;
		}
		// ָ��cur1Ϊ������
		cur1 = pHead1;
		cur2 = pHead2;
		if (len1 < len2) {
			swap(len1, len2);
			swap(cur1, cur2);
		}
		// ��cur1��len1 - len2��
		for (int i = 0; i < len1 - len2; ++i) {
			cur1 = cur1->next;
		}
		// ����ͬʱ����
		while (cur1 != nullptr && cur2 != nullptr) {
			if (cur1 == cur2) return cur1;
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return nullptr; // û�й������
	}
};


#endif // DEBUG1