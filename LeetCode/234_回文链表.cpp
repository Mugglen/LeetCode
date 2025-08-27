// 将值复制到数组中后用双指针法，
// 我们在起点放置一个指针，在结尾放置一个指针，每一次迭代判断两个指针指向的元素是否相同。

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};


class solution {
public:
	bool isPlindrome(ListNode* head) {
		// 创建数组，取出链表元素
		vector<int> vals_array;
		while (head != NULL) {
			vals_array.emplace_back(head->val);
		}

		// 双指针对比
		for (int i = 0, j = vals_array.size() - 1; i < j; ++i, --j) {
			if (vals_array[i] != vals_array[j]) {
				return false;// 拼写错误,不是faulse
			}
		}

		
		return true; 
	}
};

//#define DEBUG
#ifdef DEBUG

int main() {

	solution solution;

	// 创建列表
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(1);

	if (solution.isPlindrome(head)) {
		cout << "是回文链表" << endl;
	}
	else {
		cout << "不是回文链表" << endl; // 写反了，不是>>，是向左输出的流
	}



	return 0;
}
#endif // DEBUG
