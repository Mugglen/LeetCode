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
        // ��ʼ����Ϊ��
        int ans = 0;
        // ����ݹ麯��
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            // �߽��ж�(Ϊɶ��-1����0��)����-1����Ҷ�ӽڵ��ʱ��lenL��lenRΪ-1�����+2�͸պ���0��
            if (node == nullptr)return -1;
            int lenL = dfs(node->left);
            int lenR = dfs(node->right);
            ans = max(ans, lenL + lenR + 2); // �������������������������·��
            return max(lenL, lenR) + 1; // ���ص�ǰ�ڵ�����·������
            };
        // ��������
        dfs(root);
        return ans;
    }
};

#endif // DEBUG