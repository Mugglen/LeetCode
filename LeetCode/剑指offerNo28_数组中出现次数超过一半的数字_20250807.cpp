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
    // 要求空间复杂度O（1），不能用别的空间存数组每个元素出现的个数了
	// 先试试暴力法，遍历数组统计每个元素出现的次数
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
	// 好像其实是hot100 169多数元素，就觉得怎么这么眼熟
	int MoreThanHalfNum_Solution(vector<int>& numbers) {
		// 使用摩尔投票法，成立前提是有超过一半的元素，所以最后我们需要判断找到的元素是否出现超过一半
		int cnt = 0, num = 0;
		// 与候选元素相同增加选票，不同减少选票，选票归零换下一个元素候选，最后留下的候选者就是多数元素
		for (int i = 0; i < numbers.size(); ++i) {
			if (cnt == 0) {
				num = numbers[i];
					cnt = 1;
			}
			else {
				num == numbers[i] ? cnt++ : cnt--;
			}
		}
		// 判断是不是大于一半
		cnt = count(numbers.begin(), numbers.end(), num);
		return cnt > numbers.size() / 2 ? num : 0;
	}
};

#endif // DEBUG2