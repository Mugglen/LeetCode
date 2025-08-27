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

// ����ԭ��û�ˣ�дд����˼·
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/49-%E5%89%91%E6%8C%87offer.html
// ���ð����ˢ������
class Solution {
public:
	int StrToInt(string str) {
		int len = str.size();
		if (len == 0) return 0; // ���ַ���

		int i = 0, flag = 1, isSignal = 0; // siSignal���ڱ���Ƿ��з���λ��flagΪ������־λ
		long res = 0; // ʹ��long��ֹ���
		while (i < len && str[i] == ' ') i++; // ����ǰ���ո�
		if (i >= len) return 0; // ȫ�ǿո�����

		// ����λ�Լ��Ϸ����ж�
		while (i < len && (str[i] == '-' || str[i] == '+')) { // �ж�������־λ
			if (str[i] == '-') flag = -1; // ����
			i++; // ��������λ
			isSignal++; // ����з���λ
			if (isSignal > 1) return 0; // ����ж������λ������0
		}
		// ����ת���߼�
		for (; i < len; i++) {
			if (str[i] > '9' || str[i] < '0') return 0; // �������ַ�������0
			res = res * 10 + (str[i] - '0'); // �ۼ�����(�Ӹ�λ��ʼ�ģ�ÿ��Ҫ��ǰһ�εĽ����10)
			if (res > INT_MAX && flag == 1) return INT_MAX; // �������
			if (res > INT_MAX + 1 && flag == -1) return INT_MIN; // �������
		}
		return res * flag; // ���ؽ��
	}
};

#endif // DEBUG1


