


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {

public:
	ListNode* removeElements(ListNode* head, int val) {

		// 异常处理，链表为空时返回(好像包含在循环里了)
		//if (head == nullptr) return head;

		
		// 创建哨兵
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;

		// 创建双指针
		ListNode* left = dummy;
		ListNode* right = head;

		// 循环步进
		while (right != nullptr) {
			// 判断值
			if (right->val == val) {
				// 记得释放找到的节点
				ListNode* temp = right;
				right = right->next;
				left->next = left->next->next;
				delete temp;
				// 可能有复数个需要删除的值，这里不返回

			}
			else {
				//继续步进
				right = right->next;
				left = left->next;
			}
		}

		// 整表处理完毕，没找到或者都删完了，返回链表头
		
		// 释放哨兵
		ListNode* result = dummy->next;
		delete dummy;
		return result;

		// 注意错误写法
		/*ListNode* temp = dummy;
		delete dummy;
		return temp->next;*/
		
	
	}


};