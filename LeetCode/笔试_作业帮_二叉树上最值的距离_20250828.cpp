#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;

//有一棵二叉树，树上每个点标有权值，权值各不相同，
//请设计一个算法算出权值最大的叶节点到权值最小的叶节点的距离。
//二叉树每条边的距离为1，一个节点经过多少条边到达另一个节点为这两个节点之间的距离给定二叉树的根节点root，
//请返回所求距离

// 输入{2， 1， 3}
// 返回 2

//#define DEBUG
#ifdef DEBUG

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int getDis(TreeNode* root) {
        if (!root) return 0;
        // 1) 找到权值最小叶子与权值最大叶子
        minNode = maxNode = nullptr;
        minVal = INT_MAX; maxVal = INT_MIN;
        findLeaves(root);

        // 2) LCA
        TreeNode* c = lca(root, minNode, maxNode);

        // 3) 距离 = dist(LCA, minLeaf) + dist(LCA, maxLeaf)
        return distFrom(c, minNode) + distFrom(c, maxNode);
    }

private:
    TreeNode* minNode;
    TreeNode* maxNode;
    int minVal, maxVal;

    void findLeaves(TreeNode* u) {
        if (!u) return;
        if (!u->left && !u->right) {
            if (u->val < minVal) { minVal = u->val; minNode = u; }
            if (u->val > maxVal) { maxVal = u->val; maxNode = u; }
        }
        findLeaves(u->left);
        findLeaves(u->right);
    }

    TreeNode* lca(TreeNode* r, TreeNode* a, TreeNode* b) {
        if (!r || r == a || r == b) return r;
        TreeNode* L = lca(r->left, a, b);
        TreeNode* R = lca(r->right, a, b);
        if (L && R) return r;
        return L ? L : R;
    }

    int distFrom(TreeNode* r, TreeNode* t) {
        if (!r) return -1;
        if (r == t) return 0;
        int dl = distFrom(r->left, t);
        if (dl != -1) return dl + 1;
        int dr = distFrom(r->right, t);
        if (dr != -1) return dr + 1;
        return -1;
    }
};
#endif // DEBUG
