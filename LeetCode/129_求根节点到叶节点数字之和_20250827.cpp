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

// https://leetcode.cn/problems/sum-root-to-leaf-numbers/solutions/2730644/jian-ji-xie-fa-pythonjavacgojsrust-by-en-gbu9/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int sumNumbers(TreeNode* root, int x = 0) {
        // µÝ¹é±ß½ç
        if (root == nullptr) return 0;
        // ÏÈÐò
        x = x * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) return x;
        return sumNumbers(root->left, x) + sumNumbers(root->right, x);
    }
};

#endif // DEBUG1