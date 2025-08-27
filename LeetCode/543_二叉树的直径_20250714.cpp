#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG


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
    int diameterOfBinaryTree(TreeNode* root) {
        // 初始化答案为空
        int ans = 0;
        // 定义递归函数
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            // 边界判断(为啥是-1不是0呢)（是-1，到叶子节点的时候lenL与lenR为-1，最后+2就刚好是0）
            if (node == nullptr)return -1;
            int lenL = dfs(node->left);
            int lenR = dfs(node->right);
            ans = max(ans, lenL + lenR + 2); // 加上所有子树上这个根的两条路径
            return max(lenL, lenR) + 1; // 返回当前节点的最大路径长度
            };
        // 启动遍历
        dfs(root);
        return ans;
    }
};

#endif // DEBUG