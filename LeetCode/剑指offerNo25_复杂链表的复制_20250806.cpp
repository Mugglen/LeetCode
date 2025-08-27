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


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:

    // 先复制节点，存入哈希表，然后再挨个链接上next和random
    RandomListNode* Clone(RandomListNode* pHead) {

        // 特判
        if (pHead == nullptr) return pHead;

        // 初始化
        RandomListNode* cur = pHead;
        //RandomListNode dummy(-1);
        //RandomListNode* cur2 = &dummy;
        unordered_map<RandomListNode*, RandomListNode*> map; // 保存源节点对应的复制后的节点
        // 复制开始
        while (cur) {
            map[cur] = new RandomListNode(cur->label);
            cur = cur->next;
        }
        // 开始链接
        cur = pHead;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next; // 记得步进！！！！！！！！
        }
        return map[pHead];

    }
};


#endif // DEBUG1