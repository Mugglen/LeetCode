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
// leetcode上还要考虑负数（就是每个字符多个‘-’），hard，照着leetcode的思路来实现，

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
        // “！”应该是分隔符，不然都拼在一起了不知道节点数值是多少（位数不清楚，还有可能是负数）
        if (root == nullptr) return "#!";
        // 先序遍历可以直接拼接，递归返回值就是当前子树的先序遍历序列化
        string str;
        str = to_string(root->val) + "!"; // to_string把数值转为string的
        str += SerializeCore(root->left);
        str += SerializeCore(root->right);
        return str;
    }

    // 递归建树(注意全局维护一个数组指针，所以递归外包一层传引用)
    TreeNode* DeserializeCore(char*& str) {
        // 跳过空节点
        if (*str == '#') {
            str++;
            return nullptr;
        }

        
		// 不是空节点，先判断当前节点的值是多少，正负
        int num = 0;
        // ============ 写法一 ↓ ===========
		/*bool isNegative = false;
        while (*str != '!') { // 从高位转换成数字的标准做法
			// 加一个判断，防止负数
            if (*str == '-') isNegative = true;
			else num = num * 10 + (*str - '0'); 
            str++;
        }
        // 处理负数
		if (isNegative) num *= -1;*/
        // ============ 写法一 ↑ ===========
        // ============ 写法二 ↓ ===========
        // 其实也可以用标准库函数stoi，应该就不用太担心负数了
		string numStr;
        while (*str != '!') {
			numStr += *str;
            str++;
        }
        num = std::stoi(numStr);
        // ============ 写法二 ↑ ===========

        // 开始建树
		TreeNode* node = new TreeNode(num);
        // 注意str现在等于！这一层用过了，要先自增再传入
		node->left = DeserializeCore(++str); // 递归建左子树
		node->right = DeserializeCore(++str); // 递归建右子树
		return node;
    }


public:
    // 先序遍历序列化（递归）
	// 注意题目要求返回值是char* ，而不是string，所以需要手动管理内存
	// 数组必须要要new,可以先用string来实现，最后再转成char*
    char* Serialize(TreeNode* root) {
        // string 暂存一下
		string str = SerializeCore(root);
        // 返回指针，数组就要new
        char* ans = new char[str.size()];
        for (int i = 0; i < str.size(); i++) {
			ans[i] = str[i];
        }
        return ans;
    }

    
    // 递归建树
    TreeNode* Deserialize(char* str) {
        // 保留原指针
		char* strPtr = str;
		// 启动递归建树
		return DeserializeCore(strPtr);
        // 没要求清除序列化资源
		delete[] str; // 这里不能delete[] str，因为是new char*，不是new char[]，会报错
    }
};


#endif // DEBUG2