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
	// ��������ʹ����ָ�룬ָ��ֵͬ�ĵ�һ���ڵ��ǰһ�������һ���ڵ�
    ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;

        // ��һ���ڵ�Ҳ�п��ܱ�ɾ���������ڱ�
		ListNode* dummy = new ListNode(-1);
		dummy->next = pHead; // !!!!!!!!!ע�⣬���Ҫ���ӵ��ڱ��ϣ������������˺ü�����
        ListNode* pre = dummy;
        ListNode* cur = pHead;
		ListNode* next = pHead->next;

        while (next) {
            // ��Ⱦ�ֱ��ɾ��(�������ֱ��ɾ��û�����Ԫ��)
            if (cur->val == next->val) {
				// ��cur�ض���ȫɾ��
                while (next && next->val == cur->val) {
					ListNode* temp = next;
					cur->next = next->next; // ɾ����ǰ�ڵ�(ע�⣡��������˳��)
					next = next->next; // ������һ���ڵ�(ע�⣡��������˳�򣬺������Ǿ䷴������ԭ��)
					delete temp; // ɾ����ǰ�ڵ�
                }
				// ��ʣ��curҪɾ��
				ListNode* temp2 = cur;
				pre->next = next; // ǰһ��ָ����һ��
				cur = next; // ��ǰָ��ǰ��
				next = next ? next->next : nullptr; // ��ע���ָ�жϣ�������һ��ָ��!!!ע��nextҪ��һ������Ȼcur��next��ָ��ͬһ���½ڵ㣬���ǵ�ֵ�϶����
				delete temp2;
			}
			else { // �����
				pre = cur; // ǰһ��ָ��ǰ��
				cur = next; // ��ǰָ��ǰ��
				next = next->next; // ������һ��ָ��
            }
        }
		ListNode* ans = dummy->next; // �ڱ�����һ���ڵ���Ǵ�
		delete dummy; // ɾ���ڱ�
		return ans;
    }
};


#endif // DEBUG1