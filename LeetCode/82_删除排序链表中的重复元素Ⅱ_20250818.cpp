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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        // 三指针,加一个保持当前重复值的变量
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        
        // 循环删除
        while (true) {
            // 和cur比较,删除cur以外相等节点
            if (cur && next && cur->val == next->val) {
                int val = cur->val;
                // 与重复值相同的cur都删掉（注意判断cur是否为空）
                while (cur && cur->val == val) {
                    ListNode* tmp = cur;
                    pre->next = next;
                    //pre = cur;
                    cur = next;
                    next = (cur == nullptr) ? nullptr : cur->next;
                    delete tmp;
                }
            }
            else if((cur && next && cur->val != next->val)){ // 不相等，移动三指针
                // 移动三指针
                pre = cur;
                cur = next;
                next = (cur == nullptr) ? nullptr : cur->next;
            }
            else { // next == nullptr
                break;
            }
        }
        // 删除哨兵
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};


#endif // DEBUG1