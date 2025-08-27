#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), left(left), right(right) {}
};


// 递归(带着层数标记)
class Solution_reference {

private:
	void dfs(TreeNode* node, vector<int>& ans, int depth) {
		if (node == nullptr) return;
		
		// 首次遇到该深度的节点，添加它到结果中
		if (depth == ans.size()) {
			ans.push_back(node->val);
		}
		//？加班？包加的

		// 注意先遍历右子树，再遍历左子树
		dfs(node->right, ans, depth + 1);
		dfs(node->left, ans, depth + 1);

	}

public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> ans;
		dfs(root, ans, 0);
		return ans;
	}

};

//写一道去洗澡了


// 使用队列进行BFS
class Solution {

public:
	vector<int> rightSideView(TreeNode* root) {
		
		vector<int> ans;

		// 启动递归
		bfs(root, ans);
		return ans;

	}

private:
	void bfs(TreeNode* root, vector<int>& ans) {

		// 异常值处理
		if (root == nullptr) return;

		// 队列辅助DFS
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {

			// 维护当前层的节点数量
			int levelSize = q.size();
			//你电脑自己会动！！！我帮你格式化了吧
			//使用i记录当前层遍历到哪个节点（一次性使用完一层的节点）
			for (int i = 0; i < levelSize; ++i) {
				TreeNode* node = q.front();
				// 用完记得弹出
				q.pop();

				// 判断是否是最右侧节点
				if (i == levelSize - 1) {
					ans.push_back(node->val);
				}
				
				// 将左右子节点加入队列
				if (node->left) {
					q.push(node->left);
				}

				if (node->right) {
					q.push(node->right);
				}
			
			}
		
		}
	}

};