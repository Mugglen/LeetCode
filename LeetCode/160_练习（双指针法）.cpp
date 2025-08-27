#include <iostream>
using namespace std;

// 定义链表
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		// 创建双指针
		ListNode*  curA = headA;
		ListNode* curB = headB;
		int lenA = 0, lenB = 0;
		//求链表长度
		while (curA != NULL) {
			lenA++;
			curA = curA->next;
		}

		while (curB != NULL) {
			lenB++;
			curB = curB->next;
		}

		// 重置链表指针(不要漏掉)
		curA = headA;
		curB = headB;
		
		//指定长链表指针（要先将指针重置到表头）
		if (lenB > lenA) {
			swap(lenA, lenB);
			swap(curA, curB);

		}

		//对齐链表指针
		int gap = lenA - lenB;
		while (gap--) {
			curA = curA->next;
		}

		// 分别递增
		while (curA != NULL) {
			if (curA == curB) {
				return curA;
			}
			else {
				curA = curA->next;
				curB = curB->next;
			}
		}

		// 没有交点
		return NULL;
	}
};

//#define DEBUG
#ifdef DEBUG
int main() {
	// 创建链表
	ListNode* headA = new ListNode(1); // new 用于在堆上分配内存，而不是在栈上。
	// （如果使用栈上分配，ListNode headA(1);的 headA 是一个局部变量，会在当前作用域结束时被销毁。）
	headA->next = new ListNode(2);
	headA->next->next = new ListNode(3);
	headA->next->next->next = new ListNode(4);
	headA->next->next->next->next = new ListNode(5);

	// 创建链表B
	ListNode* headB = new ListNode(6);
	headB->next = new ListNode(7);
	headB->next->next = new ListNode(8);
	headB->next->next->next = headA->next->next->next; // 链表B与链表A在节点4相交

	Solution solution;
	ListNode* intersectionNode = solution.getIntersectionNode(headA, headB);

	// 输出结果
	if (intersectionNode != NULL) {
		cout << "交点的值为" << intersectionNode->val << endl;
	}
	else {
		cout << "链表没有交点" << endl;
	}

	// 手动释放内存（注意需要倒序释放，否则会造成指针悬空）
	delete headA->next->next->next->next;
	delete headA->next->next->next;
	delete headA->next->next;
	delete headA->next;
	delete headA;

	delete headB->next->next->next;
	delete headB->next->next;
	delete headB->next;
	delete headB;

	return 0;

}
#endif // DEBUG
