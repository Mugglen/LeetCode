#include <vector>
#include <queue>
using namespace std;

// 最小堆（Min Heap）是一种特殊的基于完全二叉树的数据结构，它满足一个关键性质：​堆序性质。
// 简单来说，最小堆保证每一个父节点的值都小于或等于其所有子节点的值。
// 这意味着整棵树中最小的元素总是位于根节点（堆顶）​。


//std::priority_queue<Type, Container, Compare>


//#define DEBUG
#ifdef DEBUG

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int val, ListNode* next) :val(val), next(next) {};

};

class Solution {

public:
	ListNode* mergeKlists(vector<ListNode*>& lists) {
	
		// 创建比较器
		// 这是一个比较函数，返回true表示a的优先级低于b
		auto cmp = [](const ListNode* a, const ListNode* b) {
			return a->val > b->val;
			};
		
		// 指定大的为true，所以小元素在堆顶
		priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;

		for (auto head : lists) {
			if (head) {
				pq.push(head); //把所有非空链表的头节点入堆
			}
		}
		
		// 栈上创建，合并后作为链表头节点的前一个节点
		ListNode dummy(-1,nullptr);

		auto cur = &dummy;

		while (!pq.empty()) { // 循环直到堆为空
			auto node = pq.top();
			pq.pop();

			if (node->next) {
				pq.push(node->next); // 推入当前最小节点的后一个，和其他头节点比较
			}

			// 移动链接指针
			cur->next = node;
			cur = cur->next;
		
		
		}
		return dummy.next;
		
	}

};



#endif // DEBUG

