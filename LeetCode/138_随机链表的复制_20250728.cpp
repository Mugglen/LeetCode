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
    // ����ϣ��������û�л���
    Node* copyRandomList(Node* head) {
        
        if (head == nullptr)return head;
        Node* cur = head;
        unordered_map<Node*, Node*> map;

        // �Ƚ����ڵ㣬ά����ԭ�ڵ�Ķ�Ӧ��ϵ
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // �ٽ�������
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
    // ����ϣ��������û�л���
    Node* copyRandomList(Node* head) {
        // �쳣����
        if (head == nullptr)return head;
        // �ȿ����ڵ�
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        while (cur) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // �ٽ�������
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