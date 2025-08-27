#include<unordered_map>

using namespace std;

// https://leetcode.cn/problems/lru-cache/solutions/2456294/tu-jie-yi-zhang-tu-miao-dong-lrupythonja-czgt
// ����˫������
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
	// �������ʼ������
    int capacity;
	// �����ڱ��ڵ�
	Node* dummy;

	// Ҫ��O��1���Ĳ���ʱ�临�Ӷȣ�ʹ�ù�ϣ��
	unordered_map<int, Node*> key_to_node;

	// ɾ��һ���ڵ㣬����ʹ�����������ʹ��push_front
	void remove(Node* x) {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}

	// ������ͷ���һ���ڵ�(����ԭ�ڵ�λ�õ�������remove��ʵ��,��Ȼһ��Ҫ�޸�6��ָ��)
	void push_front(Node* x) {

		// �޸�x������
		x->prev = dummy;
		x->next = dummy->next;

		// �޸�ͷ�ڵ�ǰ�������ڵ������

		// ע����͵Ĵ��������Ѿ�����dummy->next��
		//dummy->next = x;
		//dummy->next->prev = x;

		// ��������Ѿ�����ͷ�ϵ�x���Ͽ�ͷ��������
		x->prev->next = x;
		x->next->prev = x;

	}

	// ��ȡkey��Ӧ�Ľڵ㣬ͬʱ�Ѹýڵ��Ƶ�����ͷ��
	Node* get_node(int key) {
		// find����һ�����������ҵ��Ļ�����pair<key, value>
		auto it = key_to_node.find(key);

		// ������û��
		if (it == key_to_node.end()) {
			return nullptr;
		}
		
		// �������ҵ���
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

		// �����������
		if (node) {
			node->value = value;
			return;// �����˷���
		}

		// �������û��,�½�������ϣ
		key_to_node[key] = node = new Node(key, value);

		// �ŵ����涥��
		push_front(node);

		// ��黺���С��û�г��꣨��������黺���С����Ϊ��ĿҪ�󳬳�����ɾ�����δʹ�õĽڵ㣩
		if (key_to_node.size() > capacity) {
			Node* back_node = dummy->prev;

			// ɾ����ϣ���¼
			key_to_node.erase(back_node->key);

			// ժ���ڵ�
			remove(back_node);

			// �ͷ��ڴ�
			delete back_node;
		}
	}
};



