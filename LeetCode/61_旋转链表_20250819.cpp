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
    // ����ע��k�ǿ��Դ��������ȵģ���ɾ��������k���ڵ㻹��̫һ��
    ListNode* rotateRight(ListNode* head, int k) {
        // ��ʵ�ǶϿ�������k���ڵ㣬β�����ӵ���һ���ڵ�
        // Ϊ�˼�����ת������������ڵ����������������ڱ�
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(-1, head);
        // ��Ҫͷָ�룬����k���ڵ�ǰһλ��ָ�룬�Ѿ�����k����ָ��
        // ע��k������������Ҫȡģ
        ListNode* left = dummy;
        ListNode* right = head;
        int count = 0;
        // �Ȼ�ȡ������
        while (right) {
            count++;
            right = right->next;
        }
        k = k % count; // ��kȡģ
        if (k == 0) return head; // ������ת��ֱ�ӷ���
        right = dummy; // ��λ��ָ�루ע���Ǹ�λ��dummy�ϣ�����k = 0���������λ��head�Ͼ���Ĭ��k = 1�ˣ�
        while (k--) {
            right = right->next;
        }
        // ͬʱ�ƶ�����ָ��
        while (right) {
            left = left->next;
            right = right->next;
            // �������һ���ڵ�ʱ��������β����ͷ�����ӣ����˳�ѭ��
            if (right->next == nullptr) {
                right->next = head;
                break;
            }
        }
        // ������ͷָ�룬�Ͽ�
        ListNode* newHead = left->next;
        left->next = nullptr;
        delete dummy; // �ͷ��ڱ�
        return newHead;
    }
};


#endif // DEBUG1