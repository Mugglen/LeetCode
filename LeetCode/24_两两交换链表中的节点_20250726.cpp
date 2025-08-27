


//#define DEBUG
#ifdef DEBUG


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:

    // ��װ����
    ListNode* reverseList(ListNode* head) {

        // ����ָ��
        ListNode* pre = nullptr;
        ListNode* cur = head;
		ListNode* next = nullptr;

        while (cur) {
			next = cur->next; // �ȱ�����һ���ڵ�
            cur->next = pre;
            pre = cur; // ����ǰһ���ڵ�
			cur = next; // �ƶ�����һ���ڵ�
        }
		return pre; // �����µ�ͷ�ڵ�

    }

    ListNode* swapPairs(ListNode* head) {

        // ����һ�鷴ת�����ȴ�����2���ڵ�����
        if (!head || !head->next)return head; 

        // û˵Ҫ��Ҫ�����������ڵ㣬��д
		ListNode* dummy = new ListNode(-1, head);

        // ����ָ��
        ListNode* pre = dummy;
		ListNode* node1 = head;
        ListNode* node2 = head->next;
		ListNode* next = head->next->next;

		// �����ڵ�
        while (node1 && node2) {
            
            //�ȶ���
            node2->next = nullptr;
            // ����
			reverseList(node1);
			// ����
			pre->next = node2; // ǰһ���ڵ�ָ��β�ڵ�
            node1->next = next; // ��ǰ�ڵ�ָ����һ���ڵ�
            // �ƶ�
            if (next) {
				pre = node1; // ǰһ���ڵ��ƶ�����ǰ�ڵ�
				node1 = next; // ��ǰ�ڵ��ƶ�����һ���ڵ�
				node2 = next->next; // ��һ���ڵ��ƶ�����һ������һ���ڵ�
				next = next->next ? next->next->next : nullptr; // ���¸��ڵ�
            }
            else { // ע�⣬����û�˻���Ҫ����node1��node2
                node1 = nullptr;
                node2 = nullptr;
            }
        }
		ListNode* ans = dummy->next; // �����µ�ͷ�ڵ�
        delete dummy; // �ͷ��ƽڵ�
		return ans;

    }
};
#endif // DEBUG
