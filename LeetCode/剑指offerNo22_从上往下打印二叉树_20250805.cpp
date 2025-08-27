#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


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
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		// 注意，忘记特判了!!!!!!!!!
		if (root == nullptr) return {};
		// 层次遍历嘛，辅助队列！
		vector<int> ans;
		queue<TreeNode*> q;
		q.push(root);
		// 循环入队
		while (!q.empty()) {
			TreeNode* node = q.front();
			ans.push_back(node->val);
			q.pop();
			// 先左后右，但是要判断有没有节点
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		return ans;
	}
};


#endif // DEBUG1


