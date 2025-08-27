#include <vector>


using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), left(left), right(right){}
};


// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/solutions/2952810/zhong-xu-bian-li-pythonjavaccgojsrust-by-wc02
//由于中序遍历就是在从小到大遍历节点值，所以遍历到的第 k 个节点值就是答案。

// 使用k标记递归位置的做法，感觉不太直观
class Solution_reference{

private:
	void inorderTraversal(TreeNode* node, int& k, int& ans) {
	
		// 边界处理
		if (node == nullptr)  return;
		
		// 中序递归
		inorderTraversal(node->left, k, ans);
		if (--k == 0) ans = node->val; // （注意是！！！k--）
		inorderTraversal(node->right, k, ans);

	
	}

public:
	int kthSmallest(TreeNode* root, int k) {
		int ans;

		// 启动递归
		inorderTraversal(root, k, ans);
		return ans;
	}

};

// 先通过中序遍历取出升序数组，再取里面的第k个
class Solution {

private:
	void inorderTraversal(TreeNode* node, vector<int>& vals) {
		// 边界处理
		if (node == nullptr) return;

		// 中序遍历
		inorderTraversal(node->left, vals);
		vals.push_back(node->val);
		inorderTraversal(node->right, vals);
	
	}



public:
	int kthSmallest(TreeNode* root, int k) {
		vector<int> vals;

		inorderTraversal(root, vals);
		
		return vals[k - 1];
	}


};
