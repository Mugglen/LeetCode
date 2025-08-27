#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

// https://leetcode.cn/problems/xu-lie-hua-er-cha-shu-lcof/solutions/187388/mian-shi-ti-37-xu-lie-hua-er-cha-shu-ceng-xu-bian-/
// leetcode�ϻ�Ҫ���Ǹ���������ÿ���ַ������-������hard������leetcode��˼·��ʵ�֣�

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {

private:
    string SerializeCore(TreeNode* root) {
        // ������Ӧ���Ƿָ�������Ȼ��ƴ��һ���˲�֪���ڵ���ֵ�Ƕ��٣�λ������������п����Ǹ�����
        if (root == nullptr) return "#!";
        // �����������ֱ��ƴ�ӣ��ݹ鷵��ֵ���ǵ�ǰ����������������л�
        string str;
        str = to_string(root->val) + "!"; // to_string����ֵתΪstring��
        str += SerializeCore(root->left);
        str += SerializeCore(root->right);
        return str;
    }

    // �ݹ齨��(ע��ȫ��ά��һ������ָ�룬���Եݹ����һ�㴫����)
    TreeNode* DeserializeCore(char*& str) {
        // �����սڵ�
        if (*str == '#') {
            str++;
            return nullptr;
        }

        
		// ���ǿսڵ㣬���жϵ�ǰ�ڵ��ֵ�Ƕ��٣�����
        int num = 0;
        // ============ д��һ �� ===========
		/*bool isNegative = false;
        while (*str != '!') { // �Ӹ�λת�������ֵı�׼����
			// ��һ���жϣ���ֹ����
            if (*str == '-') isNegative = true;
			else num = num * 10 + (*str - '0'); 
            str++;
        }
        // ������
		if (isNegative) num *= -1;*/
        // ============ д��һ �� ===========
        // ============ д���� �� ===========
        // ��ʵҲ�����ñ�׼�⺯��stoi��Ӧ�þͲ���̫���ĸ�����
		string numStr;
        while (*str != '!') {
			numStr += *str;
            str++;
        }
        num = std::stoi(numStr);
        // ============ д���� �� ===========

        // ��ʼ����
		TreeNode* node = new TreeNode(num);
        // ע��str���ڵ��ڣ���һ���ù��ˣ�Ҫ�������ٴ���
		node->left = DeserializeCore(++str); // �ݹ齨������
		node->right = DeserializeCore(++str); // �ݹ齨������
		return node;
    }


public:
    // ����������л����ݹ飩
	// ע����ĿҪ�󷵻�ֵ��char* ��������string��������Ҫ�ֶ������ڴ�
	// �������ҪҪnew,��������string��ʵ�֣������ת��char*
    char* Serialize(TreeNode* root) {
        // string �ݴ�һ��
		string str = SerializeCore(root);
        // ����ָ�룬�����Ҫnew
        char* ans = new char[str.size()];
        for (int i = 0; i < str.size(); i++) {
			ans[i] = str[i];
        }
        return ans;
    }

    
    // �ݹ齨��
    TreeNode* Deserialize(char* str) {
        // ����ԭָ��
		char* strPtr = str;
		// �����ݹ齨��
		return DeserializeCore(strPtr);
        // ûҪ��������л���Դ
		delete[] str; // ���ﲻ��delete[] str����Ϊ��new char*������new char[]���ᱨ��
    }
};


#endif // DEBUG2