#include <utility>
#include <vector>
//#include <string>
#include <sstream>
#include <iostream>
#include <queue>


// 这道题目使用前序遍历和后序遍历都可以，唯独中序遍历不方便，
// 因为中序遍历会把某些节点的左右孩子翻转了两次！建议拿纸画一画，就理解了


struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};

class Solution {

public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr) return root;
		std::swap(root->left, root->right); // 是utility库里的不是algorithm
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}

	std::vector<std::string> inputProcess(std::string input) {
		std::stringstream ss(input);
		std::string node;
		std::vector<std::string> nodes;

		while (getline(ss, node, ',')) { //注意ss得是string类型，不然getline会报错
			nodes.push_back(node);
		}
		return nodes;
	}

	TreeNode* buildTree(const std::vector<std::string>& nodes) {
		if (nodes.empty() || nodes[0] == "null") return nullptr;

		TreeNode* root = new TreeNode(std::stoi(nodes[0]));
		std::queue<TreeNode*> q; //别再写成queque了，是queue
		q.push(root);

		int i = 1; // 注意是i等于1不是等于0，不然根节点被重新包含两次
		while (!q.empty() && i < nodes.size()) {
			TreeNode* curr = q.front();
			q.pop();

			if (i < nodes.size() && nodes[i] != "null") {
				curr->left = new TreeNode(std::stoi(nodes[i]));
				q.push(curr->left);
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
	
	// 层次遍历打印
	void levelOrderTraversal(TreeNode* root) {
		if (!root) return;  // 空树直接返回

		std::queue<TreeNode*> q;
		q.push(root);  // 根节点入队

		while (!q.empty()) {
			TreeNode* current = q.front();  // 取出队首节点
			q.pop();
			std::cout << current->val << " ";  // 打印当前节点值

			// 左子节点入队（如果存在）
			if (current->left) {
				q.push(current->left);
			}
			// 右子节点入队（如果存在）
			if (current->right) {
				q.push(current->right);
			}
		}
	}
};

//#define DEBUG
#ifdef DEBUG
int main() {
	Solution solution;
	std::cout << "请输入树的层序遍历，逗号分割不要加空格（例如: 1,null,2,3）:" << std::endl;
	std::string input;
	getline(std::cin, input);
	std::vector<std::string> nodes = solution.inputProcess(input);
	TreeNode* root = solution.buildTree(nodes);
	solution.levelOrderTraversal(root);
	std::cout << std::endl;
	TreeNode* rootInvert = solution.invertTree(root);
	solution.levelOrderTraversal(rootInvert);
}



#endif // DEBUG

