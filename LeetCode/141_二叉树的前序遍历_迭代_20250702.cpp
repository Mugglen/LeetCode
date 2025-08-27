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
#include <stack>
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

    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> res;
        stack<TreeNode*> st;

        // 异常处理（不要忘了！！！！！！！！）
        if (root == nullptr)return res;

        // 迭代法循环入栈，注意当前节点先入栈，然后右节点再到左节点，这样出栈的时候就是前序
        st.push(root);

        while (!st.empty()) {
            // 取出栈顶
            TreeNode* cur = st.top();
            st.pop();

            // 存入结果
            res.push_back(cur->val);

            // 检查并加入右左子树
            if (cur->right)st.push(cur->right);
            if (cur->left)st.push(cur->left);
        
        }




        return res;

    }
};




#endif // DEBUG



