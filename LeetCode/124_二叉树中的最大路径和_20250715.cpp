
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
        int ans = INT_MIN; // ��ʼ�����Ϊ������
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
			if (node == nullptr)return 0; // ����ڵ�Ϊ�գ�����0
            int l_val = dfs(node->left);
            int r_val = dfs(node->right);
			ans = max(ans, l_val + r_val + node->val); // �������·����
			return max(max(l_val, r_val) + node->val, 0);// ���ص�ǰ�ڵ�����·���ͣ���Ϊ���򷵻�0
            };
        dfs(root);
		return ans; // �������·����
    }
};

#endif // DEBUG