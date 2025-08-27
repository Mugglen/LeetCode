#include <algorithm>

using namespace std;

//#define DEBUG
#ifdef DEBUG
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {

public:

	// ����������ʽ���������ȣ�����ȽϺ���⣬����ֱ�۵��뵽��Ҫ֪��������������Ⱥ���ܱȽϣ�
	int getdepth(TreeNode* node) {

		// ��д�߽�����
		if (node == nullptr) return 0;

		// ����ݹ������������
		int depthLeft = getdepth(node->left);
		int depthRight = getdepth(node->right);
		int depth = std::max(depthLeft, depthRight) + 1; // ע�⣡����������+1 ����

		// 
		return depth;


	}

	int maxDepth(TreeNode* root) {

		return getdepth(root);
	}



};
#endif // DEBUG


// �������ݹ���Σ��������ݹ�ı��ʣ��������㷨���� 09����https://www.bilibili.com/video/BV1UD4y1Y769?vd_source=394ce55653aeb29ebdb87e06077ee56c
// ˼·2�����ݵ�ǰ��ȣ�ʹ��ǰ��ķ�ʽ�����������������Ի�ȡ���ڵ�����
//#define DEBUG2
#ifdef DEBUG2
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {


public:

	// ��ȱ���
	int depth = 0;

	// ����������ʽ���������ȣ�����ȽϺ���⣬����ֱ�۵��뵽��Ҫ֪��������������Ⱥ���ܱȽϣ�
	void getdepth(TreeNode* node, int cnt) {

		// ��д�߽�����
		if (node == nullptr) return;

		// �ֲ����+1
		cnt++;

		// �������
		depth = max(cnt, depth);

		// ����ݹ�
		getdepth(node->left, cnt);
		getdepth(node->right, cnt);


	}

	int maxDepth(TreeNode* root) {
		getdepth(root, 0);
		return depth;
	}



};
#endif // DEBUG2
