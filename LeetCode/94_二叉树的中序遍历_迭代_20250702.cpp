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
    // ��ʹ�õ�����д�������������Ҫ����ָ��ı������������ʽڵ㣬ջ����������ڵ��ϵ�Ԫ�ء�
    vector<int> inorderTraversal(TreeNode* root) {

        // ������������ջ
        vector<int> res;
        stack<TreeNode*> st;

        // ��ʼ������ָ��
        TreeNode* cur = root;

        // ��ʼ���ʣ������ݴ�����Ϊ�����򣬷��ʵ�ͬʱ����һ�鴦������ѹ��ջ��
        while (cur != nullptr || !st.empty()) {
            
            // �жϵ�ǰ���ڷ��ʻ��ǿ��Խ��д���
            if (cur != nullptr) {
                st.push(cur);
                // �ƶ�����ָ��
                cur = cur->left;
            
            }
            else {
                // ��ʱcur���Ƶ��˿ɴ���ڵ����nullptr����Ҫ���¸�ֵ
                cur = st.top();
                st.pop();
                
                // ������
                res.push_back(cur->val);

                // (�ؼ����裡�������������������û����������û�еĻ������Ϊnullptr,�еĻ���ѹ��ջ��)
                cur = cur->right;
            
            }
        }
        return res;
    }
};




#endif // DEBUG



