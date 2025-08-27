#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x = -1, ListNode* ptr = nullptr) : val(x), next(ptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // �����ƽڵ�
        ListNode* dummyHead = new ListNode();

        // �������������
        dummyHead->next = head;

        ListNode* temp = dummyHead;

        while (temp->next != nullptr && temp->next->next != nullptr) {
            // ��ʼ�����ڷ����ʾ�ڵ����ʱ����
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            ListNode* node3 = temp->next->next->next;

            // ��ʼ��������Ӧ���ݶ�����ʱ�����Ӧ�ò���Ҫ���ǽ��������˳�򲻶Ե�������ϵ�
            temp->next = node2;
            node1->next = node3;
            node2->next = node1;

            // ��׼�ڵ㲽����ֱ�Ӳ��������൱�ڣ�
            temp = node1;
        }

        // ��ջ�Ϸ��䷵������
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }

    // ���ݶ��ŷָ����ַ�����������
    ListNode* buildList(const string& input) {
        stringstream ss(input);
        string token;
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        while (getline(ss, token, ',')) {
            ListNode* newNode = new ListNode(stoi(token));
            if (!head) {
                head = newNode;  // ��������ͷ
                curr = head;
            }
            else {
                curr->next = newNode;
                curr = curr->next;
            }
        }
        return head;
    }

    // ��ӡ����
    void printList(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr) {
            cout << curr->val;
            if (curr->next != nullptr) {
                cout << ", ";
            }
            curr = curr->next;
        }
        cout << endl;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {
    string input;
    Solution solution;

    // ������������
    cout << "�������������� (���磺1,2,3,4): ";
    getline(cin, input);

    // ��������
    ListNode* head = solution.buildList(input);

    // �������ǰ������
    cout << "ԭʼ����: ";
    solution.printList(head);

    // ��������гɶԽ���
    ListNode* result = solution.swapPairs(head);

    // ��������������
    cout << "�����������: ";
    solution.printList(result);

    return 0;
}

#endif // DEBUG
