#include <vector>
using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    void replaceSpace(char* str, int length) {
        // ͳ�ƿո�����
        int spaceCount = 0;
        int totalLen = length;
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ') spaceCount++;
        }

        // ���������ַ������ܳ���%20��3���ַ���ԭ�����ַ������Ȱ����ո��ˣ�����������ո񳤶Ⱦ���
        totalLen += spaceCount * 2;
        // ע����� && totalLen != i����� i = totalLen ��ʱ��˵��ǰ���Ѿ�û�пո���
        // ��Ϊ��ǰtotalLen��i����ָ������Ͳ���ǰ��ͬ��Ԫ�أ�����������ȣ���ʾ�ո��Ѿ����������
        for (int i = length - 1; i >= 0 && totalLen != i; --i) {
            // ��������ַ������飬����ԭ������Ŀռ��㹻
            // ԭ���޸ģ��Ӻ���ǰ�����ǿո��������
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
