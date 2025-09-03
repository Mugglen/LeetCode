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
        // ��α���
        vector<double> ans;
        if (root == nullptr) return ans;
        // ������������
        queue<TreeNode*> qOdd;
        queue<TreeNode*> qEven;
        qOdd.push(root);
        while (!qOdd.empty() || !qEven.empty()) {
            // ��ƽ������
            double average = 0;
            int count = 0;
            
            // �����������
            while (!qOdd.empty()) {
                TreeNode* node = qOdd.front();
                qOdd.pop();
                if (node->left) qEven.push(node->left);
                if (node->right) qEven.push(node->right);
                average += node->val;
                count++;
            }
            // ������ƽ��
            average /= count;
            ans.push_back(average);
            average = 0;
            count = 0;
            // �����ż����
            while (!qEven.empty()) {
                TreeNode* node = qEven.front();
                qEven.pop();
                if (node->left) qOdd.push(node->left);
                if (node->right) qOdd.push(node->right);
                average += node->val;
                count++;
            }
            // ż����ƽ��(ע���ж�count�Ƿ�Ϊ0����Ȼż����û������ʱ���ֱ��������һ��)
            if (count) {
                average /= count;
                ans.push_back(average);
            }
        
        }
        return ans;
    }
};



#endif // DEBUG1