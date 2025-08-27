#include <unordered_map>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/copy-list-with-random-pointer/solutions/2361362/138-fu-zhi-dai-sui-ji-zhi-zhen-de-lian-b-6jeo/?envType=study-plan-v2&envId=top-100-liked
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // 纯哈希表做法，没有回溯
    Node* copyRandomList(Node* head) {
        
        if (head == nullptr)return head;
        Node* cur = head;
        unordered_map<Node*, Node*> map;

        // 先建立节点，维护和原节点的对应关系
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // 再建立链接
        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};
#endif // DEBUG


//#define PRETICE
#ifdef PRETICE

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    // 纯哈希表做法，没有回溯
    Node* copyRandomList(Node* head) {
        // 异常处理
        if (head == nullptr)return head;
        // 先拷贝节点
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // 再建立链接
        cur = head;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};
#endif // PRETICE