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
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ��������ӵ��������ˣ�����������DEBUG2���ǶԵ�
// �������룺{8,6,10,5,7,9,11}
// Ԥ�������[[8],[10,6],[5,7,9,11]]
// ʵ�������[[8],[10,6],[9,11,5,7]]
class Solution {
public:
	// ֮���α�������ʵ���ǲ�α�����һ�㷴��
    vector<vector<int> > Print(TreeNode* pRoot) {
		// ��Ҫ�����������У�����1�������㣬����2��ż����
		queue<TreeNode*> qOdd, qEven;
		// �����
		vector<vector<int>> ans;
		vector<int> tmp;
		qOdd.push(pRoot);
		while (!qOdd.empty() || !qEven.empty()) {
			// �������д������Ҵ�ӡ
			while (!qOdd.empty()) {
				tmp.push_back(qOdd.front()->val);
				// �������ż������
				if (qOdd.front()->right) qEven.push(qOdd.front()->right);
				if (qOdd.front()->left) qEven.push(qOdd.front()->left);
				// ���������ǵõ����ڵ�
				qOdd.pop();
			}
			// ��һ�ν�������tmp��ע�⣬tmp����Ϊ�գ���������ans�
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}
			// ż�����д��������ӡ
			while (!qEven.empty()) {
				tmp.push_back(qEven.front()->val);
				// ��������������У���
				if (qEven.front()->left) qOdd.push(qEven.front()->left);
				if (qEven.front()->right) qOdd.push(qEven.front()->right);
				qEven.pop();
			}
			// ��һ�ν�������tmp��ע�⣬tmp����Ϊ�գ���������ans�
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}
		}
		return ans;
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2


struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
	// ����ջ�������ܺ����һ�㣬ջ1�������㣬ջ2��ż����
	// ջ1 �� ջ2 ���ʱ���ȴ����ӽڵ��ٴ����ӽڵ㣬����ջ2�ĳ�ջ˳����Ƿ���
	// ջ2 �� ջ1 ���ʱ���ȴ����ӽڵ��ٴ����ӽڵ㣬����ջ1�ĳ�ջ˳���������
	vector<vector<int>> Print(TreeNode* pRoot) {
		vector<vector<int>> ans;
		if (pRoot == nullptr) return ans;
		// ����������ջ
		stack<TreeNode*> oddStack;
		oddStack.push(pRoot);
		// ����ż����ջ
		stack<TreeNode*> evenStack;
		// �ݴ�
		vector<int> tmp;

		while (!oddStack.empty() || !evenStack.empty()) {
			// �����в�Ϊ��
			while (!oddStack.empty()) {
				// ȡ���ڵ�
				TreeNode* node = oddStack.top();
				// ѹ����
				tmp.push_back(node->val);
				// ѹ��ż��ջ
				if (node->left) evenStack.push(node->left);
				if (node->right) evenStack.push(node->right);
				oddStack.pop();
			}
			// ��һ�ν����ע��tmp����Ϊ�գ�
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}
			// ż���в�Ϊ��
			while (!evenStack.empty()) {
				// ȡ���ڵ�
				TreeNode* node = evenStack.top();
				// ѹ����
				tmp.push_back(node->val);
				// ѹ������ջ
				if (node->right) oddStack.push(node->right);
				if (node->left) oddStack.push(node->left);
				evenStack.pop();
			}
			// ��һ�ν����ע��tmp����Ϊ�գ�
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}

		}
		return ans;
	}
};

#endif // DEBUG2