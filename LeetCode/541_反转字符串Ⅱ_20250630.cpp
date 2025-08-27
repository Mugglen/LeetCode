
#include <string>
#include <iostream>

using namespace std;


//#define DEBUG
#ifdef DEBUG
// https://www.programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html#%E6%80%9D%E8%B7%AF
class Solution {
public:
    string reverseStr(string s, int k) {

        // ���ò������ƿ���
        // ÿ��2k���ַ���ǰk�����з�ת
        // ʣ���ַ�С��2k���Ǵ���k����תǰk�������Թ�Ϊһ��
        for (int i = 0; i < s.size(); i += (2 * k)) {
            
            // ��ʹ���������Ӳ����жϵķ�ʽ��ԭ������������ߴ��������ж�
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                // ����һ��k��ֱ��ȫ����ת
                reverse(s.begin() + i, s.end());
            }
        
        }
        return s;

    }

    // �����Ҫ�Լ�ʵ��reverse�Ļ�
    void reverse(string& s, int start, int end) {
    
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }




};



#endif // DEBUG
