#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
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

// O(n)的BFS方法
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


#endif // DEBUG1



#define DEBUG2
#ifdef DEBUG2


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// 代码随想录中利用二叉树性质的解法
// 递归判断左右子树是不是满的完全二叉树，就可以直接用公式
// 对DFS方法的优化
// https://leetcode.cn/problems/count-complete-tree-nodes/solutions/1812445/by-carlsun-2-bwlp/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        // 初始化工作指针
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // 要保存左子树左侧深度，和右子树右侧深度
        int leftDepth = 0, rightDepth = 0; // 初始化为0为了下面求指数
        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right) {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) { return (2 << leftDepth) - 1; }
        // 如果不是满完全二叉树， 递归左右
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


#endif // DEBUG2