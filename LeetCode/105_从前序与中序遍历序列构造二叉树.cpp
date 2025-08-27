#include<vector>
#include<unordered_map>

using namespace std;

class TreeNode {

	// 注意加上public,不然就直接用struct！！！！！
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}

};


// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/2361558/105-cong-qian-xu-yu-zhong-xu-bian-li-xu-4lvkz

// 分治方法（先根据前序遍历确认根节点，再根据中序遍历确认左右子树范围，再根据前序遍历确认左右子树的根）
// 注意！！！只适用于“无重复节点值”的二叉树
// 使用哈希表提升时间复杂度

class Solution {

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		// 放入类变量中给成员函数访问
		// 如果成员变量和局部变量的名字不同，则不需要使用 this，直接访问成员变量就可以。
		this->preorder = preorder;
		
		for (int i = 0; i < inorder.size(); i++) {
			dic[inorder[i]] = i;
		}
		return recur(0, 0, inorder.size() - 1);
	}


private:
	vector<int> preorder;
	unordered_map<int, int> dic;

	// 函数签名为（在前序遍历中根节点索引， 中序遍历中左边界， 中序遍历中右边界，需要后两个指标标记下一个根节点位置）
	TreeNode* recur(int root, int left, int right) {
		if (left > right) return nullptr;		// 递归终止
		TreeNode* node = new TreeNode(preorder[root]);

		// 存下根节点在inorder中的位置
		int i = dic[preorder[root]];

		// 开始递归
		// 左子树root在前序遍历里是当前 root + 1 ，
		// 在中序遍历中左边界还是最左侧，
		// 右边界从中序遍历的原 root 索引 减1
		node->left = recur(root + 1, left, i - 1);

		// 右子树root在前序遍历里是当前前序遍历中 根节点索引root + 左子树长度 i-left 再 加1 ，
		// 在中序遍历中左边界是 根节点索引 + 1，
		// 右边界还是右边界
		node->right = recur(root + i - left + 1, i + 1, right);

		return node;
	}
};