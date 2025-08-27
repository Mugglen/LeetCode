#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;

// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/solutions/144306/mian-shi-ti-26-shu-de-zi-jie-gou-xian-xu-bian-li-p/
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
	// 注意题目输入的是树，不是树的层次遍历，不要理解错了
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

		// 空树
		if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
		// 是子结构的三种情况,当前传入的两个根节点是同一颗树 || 节点1的左子树和节点2为根的树是同一颗树 || 节点1的右子树和节点2为根的树是同一颗树
		if (compareTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2)) {
			return true;
		}
		// 注意加上这行，不然return 都包在if里会报错
		return false;

		// 这样写简洁一点
		// return (pRoot1 != nullptr && pRoot2 != nullptr) && (compareTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));

	}

	// 递归判断以当前节点A为根的树和B为根的树，两棵树是不是相等的
	bool compareTree(TreeNode* nodeA, TreeNode* nodeB) {
		// 递归比到B的叶子之后了，表示该支路匹配完毕
		if (nodeB == nullptr) return true;
		if (nodeA == nullptr || nodeA->val != nodeB->val) return false;
		return (compareTree(nodeA->left, nodeB->left) && compareTree(nodeA->right, nodeB->right));
	}
};



#endif // DEBUG1