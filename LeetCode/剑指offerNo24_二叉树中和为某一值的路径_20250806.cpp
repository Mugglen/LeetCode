#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


struct TreeNode {
int val;
struct TreeNode *left;
struct TreeNode *right;
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    // 需要递归遍历二叉树，
    // 只能从父节点往子节点走，和hot100里124最大路径和不太一样,而且好像只能从根节点开始
    // 子问题：为左右子树中有没有target - root->val的和的路径，到递归终点再判断，中间保存结果，不是判断满足条件后回溯的路上保存结果
    // 递归返回值：没有
    // （注意节点值可以为负数，没有说半路上满足条件了的子路径算不算，比如target = 10时有条路【5，5，1，-1】，里面【5，5】好像在这题里不算）
    vector<vector<int> > FindPath(TreeNode* root, int target) {
        
        // 暂存结果(感觉有点回溯的性质)
        vector<int> tmp;
        vector<vector<int>> ans;
        // 内部递归
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int target) {
            // 错误终止条件1：递归到中途但target < 0,直接返回，不保存（注意本题节点值可以为负数，得继续往下递归）
            // 错误终止条件1：target为0，保存结果后直接返回（这样会在满足条件的节点返回两次）
            // 终止条件1：如果当前是叶子节点，target为root->val，保存结果后直接返回
            // 终止条件2(这个直接合并到下面左右节点的判断上，空节点直接不遍历了)：递归到叶子下的空节点但target != 0,直接返回，不保存
            
            // 空节点返回(用来处理递归启动时放入空节点)
            if (root == nullptr) return;
            // 非空先压入结果
            tmp.push_back(root->val);
            // 终止条件1
            if (root->left == nullptr && root->right == nullptr && target == root->val) {
                ans.push_back(tmp);
                // 注意!!!!!这里也要恢复现场
                tmp.pop_back();
                return;
            }
            else { 
                if (root->left) dfs(root->left, target - root->val);
                if (root->right) dfs(root->right, target - root->val);
            }
            // 恢复现场
            tmp.pop_back();
            };
        // 启动递归
        dfs(root, target);
        return ans;
    }
};


#endif // DEBUG1