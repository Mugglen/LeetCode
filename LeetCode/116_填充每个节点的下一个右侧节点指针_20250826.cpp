#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        // �е��񰴲��ӡ���ı���
        // ׼��������
        queue<Node*> qOdd;
        queue<Node*> qEven;
        if (root == nullptr) return nullptr;
        else qOdd.push(root);

        while (!qOdd.empty() || !qEven.empty()) {
            
            // ����������
            while (!qOdd.empty()) {
                // ȡ���ڵ�
                Node* node = qOdd.front(); 
                // ���Һ������
                if (node->left) qEven.push(node->left);
                if (node->right) qEven.push(node->right);
                // ����
                qOdd.pop();
                // �����Ҳ�
                node->next = !qOdd.empty() ? qOdd.front() : nullptr;

            }
            // ����ż����
            while (!qEven.empty()) {
                // ȡ���ڵ�
                Node* node = qEven.front();
                // ���Һ������
                if (node->left) qOdd.push(node->left);
                if (node->right) qOdd.push(node->right);
                // ����
                qEven.pop();
                // �����Ҳ�
                node->next = !qEven.empty() ? qEven.front() : nullptr;

            }

        }
        return root;

    }
};



#endif // DEBUG1