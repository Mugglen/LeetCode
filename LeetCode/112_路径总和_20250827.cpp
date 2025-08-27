#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>
using namespace std;


#define DEBUG1
#ifdef DEBUG1



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 递归边界(注意本题要单独判断叶子节点，直接像下面这么写是错的)
        if (root == nullptr) return targetSum == 0;
        // 递归
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        
    }
};

class Solution { // 这个是对的
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 递归边界(注意本题要单独判断叶子节点)
        if (root == nullptr) return false;
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) return targetSum == 0;
        // 递归(注意和solution1的区别，对targetSum的判断上移了一层)
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);

    }
};



#endif // DEBUG1