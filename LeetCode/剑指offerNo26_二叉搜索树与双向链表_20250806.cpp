#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
using namespace std;


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
	// ���ǰѶ���������������������˫����
	TreeNode* Convert(TreeNode* pRootOfTree) {
		// ����(�ǵ�����)
		if (pRootOfTree == nullptr) return nullptr;
		// ������������Ǳ���ڵ�ָ��(���ֳ�ʼ��Ҳ���ܴ������У���Ϊ������push_back������)
		//vector<TreeNode*> inOrder(1,nullptr);
		vector<TreeNode*> inOrder;

		function<void(TreeNode*)> traversal = [&](TreeNode* node) {

			// �ݹ���ֹ
			if (node == nullptr) return;
			// ����
			traversal(node->left);
			inOrder.push_back(node);
			traversal(node->right);
			return;
			};
		// �����ݹ�
		traversal(pRootOfTree);
		// ��˳���������ӽڵ�
		for (int i = 0; i < inOrder.size(); ++i) {
			// ͷ�ڵ�ǰ��Ϊ�գ��������ڵ������
			if (i == 0) {
				inOrder[i]->left = nullptr;
				inOrder[i]->right = inOrder[i+1];
			}
			// β�ڵ����Ϊ��(�͵��ڵ�������ֿ�)
			else if (i == inOrder.size() - 1 && i != 0) {
				inOrder[i]->left = inOrder[i-1];
				inOrder[i]->right = nullptr;
			}
			else {
				inOrder[i]->left = inOrder[i - 1];
				inOrder[i]->right = inOrder[i + 1];
			}
		}
		return inOrder[0];
	}
};



#endif // DEBUG1

// ʹ��ջ���и������о��ǵ�������������ĸĽ���û�п��ĺܶ���
//#define DEBUG2
#ifdef DEBUG2

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/26-%E5%89%91%E6%8C%87offer.html
	// ���ý�ָoffer��һ����д��
	// ��ȷConvert�����Ĺ��ܡ����룺һ�������������ĸ��ڵ㡣���̣�����ת��Ϊһ�������˫��������������ظ������ͷ�ڵ㡣
	// ��ȷ��Ա����pLast�Ĺ��ܣ����ڼ�¼��ǰ����ĩβ�ڵ�
	// ��ȷ�ݹ���̡��ݹ�Ĺ��̾��൱�ڰ������������
	// ���������ֽ����������С����Ȼ�����Ƿֱ�ת������һС��һС�ε�˫������
	// ������pLast��¼�ܵ������ĩβ�������ЩС������һ����һ���ؼӵ�ĩβ��
	TreeNode* Convert(TreeNode* pRootOfTree) {
		TreeNode* head = nullptr; // head ���
		TreeNode* pre = nullptr;// ��¼��һ�γ�ջֵ
		stack<TreeNode*> st; // ʹ��ջ����

		while (pRootOfTree || !st.empty()) {
			while (pRootOfTree != nullptr) {
				st.push(pRootOfTree);
				pRootOfTree = pRootOfTree->left;
			}
			if (!st.empty()) {
				pRootOfTree = st.top();
				st.pop();
				if (pre != nullptr) {
					pre->right = pRootOfTree;
					pRootOfTree->left = pre;
				}
				else { // preΪ�գ���ʾst��һ�γ�ջ�� ��һ�γ�ջֵΪ����ֵ�������ֵ
					head = pRootOfTree;
				}
				pre = pRootOfTree;
				pRootOfTree = pRootOfTree->right;
			}
		}
		return head;
	}
};

#endif // DEBUG2