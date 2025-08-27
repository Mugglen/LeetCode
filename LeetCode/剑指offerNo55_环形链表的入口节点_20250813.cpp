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

// 写错了，注意看下面的Solution类才是对的
class Solution_fault {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        // 双指针
		ListNode* slow = pHead;
		ListNode* fast = pHead;
        if (fast && fast->next) {
            fast = fast->next->next;
            // ！！！！！！！！！就这里，擅自把fast步进了，但是slow没有步进
            // 最后导致他们在最后一个while循环的环中永远不会相遇
            // slow = slow->next;
        }
		else return nullptr;

        while (slow != fast) {
			slow = slow->next;
            if(fast->next) fast = fast->next->next;
			else return nullptr;
        }
		// 找到相遇点后，慢指针从头开始走，快指针不动
		slow = pHead;
        while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
        }
		return slow; // 返回相遇点
    }


};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head, * fast = head;
        // 寻找相遇点（其实用原来的while(true)，把判断写在while里还更好理解一些）
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr; // 无环

        // 从头与相遇点同时一步步走，汇合处即入口
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

#endif // DEBUG1