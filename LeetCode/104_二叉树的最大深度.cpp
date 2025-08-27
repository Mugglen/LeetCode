#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <iostream>


// 根节点高度就是二叉树的最大深度
//​时间复杂度：O(n)，每个节点访问一次。
//​空间复杂度：O(h)，h为树高（递归栈空间）。

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};


class Solution {

public:

	// 后续遍历方式来求最大深度（后序比较好理解，可以直观地想到需要知道左右子树的深度后才能比较）
	int getdepth(TreeNode* node) {
		
		if (node == nullptr) return 0;
		int leftdepth = getdepth(node->left);
		int rightdepth = getdepth(node->right);
		int depth = 1 + std::max(leftdepth, rightdepth); // 递归结束后从后往前加
		return depth;
	
	
	}

	int maxDepth(TreeNode* root) {
		
		return getdepth(root);
	}

	// 层次输入处理(注意c++没有split方法应该)
	std::vector<std::string> levelOrderInput(const std::string& input) {
		std::vector<std::string> nodes;
		std::stringstream ss(input); // 注意这个是<sstream>库里的，不是<string>
		std::string item;

		while (getline(ss, item, ',')) {
			nodes.push_back(item);
		}
		return nodes;
	}

	// 层次输入构造二叉树（使用队列进行辅助）
	TreeNode* buildTree(const std::vector<std::string>& nodes) {
		if (nodes.empty() || nodes[0] == "null") return nullptr;

		TreeNode* root = new TreeNode(std::stoi(nodes[0])); // 也是属于sstream库内
		std::queue<TreeNode*> q;
		q.push(root);

		int i = 1;
		while (!q.empty() && i < nodes.size()) {
			TreeNode* curr = q.front();
			q.pop();
			
			// 处理左孩子（先左后右，注意层次遍历的顺序）
			if (i < nodes.size() && nodes[i] != "null") {
				curr->left = new TreeNode(std::stoi(nodes[i]));
				q.push(curr->left); // 用来存放当前实例化的左孩子
			
			}
			i++;

			if (i < nodes.size() && nodes[i] != "null") {
				curr->right = new TreeNode(std::stoi(nodes[i]));
				q.push(curr->right);
			}
			i++;
		}
		return root;
	
	}


};

//#define DEBUGs
#ifdef DEBUG

int main() {

	Solution solution;
	std::cout << "请输入树的层序遍历，逗号分割不要加空格（例如: 1,null,2,3）:" << std::endl; // cout不要写成coutt
	std::string input;

	getline(std::cin, input);

	std::vector<std::string> nodes = solution.levelOrderInput(input);

	TreeNode* root = solution.buildTree(nodes);

	int maxDepth = solution.getdepth(root);
	std::cout << maxDepth << std::endl;

	return 0;

}




#endif