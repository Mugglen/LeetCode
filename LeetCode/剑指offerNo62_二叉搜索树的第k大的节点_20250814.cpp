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

// ţ������Ŀ���ˣ�leetcode����
// https ://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/submissions/653117624/

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
	// �����������ĵ�k��ڵ㣬��ʵ������������ĵ�����k���ڵ�
    // ��װһ�㣬�����������
    void findTargetNodeCore(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
		findTargetNodeCore(root->left, ans); 
		ans.push_back(root->val);
        findTargetNodeCore(root->right, ans);
    }


    int findTargetNode(TreeNode* root, int cnt) {
        // ��ĿҪ��֤�нڵ㣬����������cnt�����ﲻ����Ҳ��
		if (root == nullptr) return -1;
        vector<int>ans;
        findTargetNodeCore(root, ans);
		// �ҵ���cnt���ڵ�
        if (cnt > ans.size()) return -1; // ��Ŀ��֤�нڵ㣬����������cnt�����ﲻ����Ҳ��
		return ans[ans.size() - cnt];

    }
};



#endif // DEBUG2