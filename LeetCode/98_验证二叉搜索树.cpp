#include <climits>

struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
	: val(x), left(left), right(right){}

};


// 时间复杂度：O(n)，其中 n 为二叉搜索树的节点个数。
// 空间复杂度：O(n)。最坏情况下，二叉搜索树退化成一条链
// （注意题目没有保证它是平衡树），因此递归需要 O(n) 的栈空间。
class Solution {

public:
	// 虽然题目是 int 类型，但开始递归的时候，left 需要比所有节点值都要小，
	// right 需要比所有节点值都要大，如果节点值刚好是 int 的最小值/最大值，
	// 就没有这样的 left 和 right 了，所以需要用 long 类型。

	bool isValidBST(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
		// 异常值处理
		if (root == nullptr) return true;

		// 但为啥作者还要引入 x 呢？
		// 了防止类型隐式转换引起的 bug 或警告，提高代码鲁棒性和可读性。
		// 如果直接用 root->val 做比较：编译器要进行 int → long long 的隐式转换。
		long long x = root->val;

		return left < x &&
			right > x &&
			isValidBST(root->left, left, x) &&
			isValidBST(root->right, x, right);

	}

};