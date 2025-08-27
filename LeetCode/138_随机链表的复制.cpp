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


// ����+��ϣ��
class Solution {

public:
	// ��Ϊ�ǻ��ݣ���Ҫ���Ѿ����ƹ��Ľڵ����ʶ�𣬲��еĻ����ϣ
	unordered_map<Node*, Node*> cacheNode;

	Node* copyRandomList(Node* head) {

		// �쳣ֵ����
		if (head == nullptr) {
			return nullptr;
		}

		// ��鵱ǰ�ڵ��ǲ����Ѿ���ʹ�ù������и�����
		if (!cacheNode.count(head)) {

			// ��������ڵ㣬˳����ֵ��ʼ��
			Node* headNew = new Node(head->val);

			// �����ϣ��keyΪԭ����ڵ�ָ�룬valueΪ��Ӧ������ڵ�ָ��
			cacheNode[head] = headNew;

			// ��ʼ�ݹ飬ͬʱ���ӽڵ�
			headNew->next = copyRandomList(head->next);
			headNew->random = copyRandomList(head->random);
		}
		// ���ع�ϣ��ֵ�������������˾ͻ�������Ľ��(�������������������if�д������½ڵ�)
		return cacheNode[head];
	}

};

//#define DEBUG
#ifdef DEBUG

int main() {


    return 0;
}


#endif // DEBUG
