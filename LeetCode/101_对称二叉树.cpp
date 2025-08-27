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
    // ֱ�۱Ƚ�root����������
    bool compare(TreeNode* left, TreeNode* right) {

        // ���ԳƵ��������
        // �����ų�˫�սڵ㣬���սڵ�
        if (left == nullptr && right == nullptr) return true;  // �޸�Ϊ true�������ڵ㶼Ϊ�գ���Ϊ�Գƣ�ע�����֮ǰд���ˣ�
        if (left == nullptr || right == nullptr) return false; // ֻҪһ��Ϊ�գ����� false

        // �ٿ���root����������ֵ��ͬ
        else if (left->val != right->val) return false;

        // �ݹ��߼���ʼ��ע�⿴����������������������������������ұȣ�
        // �ֱ�Ƚ����ڵ���ڲ�ڵ�
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }

    // ����leetCode����Ҫ��
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }

    // ������빹���������ʹ�ö��н��и�����
    TreeNode* buildTree(const vector<string>& nodes) {
        if (nodes.empty() || nodes[0] == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(nodes[0])); // Ҳ������sstream����
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < nodes.size()) {
            TreeNode* curr = q.front();
            q.pop();

            // �������ӣ�������ң�ע���α�����˳��
            if (i < nodes.size() && nodes[i] != "null") {
                curr->left = new TreeNode(stoi(nodes[i]));
                q.push(curr->left); // ������ŵ�ǰʵ����������
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

    // ���������ַ���Ϊ��������(ע�⣡�������������������ĵĶ��Żᵼ��getline�ִ�ʧ�ܣ����ֻ��һ�����ڵ�)
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

    // ��ȡ����
    getline(cin, input);

    // �������벢���������
    vector<string> nodes = solution.inputProcess(input);
    TreeNode* root = solution.buildTree(nodes);

    // �ж϶������Ƿ�Գ�
    string compareResult = solution.isSymmetric(root) ? "true" : "false";

    cout << compareResult << endl;

    return 0;
}

#endif // DEBUG
