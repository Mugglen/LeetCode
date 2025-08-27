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
        // �ȴ���ÿ����ĸ���ֵĴ���
        for (int i = 0; i < str.size(); ++i) {
            umap[str[i]]++;
        }
        // �����ַ���˳�����,��������Ϊ1����������,���ǵ�һ����
        for (int i = 0; i < str.size(); ++i) {
            if (umap[str[i]] == 1) return i;
        }
        // û�ҵ�
        return -1;
    }
};

#endif // DEBUG1