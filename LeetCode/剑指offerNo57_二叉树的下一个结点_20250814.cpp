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

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
// ţ������һ������ûͨ�����о������ҵ����⣬������ţ�͵Ĳ�������������
// �������� {1,2,#,#,3,#,4},4
// Ԥ����� 1
// �ҵ���� nullptr, ���4����Ӧ���ǵ���һ��˭�������ӵĽ����
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // �������Ӱ����һ�������˭�������У�����˵��ѡ�ˣ�
		// ��������������ĵ�һ����㣨���ȼ���ߣ�
		// û��������������£����ڵ㣨����еĻ������ҵ��Ǹ��ڵ�����ӣ�
        // ��������������©��һ�֣���Ȼ�Ǹ��׵��Һ��ӣ����Ǹ��׽���п����Ǹ��׵ĸ��׵����ӣ���ʱ����һ�������Ǹ��׵ĸ��ף�
		if (pNode == nullptr) return nullptr;
		// ������������ĵ�һ�����
		vector<TreeLinkNode*> res;
        function<void(TreeLinkNode*)> dfs = [&](TreeLinkNode* node){
            if (node == nullptr) return;
            dfs(node->left);
			res.push_back(node);
			dfs(node->right);
            };
        // ��������
        if (pNode->right) {
			dfs(pNode->right);
			return res[0]; // ��������������ĵ�һ�����
        }
        // �и��׽��
        else if (pNode->next) {
            // ����
            if (pNode == pNode->next->left) return pNode->next; // ���ڵ�
            // �Һ���
            else if (pNode == pNode->next->right) {
                if (pNode->next->next && pNode->next == pNode->next->next->left) {
					return pNode->next->next; // ���׵ĸ��ף�ע�⣬Ӧ���Ǵ��������ˣ�����ֻ�ж���һ�㣬Ӧ���Ǽ������ϱ�����ֱ���ҵ�һ���Ǹ��ڵ�����ӽڵ�Ľ�㣬���ظý��ĸ��ڵ㣩
                }
                else return nullptr;
            }
            else return nullptr;
        }
		// û�����������и��׽�㵫�������ӣ�û�и��׽��
        else return nullptr;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2

struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
// �������������
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        // ������Ϊ�գ����ؿ�
        if (pNode == nullptr) return nullptr;
		// ����Һ��Ӵ��ڣ�������һ��ָ��Ӹý���Һ��ӳ�����һֱ����ָ�����ӽڵ������ֱ���ҵ�һ��û�����ӽڵ�Ľ�㣬������һ�����
        TreeLinkNode* node = nullptr;
        if (pNode->right != nullptr) {
			node = pNode->right;
            while (node->left != nullptr) {
				node = node->left;
            }
			return node; // ������������������ĵ�һ�����
        }
        // �Һ��Ӳ����ڣ�����ڵ㲻�Ǹ��ڵ㣬����ýڵ��Ǹ��ڵ�����ӽڵ㣬�򷵻ظ��ڵ㣻����������ϱ�����ֱ���ҵ�һ���Ǹ��ڵ�����ӽڵ�Ľ�㣬���ظý��ĸ��ڵ�
        node = pNode;
        while (node->next != nullptr && node == node->next->right) {
			node = node->next; // ���ϱ���
        }
        // ���node->next��nullptr��˵���Ѿ�������ڵ��ˣ�����nullptr��
        // ���node->next����nullptr��˵��node->next�Ǹ��ڵ㣬���ظ��ڵ�
		return node->next; 
    }
};

#endif // DEBUG2