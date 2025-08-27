#include <iostream>
#include <algorithm>

// ʱ�临�Ӷȣ�O(N)������ N Ϊ�������Ľڵ���

using namespace std;

struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};


class Solution {

private:
	int ans;
	int depth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		// ע��ݹ�ķ���ֵ�����������������ȣ����ǵ�ǰ�ڵ��������ֱ���������������������������
		int depthL = depth(root->left); // �����Ϊ�����������
		int depthR = depth(root->right); // �Ҷ���Ϊ�����������
		ans = max(ans, depthL + depthR + 1);
		return max(depthL, depthR) + 1; // ���ط��ظýڵ�Ϊ�������������

	}


public:
	int diameterOfBinaryTree(TreeNode* root) {
		ans = 1;
		depth(root);
		return (ans - 1);
	
	}

};