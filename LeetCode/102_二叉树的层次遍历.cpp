#include <vector>
#include <iostream>
#include <queue>

using namespace std;


struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1) : val(x), left(nullptr), right(nullptr) {}

};


// 广度优先搜索
// https://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/2049807/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlpz


// 方法1 使用两个数组，一个存当前层的节点，一个存下一层的节点，在下一层节点为空时结束循环

// 方法2 使用队列，像建树一样（如果是锯齿状遍历，在奇数层和偶数层左右孩子入队顺序不同）

class Solution {

public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		// 异常值处理
		if (root == nullptr) return {};

		// 保存结果向量
		vector<vector<int>> ans;

		// 创建辅助队列
		queue<TreeNode*> q;

		q.push(root);

		// 注意循环结束条件为队列空
		while (!q.empty()) {
			vector<int> vals;
			// 获取循环次数，就是队列里的元素个数
			for (int n = q.size(); n--; ) {
				auto node = q.front();
				q.pop();
				vals.push_back(node->val);
				
				//推入新节点时记得判断一下
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);

			}
			ans.emplace_back(vals);
		
		}
		return ans;
	}

};