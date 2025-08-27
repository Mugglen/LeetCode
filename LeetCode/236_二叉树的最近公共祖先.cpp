

class TreeNode {

public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// 最近公共祖先的定义： 设节点 root 为节点 p,q 的某公共祖先，若其左子节点 root.left 和右子节点 root.right 都不是 p,q 的公共祖先，则称 root 是 “最近的公共祖先” 。
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solutions/240096/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu


// 时间复杂度O（N）
// 空间复杂度O（N）

class Solution{

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		
		// 遍历到叶子或者找到节点就返回
		if (root == nullptr || root == p || root == q) return root;
		
		// 递归，天然后续，要知道左右有没有目标节点
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		
		// 递归边界
		if (left == nullptr && right == nullptr) return nullptr; // 两边都没
		if (left == nullptr) return right;						// 右边有
		if (right == nullptr) return left;						// 左边有
		return root;											// 左右两边都有
	
	}



};