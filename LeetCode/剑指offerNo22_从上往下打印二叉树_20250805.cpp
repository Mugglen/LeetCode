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
		// ע�⣬����������!!!!!!!!!
		if (root == nullptr) return {};
		// ��α�����������У�
		vector<int> ans;
		queue<TreeNode*> q;
		q.push(root);
		// ѭ�����
		while (!q.empty()) {
			TreeNode* node = q.front();
			ans.push_back(node->val);
			q.pop();
			// ������ң�����Ҫ�ж���û�нڵ�
			if (node->left) q.push(node->left);
			if (node->right) q.push(node->right);
		}
		return ans;
	}
};


#endif // DEBUG1


