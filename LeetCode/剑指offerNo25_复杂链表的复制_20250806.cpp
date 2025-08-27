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

    // �ȸ��ƽڵ㣬�����ϣ��Ȼ���ٰ���������next��random
    RandomListNode* Clone(RandomListNode* pHead) {

        // ����
        if (pHead == nullptr) return pHead;

        // ��ʼ��
        RandomListNode* cur = pHead;
        //RandomListNode dummy(-1);
        //RandomListNode* cur2 = &dummy;
        unordered_map<RandomListNode*, RandomListNode*> map; // ����Դ�ڵ��Ӧ�ĸ��ƺ�Ľڵ�
        // ���ƿ�ʼ
        while (cur) {
            map[cur] = new RandomListNode(cur->label);
            cur = cur->next;
        }
        // ��ʼ����
        cur = pHead;
        while (cur) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next; // �ǵò�������������������
        }
        return map[pHead];

    }
};


#endif // DEBUG1