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

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
// 牛客上有一组用例没通过，感觉不是我的问题，可能是牛客的测试用例有问题
// 用例输入 {1,2,#,#,3,#,4},4
// 预期输出 1
// 我的输出 nullptr, 这个4不是应该是单独一个谁都不链接的结点吗？
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // 中序遍历影响下一个结点是谁的因素有（或者说候选人）
		// 右子树中序遍历的第一个结点（优先级最高）
		// 没有右子树的情况下，父节点（如果有的话，而且得是父节点的左孩子）
        // （！！！！这里漏了一种，虽然是父亲的右孩子，但是父亲结点有可能是父亲的父亲的左孩子，这时候下一个结点就是父亲的父亲）
		if (pNode == nullptr) return nullptr;
		// 返回中序遍历的第一个结点
		vector<TreeLinkNode*> res;
        function<void(TreeLinkNode*)> dfs = [&](TreeLinkNode* node){
            if (node == nullptr) return;
            dfs(node->left);
			res.push_back(node);
			dfs(node->right);
            };
        // 有右子树
        if (pNode->right) {
			dfs(pNode->right);
			return res[0]; // 右子树中序遍历的第一个结点
        }
        // 有父亲结点
        else if (pNode->next) {
            // 左孩子
            if (pNode == pNode->next->left) return pNode->next; // 父节点
            // 右孩子
            else if (pNode == pNode->next->right) {
                if (pNode->next->next && pNode->next == pNode->next->next->left) {
					return pNode->next->next; // 父亲的父亲（注意，应该是错在这里了，这里只判断了一层，应该是继续向上遍历，直到找到一个是父节点的左子节点的结点，返回该结点的父节点）
                }
                else return nullptr;
            }
            else return nullptr;
        }
		// 没有右子树，有父亲结点但不是左孩子，没有父亲结点
        else return nullptr;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2

struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
// 阿秀做法，简洁
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // 二叉树为空，返回空
        if (pNode == nullptr) return nullptr;
		// 结点右孩子存在，则设置一个指针从该结点右孩子出发，一直沿着指向左子节点遍历，直到找到一个没有左子节点的结点，就是下一个结点
        TreeLinkNode* node = nullptr;
        if (pNode->right != nullptr) {
			node = pNode->right;
            while (node->left != nullptr) {
				node = node->left;
            }
			return node; // 返回右子树中序遍历的第一个结点
        }
        // 右孩子不存在，如果节点不是根节点，如果该节点是父节点的左子节点，则返回父节点；否则继续向上遍历，直到找到一个是父节点的左子节点的结点，返回该结点的父节点
        node = pNode;
        while (node->next != nullptr && node == node->next->right) {
			node = node->next; // 向上遍历
        }
        // 如果node->next是nullptr，说明已经到达根节点了，返回nullptr；
        // 如果node->next不是nullptr，说明node->next是父节点，返回父节点
		return node->next; 
    }
};

#endif // DEBUG2