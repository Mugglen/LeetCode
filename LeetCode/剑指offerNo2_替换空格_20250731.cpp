#include <vector>
using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    void replaceSpace(char* str, int length) {
        // 统计空格总数
        int spaceCount = 0;
        int totalLen = length;
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ') spaceCount++;
        }

        // 算出添加完字符串的总长度%20是3个字符，原来的字符串长度包含空格了，这里加两倍空格长度就行
        totalLen += spaceCount * 2;
        // 注意加上 && totalLen != i，如果 i = totalLen 的时候说明前面已经没有空格了
        // 因为当前totalLen和i都是指向插入后和插入前相同的元素，两者索引相等，表示空格都已经被处理过了
        for (int i = length - 1; i >= 0 && totalLen != i; --i) {
            // 传入的是字符串数组，假设原有数组的空间足够
            // 原地修改，从后往前，不是空格的往后排
            if (str[i] != ' ') str[--totalLen] = str[i];
            else {
                str[--totalLen] = '0';
                str[--totalLen] = '2';
                str[--totalLen] = '%';
            }
        }
    }
};
#endif // DEBUG
