#include <iostream>
#include <unordered_map>

using namespace std;

class Node {

public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};


// 回溯+哈希表
class Solution {

public:
	// 因为是回溯，需要对已经复制过的节点进行识别，才有的缓存哈希
	unordered_map<Node*, Node*> cacheNode;

	Node* copyRandomList(Node* head) {

		// 异常值处理
		if (head == nullptr) {
			return nullptr;
		}

		// 检查当前节点是不是已经被使用过来进行复制了
		if (!cacheNode.count(head)) {

			// 创建深拷贝节点，顺带讲值初始化
			Node* headNew = new Node(head->val);

			// 存入哈希表，key为原链表节点指针，value为对应的深拷贝节点指针
			cacheNode[head] = headNew;

			// 开始递归，同时链接节点
			headNew->next = copyRandomList(head->next);
			headNew->random = copyRandomList(head->random);
		}
		// 返回哈希表值，如果是深拷贝过了就还是深拷贝的结果(这里包含返回了我们在if中创建的新节点)
		return cacheNode[head];
	}

};

//#define DEBUG
#ifdef DEBUG

int main() {


    return 0;
}


#endif // DEBUG
