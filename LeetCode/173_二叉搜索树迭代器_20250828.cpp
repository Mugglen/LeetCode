#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <unordered_map>
#include <cstdlib>
#include <ctime>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {

private:
    vector<int> ans;
    int index; // ��������

public:

    // ûҪ��̬ά��BST������ֱ�����������Ա���������в���
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        ans.push_back(node->val);
        inorder(node->right);
    }


    BSTIterator(TreeNode* root) {
        index = 0;
        inorder(root);
    }

    int next() {
        return ans[index++]; // ע�⿴�����ӣ��Ƿ��ص�ǰ��Ԫ�أ�������++�ں���
    }

    bool hasNext() {
        return index < ans.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */


#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2

// ʹ�ø���ջ

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {

private:
    TreeNode* cur; // ��ǰ����λ��
    stack<TreeNode*> st; // ������������ջ

public:


    BSTIterator(TreeNode* root) : cur(root){}

    int next() {
        // �������
        // ����������
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }
        cur = st.top();// ȡ������
        st.pop();
        int ans = cur->val;
        cur = cur->right;
        return ans;
    }

    bool hasNext() {
        return cur != nullptr || !st.empty();
    }
};


#endif // DEBUG2