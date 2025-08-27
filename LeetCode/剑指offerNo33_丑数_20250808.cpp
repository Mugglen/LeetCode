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

    int GetUglyNumber_Solution(int index) {
		// ǰ6����������1-6,ֱ���������(ֻ�Ǽӿ�һ��,û���Ҳ��)
        //if (index <= 6) return index;

		// �������Էֽ�Ϊ2^x * 3^y * 5^z����ʽ
		int i2 = 0, i3 = 0, i5 = 0;
		vector<int> res;
		res.reserve(index);
		res[0] = 1; // ��һ��������1

		for (int i = 1; i < index; i++) {
			// �õ���һ������,��������С��
			res[i] = min({ res[i2] * 2, res[i3] * 3, res[i5] * 5 });
			/*��һ���� 2��3��5�Ƚϣ��õ���С����2*/
			/*�ڶ����� 4��3��5�Ƚϣ�Ϊʲô��4���أ���Ϊ�ϴ�2�Ѿ�����һ���ˣ����Խ���ȥ���Էŵĳ�����4��3��5֮��*/
			// ���Կ�ͷ������ָ����������2 3 5 �˵Ĵ�����
			// ��Ȼÿ����С�Ŀ϶���*2��
			if (res[i] == res[i2] * 2) i2++;
			if (res[i] == res[i3] * 3) i3++;
			if (res[i] == res[i5] * 5) i5++;
		}
		return res[index - 1];
    }
};

#endif // DEBUG1