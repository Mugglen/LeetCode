#include <string>
#include <sstream>
#include <iostream>

using namespace std;



struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x = -1, ListNode* ptr = nullptr) : val(x), next(ptr) {}
};

// 方法1：计算链表长度(时间复杂度O(L)，空间复杂度O(L))
// 方法2：栈（时间复杂度O(L)，空间复杂度O(L)）
// 方法3：双指针（时间复杂度O(L)，空间复杂度O(1)第一个出现在脑子里的）

class Solution
{
public:

	// 传入的就是链表表头，所以哑节点dummy还是得在方法里创建
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummy = new ListNode(-1, head);

		// 初始化双指针
		ListNode* first = head;
		ListNode* second = dummy; // 注意second等于dummy，这样first步进后，在最后second会指向倒数第n个节点的前一个

		// 注意！！！for循环里就前两个要加分号，不要老是写成逗号
		// 题目规定确认了n不会超过链表的长度
		for (int i = 0; i < n; i++) {
			// 步进长度为n
			first = first->next;
		}

		// 快慢指针相差n个节(慢指针需要走n+1步到快指针的位置)，开始同时步进
		while (first) {
			first = first->next;
			second = second->next;
		}

		// 快指针走到底，慢指针直接跳过后一个节点
		second->next = second->next->next;
		
		// 为了释放dummy空间，整个ans保存表头
		ListNode* ans = dummy->next;
		delete dummy;
		return ans;

	}

	void buildList(ListNode*& listHead1) {

		// 第一行输入处理
		string line1;
		getline(cin, line1);
		stringstream ss1(line1);
		string token1;
		ListNode* curr1 = listHead1;
		while (getline(ss1, token1, ',')) {
			//!!!! 注意原来的错误写法，都已经声明curr了但是没用着
			//listHead1->next = new ListNode(stoi(token1)); 
			curr1->next = new ListNode(stoi(token1));
			curr1 = curr1->next;
		}
	}

};

//#define DEBUG
#ifdef DEBUG

int main() {

	Solution solution;

	ListNode* dummy = new ListNode();

	solution.buildList(dummy);

	int n;
	cin >> n;

	solution.removeNthFromEnd(dummy->next, n);

	ListNode* curr = dummy->next;

	cout << "删除后的链表为：";
	while (curr) {

		cout << curr->val << ' ';
		curr = curr->next;
	}



	return 0;
}


#endif // DEBUG
