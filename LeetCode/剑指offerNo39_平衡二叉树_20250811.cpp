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

struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 这题只判断二叉树是否平衡，不保证有序。
// 同时注意，左右子树也得是平衡的。
class Solution {
public:

    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        // 后序
		int leftHeight = height(root->left);
		int rightHeight = height(root->right);
		return max(leftHeight, rightHeight) + 1;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
        // 空树
		if (pRoot == nullptr) return true;
		// 先求左右子树高度
		int leftHeight = height(pRoot->left);
		int rightHeight = height(pRoot->right);
		// 判断高度差
		if ((abs(leftHeight - rightHeight) <= 1) &&
			(IsBalanced_Solution(pRoot->left)) && 
			(IsBalanced_Solution(pRoot->right))){
			return true; // 高度差小于等于1，且左右子树平衡，整体平衡
		}
		else {
			return false;
		}
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/39-%E5%89%91%E6%8C%87offer.html
// 这里采用阿秀的第二种方法，从下往上遍历树，这样每个节点至多访问一次，不会像方法一一样节点会被遍历多次
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 这题只判断二叉树是否平衡，不保证有序。
// 同时注意，左右子树也得是平衡的。
//方法2的优点（DEBUG2）：
//1.自底向上的方法​：你在计算高度的同时检查平衡性，一旦发现不平衡就直接返回 - 1，不再继续不必要的计算。
//2.无重复计算​：每个节点只被访问一次，因为高度是在递归返回时计算的，并且不平衡的情况会立即传播到上层。
//3.时间复杂度优化​：这种方法的时间复杂度是O(n)，因为每个节点只被处理一次。
//4.提前终止​：只要发现任何子树不平衡，整个计算就会立即终止并返回结果，不需要继续检查其他部分。
class Solution {
public:
	int getDepth(TreeNode* node) {
		if (node == nullptr) return 0; // 空节点深度为0
		int leftDepth = getDepth(node->left); // 左子树深度
		if (leftDepth == -1) return -1; // 左子树不平衡，直接返回-1
		int rightDepth = getDepth(node->right); // 右子树深度
		if (rightDepth == -1) return -1; // 右子树不平衡，直接返回-1
		
		if (abs(leftDepth - rightDepth) > 1) return -1;
		else return 1 + max(leftDepth, rightDepth);
	}


	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr) return true;
		return getDepth(pRoot) != -1; // 如果返回-1，说明不平衡
	}
};

#endif // DEBUG2