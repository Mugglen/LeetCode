#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;


//#define DEBUGs
#ifdef DEBUG

// 同hot100 题105
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param preOrder int整型vector
     * @param vinOrder int整型vector
     * @return TreeNode类
     */
    // 题目提到了没有重复元素
    // 直接想到的思路：
    // ①前序遍历找到根节点
    // ②中序遍历分出左右子树
    // ③再前序遍历找到左右子树根节点
    // ④拼接当前根节点和左右子树根节点
    // ⑤子问题变成对左右子树进行操作（需要传递的参数：子树根节点索引，子树在 中序 遍历数组中的范围）
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {

        // 使用哈希表，保存元素在中序遍历中的索引
        unordered_map<int, int> map;
        for (int i = 0; i < vinOrder.size(); i++) {
            map[vinOrder[i]] = i;
        }

        // 使用递归
        // 函数签名为（在前序遍历中根节点索引， 中序遍历中左边界， 中序遍历中右边界，需要后两个指标标记下一个根节点位置）
        // 传入根节点索引，在递归函数里构造后返回
        //auto constructor = [&](this auto&& constructor, int root, int left, int right) -> TreeNode* {
        function<TreeNode*(int, int, int)> constructor = [&](int root, int left, int right) -> TreeNode* {
            // 边界处理
            if (left > right) return nullptr;
            // 建树(root索引使用前序遍历中的位置，这样递归启动的时候第一个参数可以固定是0，不然要多一个在中序中找root位置操作，多此一举)
            TreeNode* node = new TreeNode(preOrder[root]);
            // 现在要找左右子树的根节点（这里需要获取根节点在中序遍历中的位置，就可以用哈希表来加速，来确定左右子树的范围，用于判断递归终止条件）
            // 取出当前根节点的索引
            int rootIndex = map[preOrder[root]];
            // 递归调用
            node -> left = constructor(root + 1, left, rootIndex - 1);
            node->right = constructor(root + rootIndex - left + 1, rootIndex + 1, right);

            return node;
            };

        // 启动递归
        return constructor(0, 0, preOrder.size() - 1);
    }
};
#endif // DEBUG
