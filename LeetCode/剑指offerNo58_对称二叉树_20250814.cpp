#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

	bool isSymmetrical(TreeNode* pRoot) {
		if (pRoot == nullptr) return true; // �����ǶԳƵ�
		// compare��Ƚ���������Ƿ�Գ�
		function<bool(TreeNode*, TreeNode*)> compare = [&](TreeNode* node1, TreeNode* node2) ->bool {
			//if (node1 == nullptr && node2 == nullptr) return true; // ��Ϊ�գ�˵���Գ�
			//if (node1 == nullptr && node2 != nullptr) return false;
			//if (node1 != nullptr && node2 == nullptr) return false;
			// ��������������Ժϲ�������һ��
			if (node1 == nullptr || node2 == nullptr) return node1 == node2;
			if (node1->val != node2->val) return false;
			else {
				// ע�������ǶԳƵģ�������������Ҫ����λ��
				return compare(node1->left, node2->right) && compare(node1->right, node2->left);
			}

			};
		return compare(pRoot->left, pRoot->right); // �Ӹ��ڵ������������ʼ�Ƚ�
	}
};

#endif // DEBUG1