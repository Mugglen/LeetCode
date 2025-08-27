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

// 这题原题没了，写写看看思路
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/50-%E5%89%91%E6%8C%87offer.html
// 哈希表做法
class Solution {
public:
	bool duplicate(int numbers[], int length, int* duplication) {
		unordered_map<int, int> unmp;
		unmp.reserve(length); 
		for (int i = 0; i < length; i++) {
			if (unmp.find(numbers[i]) == unmp.end()) {
				unmp.insert({ numbers[i], 1 });
			}
			else {
				*duplication = numbers[i];
				return true; // 找到重复元素
			}
		}
		return false;
	}
};

#endif // DEBUG1


