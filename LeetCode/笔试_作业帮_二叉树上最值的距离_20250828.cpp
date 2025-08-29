#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;

//��һ�ö�����������ÿ�������Ȩֵ��Ȩֵ������ͬ��
//�����һ���㷨���Ȩֵ����Ҷ�ڵ㵽Ȩֵ��С��Ҷ�ڵ�ľ��롣
//������ÿ���ߵľ���Ϊ1��һ���ڵ㾭���������ߵ�����һ���ڵ�Ϊ�������ڵ�֮��ľ�������������ĸ��ڵ�root��
//�뷵���������

// ����{2�� 1�� 3}
// ���� 2

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
        // 1) �ҵ�Ȩֵ��СҶ����Ȩֵ���Ҷ��
        minNode = maxNode = nullptr;
        minVal = INT_MAX; maxVal = INT_MIN;
        findLeaves(root);

        // 2) LCA
        TreeNode* c = lca(root, minNode, maxNode);

        // 3) ���� = dist(LCA, minLeaf) + dist(LCA, maxLeaf)
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
