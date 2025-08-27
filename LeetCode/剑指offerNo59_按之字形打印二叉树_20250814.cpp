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

// 正反序入队的做法错了！！！，下面DEBUG2才是对的
// 用例输入：{8,6,10,5,7,9,11}
// 预期输出：[[8],[10,6],[5,7,9,11]]
// 实际输出：[[8],[10,6],[9,11,5,7]]
class Solution {
public:
	// 之字形遍历，其实就是层次遍历隔一层反序
    vector<vector<int> > Print(TreeNode* pRoot) {
		// 需要两个辅助队列，队列1存奇数层，队列2存偶数层
		queue<TreeNode*> qOdd, qEven;
		// 结果集
		vector<vector<int>> ans;
		vector<int> tmp;
		qOdd.push(pRoot);
		while (!qOdd.empty() || !qEven.empty()) {
			// 奇数队列从左往右打印
			while (!qOdd.empty()) {
				tmp.push_back(qOdd.front()->val);
				// 反序进入偶数队列
				if (qOdd.front()->right) qEven.push(qOdd.front()->right);
				if (qOdd.front()->left) qEven.push(qOdd.front()->left);
				// ！！！！记得弹出节点
				qOdd.pop();
			}
			// 存一次结果，清空tmp（注意，tmp可能为空，不能推入ans里）
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}
			// 偶数队列从右往左打印
			while (!qEven.empty()) {
				tmp.push_back(qEven.front()->val);
				// 正序进入奇数队列（）
				if (qEven.front()->left) qOdd.push(qEven.front()->left);
				if (qEven.front()->right) qOdd.push(qEven.front()->right);
				qEven.pop();
			}
			// 存一次结果，清空tmp（注意，tmp可能为空，不能推入ans里）
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
	// 换成栈来做可能好理解一点，栈1存奇数层，栈2存偶数层
	// 栈1 往 栈2 存的时候，先存左子节点再存右子节点，这样栈2的出栈顺序就是反序
	// 栈2 往 栈1 存的时候，先存右子节点再存左子节点，这样栈1的出栈顺序就是正序
	vector<vector<int>> Print(TreeNode* pRoot) {
		vector<vector<int>> ans;
		if (pRoot == nullptr) return ans;
		// 创建奇数行栈
		stack<TreeNode*> oddStack;
		oddStack.push(pRoot);
		// 创建偶数行栈
		stack<TreeNode*> evenStack;
		// 暂存
		vector<int> tmp;

		while (!oddStack.empty() || !evenStack.empty()) {
			// 奇数行不为空
			while (!oddStack.empty()) {
				// 取出节点
				TreeNode* node = oddStack.top();
				// 压入结果
				tmp.push_back(node->val);
				// 压入偶数栈
				if (node->left) evenStack.push(node->left);
				if (node->right) evenStack.push(node->right);
				oddStack.pop();
			}
			// 存一次结果（注意tmp可能为空）
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}
			// 偶数行不为空
			while (!evenStack.empty()) {
				// 取出节点
				TreeNode* node = evenStack.top();
				// 压入结果
				tmp.push_back(node->val);
				// 压入奇数栈
				if (node->right) oddStack.push(node->right);
				if (node->left) oddStack.push(node->left);
				evenStack.pop();
			}
			// 存一次结果（注意tmp可能为空）
			if (!tmp.empty()) {
				ans.push_back(tmp);
				tmp.clear();
			}

		}
		return ans;
	}
};

#endif // DEBUG2