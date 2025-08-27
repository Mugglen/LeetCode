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

// 牛客上题目无了，leetcode还有
// https ://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/submissions/653117624/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	// 二叉搜索树的第k大节点，其实就是中序遍历的倒数第k个节点
    // 封装一层，返回中序遍历
    void findTargetNodeCore(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
		findTargetNodeCore(root->left, ans); 
		ans.push_back(root->val);
        findTargetNodeCore(root->right, ans);
    }


    int findTargetNode(TreeNode* root, int cnt) {
        // 题目要求保证有节点，且数量大于cnt，这里不处理也行
		if (root == nullptr) return -1;
        vector<int>ans;
        findTargetNodeCore(root, ans);
		// 找倒数cnt个节点
        if (cnt > ans.size()) return -1; // 题目保证有节点，且数量大于cnt，这里不处理也行
		return ans[ans.size() - cnt];

    }
};



#endif // DEBUG2