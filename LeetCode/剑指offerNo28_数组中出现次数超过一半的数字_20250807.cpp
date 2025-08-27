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
    // Ҫ��ռ临�Ӷ�O��1���������ñ�Ŀռ������ÿ��Ԫ�س��ֵĸ�����
	// �����Ա���������������ͳ��ÿ��Ԫ�س��ֵĴ���
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
		unordered_map<int, int> count_map;
		int len = numbers.size();
		for (int i = 0; i < len; ++i) {
			count_map[numbers[i]]++;
			if (count_map[numbers[i]] > len / 2) return numbers[i];
		}
		return 0;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2


class Solution {
public:
	// ������ʵ��hot100 169����Ԫ�أ��;�����ô��ô����
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		// ʹ��Ħ��ͶƱ��������ǰ�����г���һ���Ԫ�أ��������������Ҫ�ж��ҵ���Ԫ���Ƿ���ֳ���һ��
		int cnt = 0, num = 0;
		// ���ѡԪ����ͬ����ѡƱ����ͬ����ѡƱ��ѡƱ���㻻��һ��Ԫ�غ�ѡ��������µĺ�ѡ�߾��Ƕ���Ԫ��
		for (int i = 0; i < numbers.size(); ++i) {
			if (cnt == 0) {
				num = numbers[i];
					cnt = 1;
			}
			else {
				num == numbers[i] ? cnt++ : cnt--;
			}
		}
		// �ж��ǲ��Ǵ���һ��
		cnt = count(numbers.begin(), numbers.end(), num);
		return cnt > numbers.size() / 2 ? num : 0;
	}
};

#endif // DEBUG2