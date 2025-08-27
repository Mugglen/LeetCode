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
    // 可能可以先层次遍历，但是推入队列的时候先右后左
    // 当前使用swap函数和递归
    TreeNode* Mirror(TreeNode* pRoot) {
        if (pRoot == nullptr) return pRoot;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return pRoot;
    }
};


#endif // DEBUG1