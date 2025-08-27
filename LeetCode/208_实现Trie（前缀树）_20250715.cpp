#include <string>

using namespace std;

//#define DEBUG
#ifdef DEBUG

struct Node {
	Node* son[26]{}; // 子节点数组，表示26个字母
	bool end = false; // 标记是否为单词的结尾
};

class Trie {

private:
	Node* root = new Node(); // 根节点

    int find(string word) {
		Node* cur = root;
        for (char c : word) {
			c -= 'a'; // 将字符转换为索引
            if (cur->son[c] == nullptr) return 0; // 道不同，不相为谋
			cur = cur->son[c]; // 移动到子节点
			
        }
        return cur->end ? 2 : 1; // 走过同样的路（2=完全匹配，1=前缀匹配）
    }

public:
    Trie() {

    }

    void insert(string word) {
		Node* cur = root; // 从根节点开始
        for (char c : word) {
			c -= 'a'; // 将字符转换为索引
            if (cur->son[c] == nullptr) {
				cur->son[c] = new Node(); // 如果子节点不存在，创建新节点
            }
			cur = cur->son[c]; // 移动到子节点
        }
		cur->end = true; // 标记单词结尾
    }

    bool search(string word) {
		return find(word) == 2; // 如果返回值为2，表示单词存在w
    }

    bool startsWith(string prefix) {
		return find(prefix) != 0; // 如果返回值不为0，表示有前缀匹配
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
