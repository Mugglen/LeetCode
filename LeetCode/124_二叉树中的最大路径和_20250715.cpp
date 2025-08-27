
#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/binary-tree-maximum-path-sum/solutions/2227021/shi-pin-che-di-zhang-wo-zhi-jing-dpcong-n9s91/?envType=study-plan-v2&envId=top-100-liked

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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN; // 初始化结果为负无穷
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
			if (node == nullptr)return 0; // 如果节点为空，返回0
            int l_val = dfs(node->left);
            int r_val = dfs(node->right);
			ans = max(ans, l_val + r_val + node->val); // 更新最大路径和
			return max(max(l_val, r_val) + node->val, 0);// 返回当前节点的最大路径和，若为负则返回0
            };
        dfs(root);
		return ans; // 返回最大路径和
    }
};

#endif // DEBUG