#include<vector>
#include<unordered_map>

using namespace std;

class TreeNode {

	// ע�����public,��Ȼ��ֱ����struct����������
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr){}

};


// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solutions/2361558/105-cong-qian-xu-yu-zhong-xu-bian-li-xu-4lvkz

// ���η������ȸ���ǰ�����ȷ�ϸ��ڵ㣬�ٸ����������ȷ������������Χ���ٸ���ǰ�����ȷ�����������ĸ���
// ע�⣡����ֻ�����ڡ����ظ��ڵ�ֵ���Ķ�����
// ʹ�ù�ϣ������ʱ�临�Ӷ�

class Solution {

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		// ����������и���Ա��������
		// �����Ա�����;ֲ����������ֲ�ͬ������Ҫʹ�� this��ֱ�ӷ��ʳ�Ա�����Ϳ��ԡ�
		this->preorder = preorder;
		
		for (int i = 0; i < inorder.size(); i++) {
			dic[inorder[i]] = i;
		}
		return recur(0, 0, inorder.size() - 1);
	}


private:
	vector<int> preorder;
	unordered_map<int, int> dic;

	// ����ǩ��Ϊ����ǰ������и��ڵ������� �����������߽磬 ����������ұ߽磬��Ҫ������ָ������һ�����ڵ�λ�ã�
	TreeNode* recur(int root, int left, int right) {
		if (left > right) return nullptr;		// �ݹ���ֹ
		TreeNode* node = new TreeNode(preorder[root]);

		// ���¸��ڵ���inorder�е�λ��
		int i = dic[preorder[root]];

		// ��ʼ�ݹ�
		// ������root��ǰ��������ǵ�ǰ root + 1 ��
		// �������������߽绹������࣬
		// �ұ߽�����������ԭ root ���� ��1
		node->left = recur(root + 1, left, i - 1);

		// ������root��ǰ��������ǵ�ǰǰ������� ���ڵ�����root + ���������� i-left �� ��1 ��
		// �������������߽��� ���ڵ����� + 1��
		// �ұ߽绹���ұ߽�
		node->right = recur(root + i - left + 1, i + 1, right);

		return node;
	}
};