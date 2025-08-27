#include <climits>

struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
	: val(x), left(left), right(right){}

};


// ʱ�临�Ӷȣ�O(n)������ n Ϊ�����������Ľڵ������
// �ռ临�Ӷȣ�O(n)�������£������������˻���һ����
// ��ע����Ŀû�б�֤����ƽ����������˵ݹ���Ҫ O(n) ��ջ�ռ䡣
class Solution {

public:
	// ��Ȼ��Ŀ�� int ���ͣ�����ʼ�ݹ��ʱ��left ��Ҫ�����нڵ�ֵ��ҪС��
	// right ��Ҫ�����нڵ�ֵ��Ҫ������ڵ�ֵ�պ��� int ����Сֵ/���ֵ��
	// ��û�������� left �� right �ˣ�������Ҫ�� long ���͡�

	bool isValidBST(TreeNode* root, long long left = LLONG_MIN, long long right = LLONG_MAX) {
		// �쳣ֵ����
		if (root == nullptr) return true;

		// ��Ϊɶ���߻�Ҫ���� x �أ�
		// �˷�ֹ������ʽת������� bug �򾯸棬��ߴ���³���ԺͿɶ��ԡ�
		// ���ֱ���� root->val ���Ƚϣ�������Ҫ���� int �� long long ����ʽת����
		long long x = root->val;

		return left < x &&
			right > x &&
			isValidBST(root->left, left, x) &&
			isValidBST(root->right, x, right);

	}

};