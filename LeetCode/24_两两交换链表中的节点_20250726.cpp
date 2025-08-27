


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

    // 反装链表
    ListNode* reverseList(ListNode* head) {

        // 辅助指针
        ListNode* pre = nullptr;
        ListNode* cur = head;
		ListNode* next = nullptr;

        while (cur) {
			next = cur->next; // 先保存下一个节点
            cur->next = pre;
            pre = cur; // 更新前一个节点
			cur = next; // 移动到下一个节点
        }
		return pre; // 返回新的头节点

    }

    ListNode* swapPairs(ListNode* head) {

        // 两个一组反转链表，先处理不到2个节点的情况
        if (!head || !head->next)return head; 

        // 没说要不要处理奇数个节点，先写
		ListNode* dummy = new ListNode(-1, head);

        // 辅助指针
        ListNode* pre = dummy;
		ListNode* node1 = head;
        ListNode* node2 = head->next;
		ListNode* next = head->next->next;

		// 交换节点
        while (node1 && node2) {
            
            //先断链
            node2->next = nullptr;
            // 交换
			reverseList(node1);
			// 连接
			pre->next = node2; // 前一个节点指向尾节点
            node1->next = next; // 当前节点指向下一个节点
            // 移动
            if (next) {
				pre = node1; // 前一个节点移动到当前节点
				node1 = next; // 当前节点移动到下一个节点
				node2 = next->next; // 下一个节点移动到下一个的下一个节点
				next = next->next ? next->next->next : nullptr; // 下下个节点
            }
            else { // 注意，后面没了还是要更新node1合node2
                node1 = nullptr;
                node2 = nullptr;
            }
        }
		ListNode* ans = dummy->next; // 返回新的头节点
        delete dummy; // 释放哑节点
		return ans;

    }
};
#endif // DEBUG
