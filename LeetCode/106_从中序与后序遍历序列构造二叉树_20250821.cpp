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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// ���������������������д���ˣ�˼·�����������㲽��Ҳ��Ť��һ���ˣ�
// ���ǿ�DEBUG2��
class Solution {
public:
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        // ������Ҫ���ٲ�ѯ���ڵ��������е�����
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return buildTreeCore(postorder.size() - 1, 0, inorder.size() - 1, postorder, inorder);

    }


    // ���һ����������,ÿ�ε�����Ҫ�����������������������еķ�Χ�Ͷ�Ӧ�ĸ��ڵ��ں�������е�����
    // ����Ӧ���ǵ�ǰ�������ڵ������
    TreeNode* buildTreeCore(int root, int left, int right, vector<int>& postorder, vector<int>& inorder) {
        // �߽紦��
        if (left > right) return nullptr;
        // ����
        TreeNode* newTree = new TreeNode(postorder[root]);

        newTree->left = buildTreeCore(root - 1 - (right - map[postorder[root]] + 1 + 1), left, map[postorder[root]] + 1, postorder, inorder);
        newTree->right = buildTreeCore(root - 1, map[postorder[root]] - 1, right, postorder, inorder);
    
        return newTree;
    }

};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

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
    unordered_map<int, int> map;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // �������������ֵ��������ӳ��
        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return buildTreeCore(postorder, inorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* buildTreeCore(vector<int>& postorder, vector<int>& inorder,
        int inStart, int inEnd, int postStart, int postEnd) {
        // �߽�����
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        // ������������һ��Ԫ���Ǹ��ڵ�
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);

        // �ҵ����ڵ�����������е�λ��
        int rootIndex = map[rootVal];

        // �����������Ľڵ������ע���������ø��ڵ�������ȥ��inStart��
        // ���ڵ㲻����������һ���֣����Բ���+1�������������ȣ�
        int leftSize = rootIndex - inStart;

        // �ݹ鹹��������
        // �������ں�������еķ�Χ��[postStart, postStart + leftSize - 1]
        // ����������������еķ�Χ��[inStart, rootIndex - 1]
        root->left = buildTreeCore(postorder, inorder, 
                                    inStart, rootIndex - 1,
                                    postStart, postStart + leftSize - 1);

        // �ݹ鹹��������
        // �������ں�������еķ�Χ��[postStart + leftSize, postEnd - 1]
        // ����������������еķ�Χ��[rootIndex + 1, inEnd]
        root->right = buildTreeCore(postorder, inorder, 
                                    rootIndex + 1, inEnd,
                                    postStart + leftSize, postEnd - 1);

        return root;
    }
};

#endif // DEBUG2