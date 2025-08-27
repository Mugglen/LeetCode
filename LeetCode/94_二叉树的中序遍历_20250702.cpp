/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG

struct TreeNode {

    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x) {};

};


class Solution {
public:

    void traversal(TreeNode* cur, vector<int>& res) {

        // 异常处理
        if (cur == NULL)return;

        // 中序遍历

        traversal(cur->left, res);
        res.push_back(cur->val);
        traversal(cur->right, res);
        


    }


    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;

        traversal(root, res);

        return res;

    }
};




#endif // DEBUG



