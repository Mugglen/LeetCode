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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ！！！！！！！！！这个写崩了，思路不清晰，计算步骤也都扭在一起了，
// 还是看DEBUG2吧
class Solution {
public:
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // 后面需要快速查询根节点在中序中的索引
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return buildTreeCore(postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder);

    }


    // 添加一个建树函数,每次迭代需要推算出左右子树在中序遍历中的范围和对应的根节点在后序遍历中的索引
    // 参数应该是当前子树根节点的索引
    TreeNode* buildTreeCore(int root, int left, int right, vector<int>& postorder, vector<int>& inorder) {
        // 边界处理
        if (left > right) return nullptr;
        // 建树
        TreeNode* newTree = new TreeNode(postorder[root]);

        newTree->left = buildTreeCore(root - 1 - (right - map[postorder[root]] + 1 + 1), left, map[postorder[root]] + 1, postorder, inorder);
        newTree->right = buildTreeCore(root - 1, map[postorder[root]] - 1, right, postorder, inorder);
    
        return newTree;
    }

};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 建立中序遍历的值到索引的映射
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return buildTreeCore(postorder, inorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTreeCore(vector<int>& postorder, vector<int>& inorder,
        int inStart, int inEnd, int postStart, int postEnd) {
        // 边界条件
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        // 后序遍历的最后一个元素是根节点
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // 找到根节点在中序遍历中的位置
        int rootIndex = map[rootVal];

        // 计算左子树的节点个数（注意这里是拿根节点索引减去的inStart，
        // 根节点不是左子树的一部分，所以不用+1就是左子树长度）
        int leftSize = rootIndex - inStart;

        // 递归构建左子树
        // 左子树在后序遍历中的范围：[postStart, postStart + leftSize - 1]
        // 左子树在中序遍历中的范围：[inStart, rootIndex - 1]
        root->left = buildTreeCore(postorder, inorder, 
                                    inStart, rootIndex - 1,
                                    postStart, postStart + leftSize - 1);

        // 递归构建右子树
        // 右子树在后序遍历中的范围：[postStart + leftSize, postEnd - 1]
        // 右子树在中序遍历中的范围：[rootIndex + 1, inEnd]
        root->right = buildTreeCore(postorder, inorder, 
                                    rootIndex + 1, inEnd,
                                    postStart + leftSize, postEnd - 1);

        return root;
    }
};

#endif // DEBUG2