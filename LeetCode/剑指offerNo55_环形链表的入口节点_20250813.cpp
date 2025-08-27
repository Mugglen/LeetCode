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
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

// д���ˣ�ע�⿴�����Solution����ǶԵ�
class Solution_fault {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        // ˫ָ��
		ListNode* slow = pHead;
		ListNode* fast = pHead;
        if (fast && fast->next) {
            fast = fast->next->next;
            // ��������������������������԰�fast�����ˣ�����slowû�в���
            // ��������������һ��whileѭ���Ļ�����Զ��������
            // slow = slow->next;
        }
		else return nullptr;

        while (slow != fast) {
			slow = slow->next;
            if(fast->next) fast = fast->next->next;
			else return nullptr;
        }
		// �ҵ����������ָ���ͷ��ʼ�ߣ���ָ�벻��
		slow = pHead;
        while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
        }
		return slow; // ����������
    }


};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head, * fast = head;
        // Ѱ�������㣨��ʵ��ԭ����while(true)�����ж�д��while�ﻹ�������һЩ��
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr; // �޻�

        // ��ͷ��������ͬʱһ�����ߣ���ϴ������
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

#endif // DEBUG1