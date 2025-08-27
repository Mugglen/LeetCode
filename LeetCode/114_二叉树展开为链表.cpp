

// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solutions/2992172/liang-chong-fang-fa-tou-cha-fa-fen-zhi-p-h9bg

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), left(left), right(right) {}
};

// 方法一 头插法
class Solution_headInsert {

private:
	// 存储当前链表的头节点
	TreeNode* head;


public:
	void flatten(TreeNode* root) {
		
		// 边界处理
		if (root == nullptr) return;
		
		// 注意展开后的顺序要求和前序遍历相同
		// 因为是头插法所以顺序得与前序完全相反，右，左，根
		// 效果就是按照前序遍历的顺序，但是倒着从结尾通过头插来造链表
		flatten(root->right);
		flatten(root->left);

		// 按照右子树 - 左子树 - 根的顺序 DFS 这棵树。
		root->left = nullptr;
		root->right = head;
		head = root;
	}



};


class Solution {

private:
	TreeNode* dfs(TreeNode* root) {
		
		if (root == nullptr) return nullptr;

		TreeNode* left_tail = dfs(root->left);
		TreeNode* right_tail = dfs(root->right);

		if (left_tail) {

			// 左子树链表->右子树链表
			left_tail->right = root->right;
			// 当前节点 -> 左右子树合并后的链表
			root->right = root->left;
			root->left = nullptr;
		
		}
		return right_tail ? right_tail : left_tail ? left_tail : root;
	
	}

public:
	void flatten(TreeNode* root) {
		dfs(root);
	}


};