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


// !!!!!!!!!这个扔leetcode里会报错，不知道为啥
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
        // 循环销毁
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

        // 下表无效的情况
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
        dummy->next = myListHead; // 注意！！！更新dummy,不然哨兵就不在链表头了
        size++;
    }

    void addAtTail(int val) {

        ListNode* cur = myListHead;
        // 步进到最后一个
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new ListNode(val, nullptr);
        size++;

    }

    void addAtIndex(int index, int val) {

        // 大于链表长度
        if (index > size)return;

        ListNode* cur = myListHead;
        ListNode* pre = dummy;
        while (index--) {
            // 此时cur会指向index表示的节点，但是我们要插入在index前，需要有个指针保存index之前的.
            // 这里包含了index == size的情况，此时cur 指向链表最后一个节点的下一个nullptr
            cur = cur->next;
            pre = pre->next;
        }

        pre->next = new ListNode(val, cur);
        size++;

    }

    void deleteAtIndex(int index) {

        // 下表无效的情况
        if (index > size - 1)return;

        ListNode* cur = myListHead;
        ListNode* pre = dummy;
        while (index--) {
            // 此时cur会指向index表示的节点
            cur = cur->next;
            pre = pre->next;

        }
        pre->next = cur->next;
        delete cur;
        size--;


    }

    void printList() {
        
        ListNode* cur = myListHead;
        cout << "当前链表：";
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

    myLinkedList->get(0);              // 返回 2
    myLinkedList->printList();

    myLinkedList->addAtHead(1);
    myLinkedList->printList();

    myLinkedList->addAtTail(3);
    myLinkedList->printList();

    myLinkedList->addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList->printList();

    myLinkedList->get(1);              // 返回 2
    myLinkedList->printList();

    myLinkedList->deleteAtIndex(1);    // 现在，链表变为 1->3
    myLinkedList->printList();

    myLinkedList->get(1);              // 返回 3


}



#endif // DEBUG


//#define DaiMaSuiXiangLu
// https://www.programmercarl.com/0707.%E8%AE%BE%E8%AE%A1%E9%93%BE%E8%A1%A8.html#%E6%80%9D%E8%B7%AF
#ifdef DaiMaSuiXiangLu

class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {}
    };

    // 初始化链表
    MyLinkedList() {
        _dummyHead = new LinkedNode(0); // 这里定义的头结点 是一个虚拟头结点，而不是真正的链表头结点
        _size = 0;
    }

    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        if (index > (_size - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while (index--) { // 如果--index 就会陷入死循环
            cur = cur->next;
        }
        return cur->val;
    }

    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }

    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
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

    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
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
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp = nullptr;
        _size--;
    }

    // 打印链表
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
