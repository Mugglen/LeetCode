#include <string>

using namespace std;

//#define DEBUG
#ifdef DEBUG

struct Node {
	Node* son[26]{}; // �ӽڵ����飬��ʾ26����ĸ
	bool end = false; // ����Ƿ�Ϊ���ʵĽ�β
};

class Trie {

private:
	Node* root = new Node(); // ���ڵ�

    int find(string word) {
		Node* cur = root;
        for (char c : word) {
			c -= 'a'; // ���ַ�ת��Ϊ����
            if (cur->son[c] == nullptr) return 0; // ����ͬ������Ϊı
			cur = cur->son[c]; // �ƶ����ӽڵ�
			
        }
        return cur->end ? 2 : 1; // �߹�ͬ����·��2=��ȫƥ�䣬1=ǰ׺ƥ�䣩
    }

public:
    Trie() {

    }

    void insert(string word) {
		Node* cur = root; // �Ӹ��ڵ㿪ʼ
        for (char c : word) {
			c -= 'a'; // ���ַ�ת��Ϊ����
            if (cur->son[c] == nullptr) {
				cur->son[c] = new Node(); // ����ӽڵ㲻���ڣ������½ڵ�
            }
			cur = cur->son[c]; // �ƶ����ӽڵ�
        }
		cur->end = true; // ��ǵ��ʽ�β
    }

    bool search(string word) {
		return find(word) == 2; // �������ֵΪ2����ʾ���ʴ���w
    }

    bool startsWith(string prefix) {
		return find(prefix) != 0; // �������ֵ��Ϊ0����ʾ��ǰ׺ƥ��
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
#endif // DEBUG
