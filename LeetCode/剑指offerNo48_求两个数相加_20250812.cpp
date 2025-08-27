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
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/48-%E5%89%91%E6%8C%87offer.html
    int Add(int num1, int num2) {
        while (num2 != 0) {
			int sum = num1 ^ num2; // �����������㲻��λ�ĺ�
			int carry = (num1 & num2) << 1; // ������������λ
			num1 = sum; // ����num1Ϊ����λ�ĺ�
			num2 = carry; // ����num2Ϊ��λ
        }
		return num1; // �������յĺ�
    }
};

#endif // DEBUG1


