


//#define DEBUG
#ifdef DEBUG

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // ���������Ѿ�����ֱ�Ӽ�
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* cur3 = dummy;
		int cin = 0; // ��λ

        // ע���λ
        while (cur1 || cur2 || cin) {

			// ע�����һ��ȡֵ������ܿ�ָ���쳣
			int val1 = cur1 ? cur1->val : 0;
            int val2 = cur2 ? cur2->val : 0;
            int sum = val1 + val2 + cin;
            
            // �ж��´ν�λ
            cin = sum >= 10 ? 1 : 0;

			// �½��ڵ�洢������
			cur3->next = new ListNode(sum % 10, nullptr);

            // ע�Ⲣ����Ҫ��cin������һ���ڵ��val��sum % 10����sum��sum % 10�Ͱ������������

            // ͳһ�ƶ�ָ��
            cur1 = cur1 ? cur1->next : nullptr;
            cur2 = cur2 ? cur2->next : nullptr;
            cur3 = cur3->next;
        }
		// ���ر�ͷָ�뱸��
		ListNode* result = dummy->next;
        delete dummy; // �ͷ��ڱ��ڵ���ڴ�
		return result;
    }
};


#endif // DEBUG
