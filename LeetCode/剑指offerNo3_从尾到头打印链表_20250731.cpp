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
        // 异常处理
        if (head == nullptr) return {};

        vector<int> res;
        ListNode* cur = head;
        while (cur) {
            res.push_back(cur->val);
            cur = cur->next;
        }
        reverse(res.begin(), res.end());
        // 注意不能return reverse(res.begin(), res.end());
        // 因为reverse没有返回值
        return res;
    }
};
#endif // DEBUG
