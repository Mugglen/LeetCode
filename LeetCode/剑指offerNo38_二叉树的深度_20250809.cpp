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
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {

public:
	int TreeDepth(TreeNode* pRoot) {
		if (pRoot == nullptr) return 0;
		
		// 后序遍历，比较左右子树深度
		int depthL = (pRoot->left) ? TreeDepth(pRoot->left) : 0;
		int depthR = (pRoot->right) ? TreeDepth(pRoot->right) : 0;
		// 统计
		return max(depthL, depthR) + 1;
	}
};


#endif // DEBUG1