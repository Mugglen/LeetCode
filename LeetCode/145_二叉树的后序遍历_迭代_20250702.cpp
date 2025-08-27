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


    // https://www.programmercarl.com/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E8%BF%AD%E4%BB%A3%E9%81%8D%E5%8E%86.html#%E6%80%9D%E8%B7%AF
    // 注意和前序遍历不一样，一开始访问的不是中间节点
    // 在使用迭代法写后序遍历，单可以在前序的基础上修改，。
    vector<int> postorderTraversal(TreeNode* root) {

        // 创建结果数组和栈
        vector<int> res;
        stack<TreeNode*> st;

        // 异常处理
        if (root == nullptr)return res;

        // 初始压栈
        st.push(root);

        // 开始访问，和数据处理（因为是后序，访问的同时不能一块处理，得先压入栈）
        while (!st.empty()) {

            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);

            // 关键点，修改压栈顺序，出栈顺序变为中右左，然后reverse
            if (cur->left)st.push(cur->left);
            if (cur->right)st.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};




#endif // DEBUG



