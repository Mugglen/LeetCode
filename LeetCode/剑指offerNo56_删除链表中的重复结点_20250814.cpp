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
	// 链表有序，使用三指针，指向同值的第一个节点的前一个和最后一个节点
    ListNode* deleteDuplication(ListNode* pHead) {
		if (pHead == nullptr) return nullptr;

        // 第一个节点也有可能被删除，创建哨兵
		ListNode* dummy = new ListNode(-1);
		dummy->next = pHead; // !!!!!!!!!注意，这个要链接到哨兵上！！！！！错了好几次了
        ListNode* pre = dummy;
        ListNode* cur = pHead;
		ListNode* next = pHead->next;

        while (next) {
            // 相等就直接删除(排序过了直接删到没有这个元素)
            if (cur->val == next->val) {
				// 和cur重读的全删了
                while (next && next->val == cur->val) {
					ListNode* temp = next;
					cur->next = next->next; // 删除当前节点(注意！！！操作顺序)
					next = next->next; // 保存下一个节点(注意！！！操作顺序，和上面那句反过来了原来)
					delete temp; // 删除当前节点
                }
				// 还剩个cur要删除
				ListNode* temp2 = cur;
				pre->next = next; // 前一个指向下一个
				cur = next; // 当前指针前进
				next = next ? next->next : nullptr; // （注意空指判断）更新下一个指针!!!注意next要走一步，不然cur和next会指向同一个新节点，他们的值肯定相等
				delete temp2;
			}
			else { // 不相等
				pre = cur; // 前一个指针前进
				cur = next; // 当前指针前进
				next = next->next; // 更新下一个指针
            }
        }
		ListNode* ans = dummy->next; // 哨兵的下一个节点就是答案
		delete dummy; // 删除哨兵
		return ans;
    }
};


#endif // DEBUG1