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


// �ݹ�(���Ų������)
class Solution_reference {

private:
	void dfs(TreeNode* node, vector<int>& ans, int depth) {
		if (node == nullptr) return;
		
		// �״���������ȵĽڵ㣬������������
		if (depth == ans.size()) {
			ans.push_back(node->val);
		}
		//���Ӱࣿ���ӵ�

		// ע���ȱ������������ٱ���������
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

//дһ��ȥϴ����


// ʹ�ö��н���BFS
class Solution {

public:
	vector<int> rightSideView(TreeNode* root) {
		
		vector<int> ans;

		// �����ݹ�
		bfs(root, ans);
		return ans;

	}

private:
	void bfs(TreeNode* root, vector<int>& ans) {

		// �쳣ֵ����
		if (root == nullptr) return;

		// ���и���DFS
		queue<TreeNode*> q;
		q.push(root);

		while (!q.empty()) {

			// ά����ǰ��Ľڵ�����
			int levelSize = q.size();
			//������Լ��ᶯ�������Ұ����ʽ���˰�
			//ʹ��i��¼��ǰ��������ĸ��ڵ㣨һ����ʹ����һ��Ľڵ㣩
			for (int i = 0; i < levelSize; ++i) {
				TreeNode* node = q.front();
				// ����ǵõ���
				q.pop();

				// �ж��Ƿ������Ҳ�ڵ�
				if (i == levelSize - 1) {
					ans.push_back(node->val);
				}
				
				// �������ӽڵ�������
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