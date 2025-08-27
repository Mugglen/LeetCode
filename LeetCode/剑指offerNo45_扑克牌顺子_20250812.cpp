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
    // https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&&tqId=11198&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
    //这个题解的第一种方法
    bool IsContinuous(vector<int>& numbers) {
        // 先排序
        sort(numbers.begin(), numbers.end());
        // 统计大小王的数量（0的数量）
		int zeroCount = 0;
		int i = 0; // 上一个非大小王的数字
        while (numbers[i] == 0) {
            zeroCount++;
            i++;
        }
        // 记录非零元素之间成为顺子需要补齐的元素个数，然后和0元素比较
		int needCount = 0;
		// 注意要和i + 1比较，所以索引范围是 i < numbers.size() - 1
        for (; i < numbers.size() - 1; i++) {
			if (numbers[i] == numbers[i + 1]) return false; // 有重复元素，不能成为顺子
			needCount += numbers[i + 1] - numbers[i] - 1; // 计算需要补齐的元素个数
        }
		if (zeroCount >= needCount) return true; // 如果大小王的数量大于等于需要补齐的元素个数，则可以成为顺子
        else return false; // 否则不能成为顺子
    }
};
#endif // DEBUG1