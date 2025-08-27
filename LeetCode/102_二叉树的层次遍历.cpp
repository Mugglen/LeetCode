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


// �����������
// https://leetcode.cn/problems/binary-tree-level-order-traversal/solutions/2049807/bfs-wei-shi-yao-yao-yong-dui-lie-yi-ge-s-xlpz


// ����1 ʹ���������飬һ���浱ǰ��Ľڵ㣬һ������һ��Ľڵ㣬����һ��ڵ�Ϊ��ʱ����ѭ��

// ����2 ʹ�ö��У�����һ��������Ǿ��״���������������ż�������Һ������˳��ͬ��

class Solution {

public:
	vector<vector<int>> levelOrder(TreeNode* root) {

		// �쳣ֵ����
		if (root == nullptr) return {};

		// ����������
		vector<vector<int>> ans;

		// ������������
		queue<TreeNode*> q;

		q.push(root);

		// ע��ѭ����������Ϊ���п�
		while (!q.empty()) {
			vector<int> vals;
			// ��ȡѭ�����������Ƕ������Ԫ�ظ���
			for (int n = q.size(); n--; ) {
				auto node = q.front();
				q.pop();
				vals.push_back(node->val);
				
				//�����½ڵ�ʱ�ǵ��ж�һ��
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);

			}
			ans.emplace_back(vals);
		
		}
		return ans;
	}

};