#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	// 就是把二叉搜索树的中序遍历变成双链表
	TreeNode* Convert(TreeNode* pRootOfTree) {
		// 特判(记得特判)
		if (pRootOfTree == nullptr) return nullptr;
		// 中序遍历，但是保存节点指针(这种初始化也不能代替特判，因为下面是push_back进来的)
		//vector<TreeNode*> inOrder(1,nullptr);
		vector<TreeNode*> inOrder;

		function<void(TreeNode*)> traversal = [&](TreeNode* node) {

			// 递归终止
			if (node == nullptr) return;
			// 中序
			traversal(node->left);
			inOrder.push_back(node);
			traversal(node->right);
			return;
			};
		// 启动递归
		traversal(pRootOfTree);
		// 按顺序重新链接节点
		for (int i = 0; i < inOrder.size(); ++i) {
			// 头节点前面为空（包含单节点情况）
			if (i == 0) {
				inOrder[i]->left = nullptr;
				inOrder[i]->right = inOrder[i+1];
			}
			// 尾节点后面为空(和单节点情况区分开)
			else if (i == inOrder.size() - 1 && i != 0) {
				inOrder[i]->left = inOrder[i-1];
				inOrder[i]->right = nullptr;
			}
			else {
				inOrder[i]->left = inOrder[i - 1];
				inOrder[i]->right = inOrder[i + 1];
			}
		}
		return inOrder[0];
	}
};



#endif // DEBUG1

// 使用栈进行辅助，感觉是迭代法中序遍历的改进，没有看的很懂。
//#define DEBUG2
#ifdef DEBUG2

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/26-%E5%89%91%E6%8C%87offer.html
	// 采用剑指offer上一样的写法
	// 明确Convert函数的功能。输入：一个二叉搜索树的根节点。过程：将其转化为一个有序的双向链表。输出：返回该链表的头节点。
	// 明确成员变量pLast的功能：用于记录当前链表末尾节点
	// 明确递归过程。递归的过程就相当于按照中序遍历，
	// 将整个树分解成了无数的小树，然后将他们分别转化成了一小段一小段的双向链表。
	// 再利用pLast记录总的链表的末尾，最后将这些小段链表一个接一个地加到末尾。
	TreeNode* Convert(TreeNode* pRootOfTree) {
		TreeNode* head = nullptr; // head 输出
		TreeNode* pre = nullptr;// 记录上一次出栈值
		stack<TreeNode*> st; // 使用栈辅助

		while (pRootOfTree || !st.empty()) {
			while (pRootOfTree != nullptr) {
				st.push(pRootOfTree);
				pRootOfTree = pRootOfTree->left;
			}
			if (!st.empty()) {
				pRootOfTree = st.top();
				st.pop();
				if (pre != nullptr) {
					pre->right = pRootOfTree;
					pRootOfTree->left = pre;
				}
				else { // pre为空，表示st第一次出栈， 第一次出栈值为最左值，即输出值
					head = pRootOfTree;
				}
				pre = pRootOfTree;
				pRootOfTree = pRootOfTree->right;
			}
		}
		return head;
	}
};

#endif // DEBUG2