#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;

// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/solutions/144306/mian-shi-ti-26-shu-de-zi-jie-gou-xian-xu-bian-li-p/
//#define DEBUG1
#ifdef DEBUG1

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	// ע����Ŀ������������������Ĳ�α�������Ҫ������
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {

		// ����
		if (pRoot1 == nullptr || pRoot2 == nullptr) return false;
		// ���ӽṹ���������,��ǰ������������ڵ���ͬһ���� || �ڵ�1���������ͽڵ�2Ϊ��������ͬһ���� || �ڵ�1���������ͽڵ�2Ϊ��������ͬһ����
		if (compareTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2)) {
			return true;
		}
		// ע��������У���Ȼreturn ������if��ᱨ��
		return false;

		// ����д���һ��
		// return (pRoot1 != nullptr && pRoot2 != nullptr) && (compareTree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2));

	}

	// �ݹ��ж��Ե�ǰ�ڵ�AΪ��������BΪ���������������ǲ�����ȵ�
	bool compareTree(TreeNode* nodeA, TreeNode* nodeB) {
		// �ݹ�ȵ�B��Ҷ��֮���ˣ���ʾ��֧·ƥ�����
		if (nodeB == nullptr) return true;
		if (nodeA == nullptr || nodeA->val != nodeB->val) return false;
		return (compareTree(nodeA->left, nodeB->left) && compareTree(nodeA->right, nodeB->right));
	}
};



#endif // DEBUG1