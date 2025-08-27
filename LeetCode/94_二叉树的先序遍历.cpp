#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>

// 二叉树节点结构体
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 解析输入字符串为 vector<string>
std::vector<std::string> parseInput(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) {
        // 去除前后的空格
        while (!token.empty() && token.front() == ' ') token.erase(0, 1);
        while (!token.empty() && token.back() == ' ') token.pop_back();
        result.push_back(token);
    }
    return result;
}

/**
 * 根据层次遍历的字符串数组构建二叉树
 * @param data 层次遍历的节点值数组，用"null"表示空节点
 * @return 构建好的二叉树根节点
 */
TreeNode* buildTree(const std::vector<std::string>& data) {
    // 1. 处理空树或根节点为空的情况
    if (data.empty() || data[0] == "null") {
        return nullptr;  // 返回空指针表示空树
    }

    // 2. 创建根节点（第一个元素一定是根节点）
    TreeNode* root = new TreeNode(std::stoi(data[0]));  // 将字符串转换为整数
    std::queue<TreeNode*> q;  // 辅助队列：用于按层次构建树节点
    q.push(root);  // 根节点入队
    int i = 1;     // 从第二个元素开始处理

    // 3. 层次遍历构建树
    while (!q.empty() && i < data.size()) {
        TreeNode* node = q.front();  // 取出当前待处理的父节点
        q.pop();  // 已取出，从队列中移除

        // 3.1 构建左子节点
        if (i < data.size() && data[i] != "null") {
            node->left = new TreeNode(std::stoi(data[i]));  // 创建左子节点
            q.push(node->left);  // 左子节点入队，后续处理其子节点
        }
        i++;  // 移动到下一个数据元素

        // 3.2 构建右子节点
        if (i < data.size() && data[i] != "null") {
            node->right = new TreeNode(std::stoi(data[i]));  // 创建右子节点
            q.push(node->right);  // 右子节点入队，后续处理其子节点
        }
        i++;  // 移动到下一个数据元素
    }

    // 4. 返回构建好的二叉树根节点
    return root;
}

// 先序遍历（Preorder）打印树的节点值
void preorder(TreeNode* root, std::vector<int>& result) {
    //if (!root) return;
    if (root == nullptr) return;
    //std::cout << root->val << " ";
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

//#define DEBUG
#ifdef DEBUG

int main() {
    std::string line;

    // 🌟 示例输入方式（输入层序遍历，用逗号分隔）
    // 示例：1,null,2,3 表示如下二叉树：
    //     1
    //      \
    //       2
    //      /
    //     3
    //
    // 输入行：1,null,2,3
    std::cout << "请输入树的层序遍历（例如: 1,null,2,3）:" << std::endl;
    std::getline(std::cin, line);

    std::vector<std::string> nodes = parseInput(line);
    TreeNode* root = buildTree(nodes);
    std::vector<int> result;

    std::cout << "先序遍历结果为: " << std::endl;
    preorder(root, result);

    for (int val : result) { 
        std::cout << val <<  std::endl; 
    }


    return 0;
}

#endif
