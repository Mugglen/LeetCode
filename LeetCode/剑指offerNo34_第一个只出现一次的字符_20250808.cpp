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
class Solution {
public:

    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> umap;
        // 先存下每个字母出现的次数
        for (int i = 0; i < str.size(); ++i) {
            umap[str[i]]++;
        }
        // 按照字符串顺序遍历,遇到次数为1的立即返回,就是第一个了
        for (int i = 0; i < str.size(); ++i) {
            if (umap[str[i]] == 1) return i;
        }
        // 没找到
        return -1;
    }
};

#endif // DEBUG1