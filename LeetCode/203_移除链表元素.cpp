


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {

public:
	ListNode* removeElements(ListNode* head, int val) {

		// �쳣��������Ϊ��ʱ����(���������ѭ������)
		//if (head == nullptr) return head;

		
		// �����ڱ�
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		// ����˫ָ��
		ListNode* left = dummy;
		ListNode* right = head;

		// ѭ������
		while (right != nullptr) {
			// �ж�ֵ
			if (right->val == val) {
				// �ǵ��ͷ��ҵ��Ľڵ�
				ListNode* temp = right;
				right = right->next;
				left->next = left->next->next;
				delete temp;
				// �����и�������Ҫɾ����ֵ�����ﲻ����

			}
			else {
				//��������
				right = right->next;
				left = left->next;
			}
		}

		// ��������ϣ�û�ҵ����߶�ɾ���ˣ���������ͷ
		
		// �ͷ��ڱ�
		ListNode* result = dummy->next;
		delete dummy;
		return result;

		// ע�����д��
		/*ListNode* temp = dummy;
		delete dummy;
		return temp->next;*/
		
	
	}


};