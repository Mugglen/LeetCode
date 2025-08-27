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
    // ע���ǰ�������һ����һ��ʼ���ʵĲ����м�ڵ�
    // ��ʹ�õ�����д�����������������ǰ��Ļ������޸ģ���
    vector<int> postorderTraversal(TreeNode* root) {

        // ������������ջ
        vector<int> res;
        stack<TreeNode*> st;

        // �쳣����
        if (root == nullptr)return res;

        // ��ʼѹջ
        st.push(root);

        // ��ʼ���ʣ������ݴ�����Ϊ�Ǻ��򣬷��ʵ�ͬʱ����һ�鴦������ѹ��ջ��
        while (!st.empty()) {

            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);

            // �ؼ��㣬�޸�ѹջ˳�򣬳�ջ˳���Ϊ������Ȼ��reverse
            if (cur->left)st.push(cur->left);
            if (cur->right)st.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};




#endif // DEBUG



