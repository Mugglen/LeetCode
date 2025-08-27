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
        // 有点像按层打印树的变种
        // 准备俩队列
        queue<Node*> qOdd;
        queue<Node*> qEven;
        if (root == nullptr) return nullptr;
        else qOdd.push(root);

        while (!qOdd.empty() || !qEven.empty()) {
            
            // 处理奇数行
            while (!qOdd.empty()) {
                // 取出节点
                Node* node = qOdd.front(); 
                // 左右孩子入队
                if (node->left) qEven.push(node->left);
                if (node->right) qEven.push(node->right);
                // 出队
                qOdd.pop();
                // 链接右侧
                node->next = !qOdd.empty() ? qOdd.front() : nullptr;

            }
            // 处理偶数行
            while (!qEven.empty()) {
                // 取出节点
                Node* node = qEven.front();
                // 左右孩子入队
                if (node->left) qOdd.push(node->left);
                if (node->right) qOdd.push(node->right);
                // 出队
                qEven.pop();
                // 链接右侧
                node->next = !qEven.empty() ? qEven.front() : nullptr;

            }

        }
        return root;

    }
};



#endif // DEBUG1