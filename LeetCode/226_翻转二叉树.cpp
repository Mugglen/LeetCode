#include <utility>
#include <vector>
//#include <string>
#include <sstream>
#include <iostream>
#include <queue>


// �����Ŀʹ��ǰ������ͺ�����������ԣ�Ψ��������������㣬
// ��Ϊ����������ĳЩ�ڵ�����Һ��ӷ�ת�����Σ�������ֽ��һ�����������


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
		std::swap(root->left, root->right); // ��utility����Ĳ���algorithm
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}

	std::vector<std::string> inputProcess(std::string input) {
		std::stringstream ss(input);
		std::string node;
		std::vector<std::string> nodes;

		while (getline(ss, node, ',')) { //ע��ss����string���ͣ���Ȼgetline�ᱨ��
			nodes.push_back(node);
		}
		return nodes;
	}

	TreeNode* buildTree(const std::vector<std::string>& nodes) {
		if (nodes.empty() || nodes[0] == "null") return nullptr;

		TreeNode* root = new TreeNode(std::stoi(nodes[0]));
		std::queue<TreeNode*> q; //����д��queque�ˣ���queue
		q.push(root);

		int i = 1; // ע����i����1���ǵ���0����Ȼ���ڵ㱻���°�������
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
	
	// ��α�����ӡ
	void levelOrderTraversal(TreeNode* root) {
		if (!root) return;  // ����ֱ�ӷ���

		std::queue<TreeNode*> q;
		q.push(root);  // ���ڵ����

		while (!q.empty()) {
			TreeNode* current = q.front();  // ȡ�����׽ڵ�
			q.pop();
			std::cout << current->val << " ";  // ��ӡ��ǰ�ڵ�ֵ

			// ���ӽڵ���ӣ�������ڣ�
			if (current->left) {
				q.push(current->left);
			}
			// ���ӽڵ���ӣ�������ڣ�
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
	std::cout << "���������Ĳ�����������ŷָҪ�ӿո�����: 1,null,2,3��:" << std::endl;
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

