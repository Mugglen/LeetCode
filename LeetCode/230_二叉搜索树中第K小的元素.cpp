#include <vector>


using namespace std;


struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), left(left), right(right){}
};


// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/solutions/2952810/zhong-xu-bian-li-pythonjavaccgojsrust-by-wc02
//����������������ڴ�С��������ڵ�ֵ�����Ա������ĵ� k ���ڵ�ֵ���Ǵ𰸡�

// ʹ��k��ǵݹ�λ�õ��������о���ֱ̫��
class Solution_reference{

private:
	void inorderTraversal(TreeNode* node, int& k, int& ans) {
	
		// �߽紦��
		if (node == nullptr)  return;
		
		// ����ݹ�
		inorderTraversal(node->left, k, ans);
		if (--k == 0) ans = node->val; // ��ע���ǣ�����k--��
		inorderTraversal(node->right, k, ans);

	
	}

public:
	int kthSmallest(TreeNode* root, int k) {
		int ans;

		// �����ݹ�
		inorderTraversal(root, k, ans);
		return ans;
	}

};

// ��ͨ���������ȡ���������飬��ȡ����ĵ�k��
class Solution {

private:
	void inorderTraversal(TreeNode* node, vector<int>& vals) {
		// �߽紦��
		if (node == nullptr) return;

		// �������
		inorderTraversal(node->left, vals);
		vals.push_back(node->val);
		inorderTraversal(node->right, vals);
	
	}



public:
	int kthSmallest(TreeNode* root, int k) {
		vector<int> vals;

		inorderTraversal(root, vals);
		
		return vals[k - 1];
	}


};
