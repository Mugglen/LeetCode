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
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        // �½���������һ���� < x��һ���� >= x
        ListNode* minor = new ListNode(-1, nullptr);
        ListNode* greater = new ListNode(-1, nullptr);\
        // ����ָ��
        ListNode* cur = head; 
        ListNode* curMin = minor;
        ListNode* curBig = greater;

        while (cur) {
            if (cur->val < x) {
                curMin->next = cur; // ����
                curMin = curMin->next; // �ƶ�
                cur = cur->next;
            }
            else {
                curBig->next = cur; // ����
                curBig = curBig->next; // �ƶ�
                cur = cur->next;
            }
        }
        // �����������Ȱ���������β�������ŵĹ�ϵ����
        curMin->next = nullptr;
        curBig->next = nullptr;
        // ƴ��
        curMin->next = greater->next;
        // ���ؽ���������Դ
        ListNode* ans = minor->next;
        delete minor;
        delete greater;
        return ans;
    }
};


#endif // DEBUG1