#include <iostream>

using namespace std;

//#define DEBUG
#ifdef DEBUG
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


// !!!!!!!!!�����leetcode��ᱨ����֪��Ϊɶ
class MyLinkedList {

private:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode* pre;
        ListNode(int x, ListNode* next, ListNode* pre = nullptr) :val(x), next(next), pre(pre) {};
    };

    ListNode* myListHead;
    int size;
    ListNode* dummy;

public:
    MyLinkedList() {
        myListHead = nullptr;
        size = 0;
        dummy = new ListNode(-1, myListHead);
    }

    ~MyLinkedList() {
        // ѭ������
        ListNode* cur = myListHead;
        ListNode* temp;
        while (cur) {
            temp = cur;
            cur = cur->next;
            delete temp;
        }
        delete dummy;
    }

    int get(int index) {

        // �±���Ч�����
        if (index < 0 || index >= size) return -1;

        ListNode* cur = myListHead;

        while (index--) {
            cur = cur->next;
            if (cur == nullptr)return -1;
        }
        return cur->val;
    }

    void addAtHead(int val) {
        ListNode* temp = myListHead;
        myListHead = new ListNode(val, temp);
        dummy->next = myListHead; // ע�⣡��������dummy,��Ȼ�ڱ��Ͳ�������ͷ��
        size++;
    }

    void addAtTail(int val) {

        ListNode* cur = myListHead;
        // ���������һ��
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new ListNode(val, nullptr);
        size++;

    }

    void addAtIndex(int index, int val) {

        // ����������
        if (index > size)return;

        ListNode* cur = myListHead;
        ListNode* pre = dummy;
        while (index--) {
            // ��ʱcur��ָ��index��ʾ�Ľڵ㣬��������Ҫ������indexǰ����Ҫ�и�ָ�뱣��index֮ǰ��.
            // ���������index == size���������ʱcur ָ���������һ���ڵ����һ��nullptr
            cur = cur->next;
            pre = pre->next;
        }

        pre->next = new ListNode(val, cur);
        size++;

    }

    void deleteAtIndex(int index) {

        // �±���Ч�����
        if (index > size - 1)return;

        ListNode* cur = myListHead;
        ListNode* pre = dummy;
        while (index--) {
            // ��ʱcur��ָ��index��ʾ�Ľڵ�
            cur = cur->next;
            pre = pre->next;

        }
        pre->next = cur->next;
        delete cur;
        size--;


    }

    void printList() {
        
        ListNode* cur = myListHead;
        cout << "��ǰ����";
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {

    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->printList();

    myLinkedList->get(0);              // ���� 2
    myLinkedList->printList();

    myLinkedList->addAtHead(1);
    myLinkedList->printList();

    myLinkedList->addAtTail(3);
    myLinkedList->printList();

    myLinkedList->addAtIndex(1, 2);    // �����Ϊ 1->2->3
    myLinkedList->printList();

    myLinkedList->get(1);              // ���� 2
    myLinkedList->printList();

    myLinkedList->deleteAtIndex(1);    // ���ڣ������Ϊ 1->3
    myLinkedList->printList();

    myLinkedList->get(1);              // ���� 3


}



#endif // DEBUG


//#define DaiMaSuiXiangLu
// https://www.programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF
#ifdef DaiMaSuiXiangLu

class MyLinkedList {
public:
    // ��������ڵ�ṹ��
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {}
    };

    // ��ʼ������
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // ���ﶨ���ͷ��� ��һ������ͷ��㣬����������������ͷ���
        _size = 0;
    }

    // ��ȡ����index���ڵ���ֵ�����index�ǷǷ���ֱֵ�ӷ���-1�� ע��index�Ǵ�0��ʼ�ģ���0���ڵ����ͷ���
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--) { // ���--index �ͻ�������ѭ��
            cur = cur->next;
        }
        return cur->val;
    }

    // ��������ǰ�����һ���ڵ㣬������ɺ��²���Ľڵ�Ϊ������µ�ͷ���
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // ��������������һ���ڵ�
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // �ڵ�index���ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
    // ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
    // ���index��������ĳ��ȣ��򷵻ؿ�
    // ���indexС��0������ͷ������ڵ�
    void addAtIndex(int index, int val) {

        if (index > _size) return;
        if (index < 0) index = 0;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }

    // ɾ����index���ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
    void deleteAtIndex(int index) {
        if (index >= _size || index < 0) {
            return;
        }
        LinkedNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        //delete����ָʾ�ͷ���tmpָ��ԭ����ָ���ǲ����ڴ棬
        //��delete���ָ��tmp��ֵ����ַ�����Ǿ���NULL���������ֵ��Ҳ���Ǳ�delete��
        //������ټ���һ��tmp=nullptr,tmp���Ϊ��ָ��Ұָ��
        //���֮��ĳ���С��ʹ����tmp����ָ������Ԥ����ڴ�ռ�
        tmp = nullptr;
        _size--;
    }

    // ��ӡ����
    void printLinkedList() {
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
private:
    int _size;
    LinkedNode* _dummyHead;

};

#endif // DaiMaSuiXiangLu
