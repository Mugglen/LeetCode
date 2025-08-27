#include <vector>
#include <algorithm>
using namespace std;


//#define DEBUG
#ifdef DEBUG

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val, ListNode* next) : val(val), next(next) {};

};

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        // �쳣����
        if (head == nullptr) return {};

        vector<int> res;
        ListNode* cur = head;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        reverse(res.begin(), res.end());
        // ע�ⲻ��return reverse(res.begin(), res.end());
        // ��Ϊreverseû�з���ֵ
        return res;
    }
};
#endif // DEBUG
