#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
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

// O(n)��BFS����
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


#endif // DEBUG1



#define DEBUG2
#ifdef DEBUG2


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ��������¼�����ö��������ʵĽⷨ
// �ݹ��ж����������ǲ���������ȫ���������Ϳ���ֱ���ù�ʽ
// ��DFS�������Ż�
// https://leetcode.cn/problems/count-complete-tree-nodes/solutions/1812445/by-carlsun-2-bwlp/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        // ��ʼ������ָ��
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        // Ҫ���������������ȣ����������Ҳ����
        int leftDepth = 0, rightDepth = 0; // ��ʼ��Ϊ0Ϊ��������ָ��
        while (left) {
            left = left->left;
            leftDepth++;
        }
        while (right) {
            right = right->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth) { return (2 << leftDepth) - 1; }
        // �����������ȫ�������� �ݹ�����
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


#endif // DEBUG2