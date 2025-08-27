#include<unordered_map>

using namespace std;

// https://leetcode.cn/problems/lru-cache/solutions/2456294/tu-jie-yi-zhang-tu-miao-dong-lrupythonja-czgt
// 创建双向链表
class Node {

public:

	int key;
	int value;
	Node* prev;
	Node* next;

	Node(int k = 0, int v = 0) : key(k), value(v) {}

};

class LRUCache {

private:
	// 保存类初始化变量
    int capacity;
	// 保存哨兵节点
	Node* dummy;

	// 要求O（1）的查找时间复杂度，使用哈希表
	unordered_map<int, Node*> key_to_node;

	// 删除一个节点，得先使用这个函数再使用push_front
	void remove(Node* x) {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}

	// 在链表头添加一个节点(连接原节点位置的愈合在remove中实现,不然一共要修改6个指针)
	void push_front(Node* x) {

		// 修改x的连接
		x->prev = dummy;
		x->next = dummy->next;

		// 修改头节点前后两个节点的连接

		// 注意典型的错误，这里已经改了dummy->next了
		//dummy->next = x;
		//dummy->next->prev = x;

		// 灵活利用已经接在头上的x来断开头处的连接
		x->prev->next = x;
		x->next->prev = x;

	}

	// 获取key对应的节点，同时把该节点移到链表头部
	Node* get_node(int key) {
		// find返回一个迭代器，找到的话就是pair<key, value>
		auto it = key_to_node.find(key);

		// 缓存内没有
		if (it == key_to_node.end()) {
			return nullptr;
		}
		
		// 缓存内找到了
		Node* node = it->second;
		remove(node);
		push_front(node);
		return node;
	
	
	}

public:
	LRUCache(int capacity) : capacity(capacity), dummy(new Node()) {
		dummy->prev = dummy;
		dummy->next = dummy;
	}

	int get(int key) {

		Node* node = get_node(key);

		return node ? node->value : -1;
	}

	void put(int key, int value) {
		Node* node = get_node(key);

		// 如果缓存内有
		if (node) {
			node->value = value;
			return;// 别忘了返回
		}

		// 如果缓存没有,新建索引哈希
		key_to_node[key] = node = new Node(key, value);

		// 放到缓存顶上
		push_front(node);

		// 检查缓存大小有没有超标（放在最后检查缓存大小是因为题目要求超出后再删除最久未使用的节点）
		if (key_to_node.size() > capacity) {
			Node* back_node = dummy->prev;

			// 删除哈希表记录
			key_to_node.erase(back_node->key);

			// 摘除节点
			remove(back_node);

			// 释放内存
			delete back_node;
		}
	}
};



