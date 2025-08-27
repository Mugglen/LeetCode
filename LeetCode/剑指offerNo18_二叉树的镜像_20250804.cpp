#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1



struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // ���ܿ����Ȳ�α���������������е�ʱ�����Һ���
    // ��ǰʹ��swap�����͵ݹ�
    TreeNode* Mirror(TreeNode* pRoot) {
        if (pRoot == nullptr) return pRoot;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};


#endif // DEBUG1