#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

public:
    // 直观比较root的左右子树
    bool compare(TreeNode* left, TreeNode* right) {

        // 不对称的三种情况
        // 首先排除双空节点，单空节点
        if (left == nullptr && right == nullptr) return true;  // 修改为 true，两个节点都为空，认为对称（注意这里，之前写错了）
        if (left == nullptr || right == nullptr) return false; // 只要一个为空，返回 false

        // 再考虑root左右子树数值不同
        else if (left->val != right->val) return false;

        // 递归逻辑开始（注意看！！！！！！是左子树的左和右子树的右比）
        // 分别比较外侧节点和内侧节点
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }

    // 复合leetCode参数要求
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }

    // 层次输入构造二叉树（使用队列进行辅助）
    TreeNode* buildTree(const vector<string>& nodes) {
        if (nodes.empty() || nodes[0] == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(nodes[0])); // 也是属于sstream库内
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // 处理左孩子（先左后右，注意层次遍历的顺序）
            if (i < nodes.size() && nodes[i] != "null") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left); // 用来存放当前实例化的左孩子
            }
            i++;

            if (i < nodes.size() && nodes[i] != "null") {
                curr->right = new TreeNode(stoi(nodes[i]));
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }

    // 解析输入字符串为整数数组(注意！！！！！！！输入中文的逗号会导致getline分词失败，最后只有一个树节点)
    vector<string> inputProcess(string input) {
        vector<string> result;
        stringstream ss(input);
        string token;
        while (getline(ss, token, ',')) {
            result.push_back(token);
            //cout << token << endl;
        }
        
        return result;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {
    Solution solution;
    string input;

    // 获取输入
    getline(cin, input);

    // 解析输入并构造二叉树
    vector<string> nodes = solution.inputProcess(input);
    TreeNode* root = solution.buildTree(nodes);

    // 判断二叉树是否对称
    string compareResult = solution.isSymmetric(root) ? "true" : "false";

    cout << compareResult << endl;

    return 0;
}

#endif // DEBUG
