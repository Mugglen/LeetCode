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
        // ��ָ��,��һ�����ֵ�ǰ�ظ�ֵ�ı���
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        
        // ѭ��ɾ��
        while (true) {
            // ��cur�Ƚ�,ɾ��cur������Ƚڵ�
            if (cur && next && cur->val == next->val) {
                int val = cur->val;
                // ���ظ�ֵ��ͬ��cur��ɾ����ע���ж�cur�Ƿ�Ϊ�գ�
                while (cur && cur->val == val) {
                    ListNode* tmp = cur;
                    pre->next = next;
                    //pre = cur;
                    cur = next;
                    next = (cur == nullptr) ? nullptr : cur->next;
                    delete tmp;
                }
            }
            else if((cur && next && cur->val != next->val)){ // ����ȣ��ƶ���ָ��
                // �ƶ���ָ��
                pre = cur;
                cur = next;
                next = (cur == nullptr) ? nullptr : cur->next;
            }
            else { // next == nullptr
                break;
            }
        }
        // ɾ���ڱ�
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};


#endif // DEBUG1