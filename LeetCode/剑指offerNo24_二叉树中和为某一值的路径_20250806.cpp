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

    // ��Ҫ�ݹ������������
    // ֻ�ܴӸ��ڵ����ӽڵ��ߣ���hot100��124���·���Ͳ�̫һ��,���Һ���ֻ�ܴӸ��ڵ㿪ʼ
    // �����⣺Ϊ������������û��target - root->val�ĺ͵�·�������ݹ��յ����жϣ��м䱣�����������ж�������������ݵ�·�ϱ�����
    // �ݹ鷵��ֵ��û��
    // ��ע��ڵ�ֵ����Ϊ������û��˵��·�����������˵���·���㲻�㣬����target = 10ʱ����·��5��5��1��-1�������桾5��5�������������ﲻ�㣩
    vector<vector<int> > FindPath(TreeNode* root, int target) {
        
        // �ݴ���(�о��е���ݵ�����)
        vector<int> tmp;
        vector<vector<int>> ans;
        // �ڲ��ݹ�
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int target) {
            // ������ֹ����1���ݹ鵽��;��target < 0,ֱ�ӷ��أ������棨ע�Ȿ��ڵ�ֵ����Ϊ�������ü������µݹ飩
            // ������ֹ����1��targetΪ0����������ֱ�ӷ��أ������������������Ľڵ㷵�����Σ�
            // ��ֹ����1�������ǰ��Ҷ�ӽڵ㣬targetΪroot->val����������ֱ�ӷ���
            // ��ֹ����2(���ֱ�Ӻϲ����������ҽڵ���ж��ϣ��սڵ�ֱ�Ӳ�������)���ݹ鵽Ҷ���µĿսڵ㵫target != 0,ֱ�ӷ��أ�������
            
            // �սڵ㷵��(��������ݹ�����ʱ����սڵ�)
            if (root == nullptr) return;
            // �ǿ���ѹ����
            tmp.push_back(root->val);
            // ��ֹ����1
            if (root->left == nullptr && root->right == nullptr && target == root->val) {
                ans.push_back(tmp);
                // ע��!!!!!����ҲҪ�ָ��ֳ�
                tmp.pop_back();
                return;
            }
            else { 
                if (root->left) dfs(root->left, target - root->val);
                if (root->right) dfs(root->right, target - root->val);
            }
            // �ָ��ֳ�
            tmp.pop_back();
            };
        // �����ݹ�
        dfs(root, target);
        return ans;
    }
};


#endif // DEBUG1