#include "stddef.h"

//#define DEBUG
#ifdef DEBUG

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// https://leetcode.cn/problems/linked-list-cycle-ii/solutions/12616/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		
		// 创建快慢指针
		ListNode* slow = head;
		ListNode* fast = head;

		// 第一次循环
		while (true) {
			if (fast == nullptr || fast->next == nullptr)return nullptr; // 处理无环
			fast = fast->next->next; // 快指针每次走两步
			slow = slow->next; // 慢指针每次走一步
			if (slow == fast)break; // 如果相遇了，说明有环
		}

		// 第二次循环，找到环的入口
		fast = head; // 将快指针重置到头节点
		while (slow != fast) {
			slow = slow->next; // 慢指针每次走一步
			fast = fast->next; // 快指针每次走一步
		}

		return fast;
	}
};
#endif // DEBUG
