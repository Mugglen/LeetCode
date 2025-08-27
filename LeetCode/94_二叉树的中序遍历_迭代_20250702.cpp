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
    // 在使用迭代法写中序遍历，就需要借用指针的遍历来帮助访问节点，栈则用来处理节点上的元素。
    vector<int> inorderTraversal(TreeNode* root) {

        // 创建结果数组和栈
        vector<int> res;
        stack<TreeNode*> st;

        // 初始化访问指针
        TreeNode* cur = root;

        // 开始访问，和数据处理（因为是中序，访问的同时不能一块处理，得先压入栈）
        while (cur != nullptr || !st.empty()) {
            
            // 判断当前是在访问还是可以进行处理
            if (cur != nullptr) {
                st.push(cur);
                // 移动访问指针
                cur = cur->left;
            
            }
            else {
                // 此时cur被移到了可处理节点的左nullptr，需要重新赋值
                cur = st.top();
                st.pop();
                
                // 存入结果
                res.push_back(cur->val);

                // (关键步骤！！！！！！！！检查有没有右子树，没有的话这里会为nullptr,有的话就压入栈里)
                cur = cur->right;
            
            }
        }
        return res;
    }
};




#endif // DEBUG



