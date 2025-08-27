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

        // �쳣������Ҫ���ˣ�����������������
        if (root == nullptr)return res;

        // ������ѭ����ջ��ע�⵱ǰ�ڵ�����ջ��Ȼ���ҽڵ��ٵ���ڵ㣬������ջ��ʱ�����ǰ��
        st.push(root);

        while (!st.empty()) {
            // ȡ��ջ��
            TreeNode* cur = st.top();
            st.pop();

            // ������
            res.push_back(cur->val);

            // ��鲢������������
            if (cur->right)st.push(cur->right);
            if (cur->left)st.push(cur->left);
        
        }




        return res;

    }
};




#endif // DEBUG



