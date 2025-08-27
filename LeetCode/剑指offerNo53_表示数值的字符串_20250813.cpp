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
    bool isNumeric(char* string) {
        // ������Ƿ��š�С���㡢e�Ƿ���ֹ�
        bool sign = false, decimal = false, hasE = false;
        for (int i = 0; i < strlen(string); ++i) {
            // �����о������ַ���������
			// ��ѧ��������e��E
            if (string[i] == 'e' || string[i] == 'E') {
				if (i == strlen(string) - 1) return false; // e�������������(С�����ں��洦��)
				if (hasE) return false; // eֻ�ܳ���һ��
				hasE = true; // ���e���ֹ�
            }
            // ������
            else if (string[i] == '+' || string[i] == '-') {
				// ��һ�γ��������ţ������ڿ�ͷ��Ҳ��������e����
                if (!sign && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E') return false;
                // �ڶ��γ��������ţ����������e����(���ֹ��ˣ������ж�i����0�����õ���i - 1���)
                if (sign && string[i - 1] != 'e' && string[i - 1] != 'E') return false;
				sign = true; // ��������ų��ֹ�
            }
            // С����
            else if (string[i] == '.') {
				// e ���治����С����(��ֻ��string[i - 1]������e������e���涼���ܳ���)
                if (hasE || decimal) return false;
				decimal = true; // ���С������ֹ�
            }
            // �ж�����
			else if (string[i] < '0' || string[i] > '9')  return false; // ��������
        }
        // �ж����
		return true; // ���û�з���false��˵��������
    }
};

#endif // DEBUG1


