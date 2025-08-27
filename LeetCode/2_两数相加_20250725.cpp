


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

        // 加数本身已经逆序，直接加
        ListNode* dummy = new ListNode(-1, nullptr);
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* cur3 = dummy;
		int cin = 0; // 进位

        // 注意进位
        while (cur1 || cur2 || cin) {

			// 注意加这一层取值，来规避空指针异常
			int val1 = cur1 ? cur1->val : 0;
            int val2 = cur2 ? cur2->val : 0;
            int sum = val1 + val2 + cin;
            
            // 判断下次进位
            cin = sum >= 10 ? 1 : 0;

			// 新建节点存储运算结果
			cur3->next = new ListNode(sum % 10, nullptr);

            // 注意并不需要分cin讨论下一个节点的val是sum % 10和是sum，sum % 10就包含了两种情况

            // 统一移动指针
            cur1 = cur1 ? cur1->next : nullptr;
            cur2 = cur2 ? cur2->next : nullptr;
            cur3 = cur3->next;
        }
		// 返回表头指针备份
		ListNode* result = dummy->next;
        delete dummy; // 释放哨兵节点的内存
		return result;
    }
};


#endif // DEBUG
