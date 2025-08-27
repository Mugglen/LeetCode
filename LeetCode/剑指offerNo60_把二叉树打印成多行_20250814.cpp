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

    // 层次遍历，但是结果分层，还是两个队列的思路
    vector<vector<int> > Print(TreeNode* pRoot) {
		if (pRoot == nullptr) return {};
        // 辅助队列
		queue<TreeNode*> qOdd, qEven;
		qOdd.push(pRoot);
		vector<vector<int>> ans;
		vector<int> tmp;
        while (!qOdd.empty() || !qEven.empty()) {
            while (!qOdd.empty()) {
				TreeNode* node = qOdd.front();
				tmp.push_back(node->val);
				// 进入偶数队列
				if (node->left) qEven.push(node->left);
				if (node->right) qEven.push(node->right);
				// 弹出节点
				qOdd.pop();
            }
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}
			while (!qEven.empty()) {
				TreeNode* node = qEven.front();
				tmp.push_back(node->val);
				// 进入偶数队列
				if (node->left) qOdd.push(node->left);
				if (node->right) qOdd.push(node->right);
				// 弹出节点
				qEven.pop();
			}
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}
        }
		return ans;
    }
};



#endif // DEBUG2