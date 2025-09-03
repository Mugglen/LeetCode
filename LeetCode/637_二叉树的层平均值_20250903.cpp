#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include <unordered_map>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        // 层次遍历
        vector<double> ans;
        if (root == nullptr) return ans;
        // 两个辅助队列
        queue<TreeNode*> qOdd;
        queue<TreeNode*> qEven;
        qOdd.push(root);
        while (!qOdd.empty() || !qEven.empty()) {
            // 层平均参数
            double average = 0;
            int count = 0;
            
            // 先清空奇数层
            while (!qOdd.empty()) {
                TreeNode* node = qOdd.front();
                qOdd.pop();
                if (node->left) qEven.push(node->left);
                if (node->right) qEven.push(node->right);
                average += node->val;
                count++;
            }
            // 奇数层平均
            average /= count;
            ans.push_back(average);
            average = 0;
            count = 0;
            // 先清空偶数层
            while (!qEven.empty()) {
                TreeNode* node = qEven.front();
                qEven.pop();
                if (node->left) qOdd.push(node->left);
                if (node->right) qOdd.push(node->right);
                average += node->val;
                count++;
            }
            // 偶数层平均(注意判断count是否为0，不然偶数层没东西的时候会直接跳到这一步)
            if (count) {
                average /= count;
                ans.push_back(average);
            }
        
        }
        return ans;
    }
};



#endif // DEBUG1