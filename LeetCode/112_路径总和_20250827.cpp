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
        // �ݹ�߽�(ע�Ȿ��Ҫ�����ж�Ҷ�ӽڵ㣬ֱ����������ôд�Ǵ��)
        if (root == nullptr) return targetSum == 0;
        // �ݹ�
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
        
    }
};

class Solution { // ����ǶԵ�
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // �ݹ�߽�(ע�Ȿ��Ҫ�����ж�Ҷ�ӽڵ�)
        if (root == nullptr) return false;
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) return targetSum == 0;
        // �ݹ�(ע���solution1�����𣬶�targetSum���ж�������һ��)
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);

    }
};



#endif // DEBUG1