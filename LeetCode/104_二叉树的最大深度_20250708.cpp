#include <algorithm>

using namespace std;

//#define DEBUG
#ifdef DEBUG
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {

public:

	// 后续遍历方式来求最大深度（后序比较好理解，可以直观地想到需要知道左右子树的深度后才能比较）
	int getdepth(TreeNode* node) {

		// 先写边界条件
		if (node == nullptr) return 0;

		// 后序递归计算左右子树
		int depthLeft = getdepth(node->left);
		int depthRight = getdepth(node->right);
		int depth = std::max(depthLeft, depthRight) + 1; // 注意！！！！！！+1 操作

		// 
		return depth;


	}

	int maxDepth(TreeNode* root) {

		return getdepth(root);
	}



};
#endif // DEBUG


// 【看到递归就晕？带你理解递归的本质！【基础算法精讲 09】】https://www.bilibili.com/video/BV1UD4y1Y769?vd_source=394ce55653aeb29ebdb87e06077ee56c
// 思路2，传递当前深度，使用前序的方式，这样左右子树可以获取父节点的深度
//#define DEBUG2
#ifdef DEBUG2
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {


public:

	// 深度变量
	int depth = 0;

	// 后续遍历方式来求最大深度（后序比较好理解，可以直观地想到需要知道左右子树的深度后才能比较）
	void getdepth(TreeNode* node, int cnt) {

		// 先写边界条件
		if (node == nullptr) return;

		// 局部深度+1
		cnt++;

		// 更新深度
		depth = max(cnt, depth);

		// 先序递归
		getdepth(node->left, cnt);
		getdepth(node->right, cnt);


	}

	int maxDepth(TreeNode* root) {
		getdepth(root, 0);
		return depth;
	}



};
#endif // DEBUG2
