

// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/solutions/2992172/liang-chong-fang-fa-tou-cha-fa-fen-zhi-p-h9bg

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), left(left), right(right) {}
};

// ����һ ͷ�巨
class Solution_headInsert {

private:
	// �洢��ǰ�����ͷ�ڵ�
	TreeNode* head;


public:
	void flatten(TreeNode* root) {
		
		// �߽紦��
		if (root == nullptr) return;
		
		// ע��չ�����˳��Ҫ���ǰ�������ͬ
		// ��Ϊ��ͷ�巨����˳�����ǰ����ȫ�෴���ң��󣬸�
		// Ч�����ǰ���ǰ�������˳�򣬵��ǵ��Ŵӽ�βͨ��ͷ����������
		flatten(root->right);
		flatten(root->left);

		// ���������� - ������ - ����˳�� DFS �������
		root->left = nullptr;
		root->right = head;
		head = root;
	}



};


class Solution {

private:
	TreeNode* dfs(TreeNode* root) {
		
		if (root == nullptr) return nullptr;

		TreeNode* left_tail = dfs(root->left);
		TreeNode* right_tail = dfs(root->right);

		if (left_tail) {

			// ����������->����������
			left_tail->right = root->right;
			// ��ǰ�ڵ� -> ���������ϲ��������
			root->right = root->left;
			root->left = nullptr;
		
		}
		return right_tail ? right_tail : left_tail ? left_tail : root;
	
	}

public:
	void flatten(TreeNode* root) {
		dfs(root);
	}


};