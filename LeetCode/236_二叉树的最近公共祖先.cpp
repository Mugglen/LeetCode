

class TreeNode {

public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// ����������ȵĶ��壺 ��ڵ� root Ϊ�ڵ� p,q ��ĳ�������ȣ��������ӽڵ� root.left �����ӽڵ� root.right ������ p,q �Ĺ������ȣ���� root �� ������Ĺ������ȡ� ��
// https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/solutions/240096/236-er-cha-shu-de-zui-jin-gong-gong-zu-xian-hou-xu


// ʱ�临�Ӷ�O��N��
// �ռ临�Ӷ�O��N��

class Solution{

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		
		// ������Ҷ�ӻ����ҵ��ڵ�ͷ���
		if (root == nullptr || root == p || root == q) return root;
		
		// �ݹ飬��Ȼ������Ҫ֪��������û��Ŀ��ڵ�
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		
		// �ݹ�߽�
		if (left == nullptr && right == nullptr) return nullptr; // ���߶�û
		if (left == nullptr) return right;						// �ұ���
		if (right == nullptr) return left;						// �����
		return root;											// �������߶���
	
	}



};