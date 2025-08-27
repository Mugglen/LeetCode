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

class Solution {
public:

	bool isSymmetrical(TreeNode* pRoot) {
		if (pRoot == nullptr) return true; // 空树是对称的
		// compare里比较两个结点是否对称
		function<bool(TreeNode*, TreeNode*)> compare = [&](TreeNode* node1, TreeNode* node2) ->bool {
			//if (node1 == nullptr && node2 == nullptr) return true; // 都为空，说明对称
			//if (node1 == nullptr && node2 != nullptr) return false;
			//if (node1 != nullptr && node2 == nullptr) return false;
			// 上面三种情况可以合并成下面一句
			if (node1 == nullptr || node2 == nullptr) return node1 == node2;
			if (node1->val != node2->val) return false;
			else {
				// 注意这里是对称的，所以左右子树要交换位置
				return compare(node1->left, node2->right) && compare(node1->right, node2->left);
			}

			};
		return compare(pRoot->left, pRoot->right); // 从根节点的左右子树开始比较
	}
};

#endif // DEBUG1