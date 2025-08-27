#include <vector>
#include <iostream>


struct treeNode {
	int val;
	treeNode* left;
	treeNode* right;
	treeNode(int x) : val(x), left(nullptr), right(nullptr) {}

};


class Solution {
public:
	void inOrder(treeNode* root, std::vector<int>& result) {
		if (root == nullptr) return;
		
		inOrder(root->left, result);
		result.push_back(root->val);
		inOrder(root->right, result);
	
	
	}

	std::vector<int> inorderTraversal(treeNode* root) {
		std::vector<int> result;
		inOrder(root, result);
		return result;
	
	
	}


};

//#define DEBUG
#ifdef DEBUG

int main() {
	




}



#endif