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
        // 创建哑节点
        ListNode* dummyHead = new ListNode();

        // 接上输入的链表
        dummyHead->next = head;

        ListNode* temp = dummyHead;

        while (temp->next != nullptr && temp->next->next != nullptr) {
            // 初始化用于方便表示节点的临时变量
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;
            ListNode* node3 = temp->next->next->next;

            // 开始交换，对应数据都在临时变量里，应该不需要考虑交换这里的顺序不对导致链表断掉
            temp->next = node2;
            node1->next = node3;
            node2->next = node1;

            // 基准节点步进（直接步进两步相当于）
            temp = node1;
        }

        // 在栈上分配返回数据
        ListNode* ans = dummyHead->next;
        delete dummyHead;
        return ans;
    }

    // 根据逗号分隔的字符串构建链表
    ListNode* buildList(const string& input) {
        stringstream ss(input);
        string token;
        ListNode* head = nullptr;
        ListNode* curr = nullptr;

        while (getline(ss, token, ',')) {
            ListNode* newNode = new ListNode(stoi(token));
            if (!head) {
                head = newNode;  // 设置链表头
                curr = head;
            }
            else {
                curr->next = newNode;
                curr = curr->next;
            }
        }
        return head;
    }

    // 打印链表
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

    // 输入链表数据
    cout << "请输入链表数据 (例如：1,2,3,4): ";
    getline(cin, input);

    // 构建链表
    ListNode* head = solution.buildList(input);

    // 输出交换前的链表
    cout << "原始链表: ";
    solution.printList(head);

    // 对链表进行成对交换
    ListNode* result = solution.swapPairs(head);

    // 输出交换后的链表
    cout << "交换后的链表: ";
    solution.printList(result);

    return 0;
}

#endif // DEBUG
