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
		// 前6个丑数就是1-6,直接输出即可(只是加快一点,没这个也行)
        //if (index <= 6) return index;

		// 丑数可以分解为2^x * 3^y * 5^z的形式
		int i2 = 0, i3 = 0, i5 = 0;
		vector<int> res;
		res.reserve(index);
		res[0] = 1; // 第一个丑数是1

		for (int i = 1; i < index; i++) {
			// 得到下一个丑数,三者中最小的
			res[i] = min({ res[i2] * 2, res[i3] * 3, res[i5] * 5 });
			/*第一次是 2、3、5比较，得到最小的是2*/
			/*第二次是 4、3、5比较，为什么是4了呢？因为上次2已经乘了一次了，所以接下去可以放的丑数在4、3、5之间*/
			// 所以开头的三个指针就是来标记2 3 5 乘的次数的
			// 不然每次最小的肯定是*2的
			if (res[i] == res[i2] * 2) i2++;
			if (res[i] == res[i3] * 3) i3++;
			if (res[i] == res[i5] * 5) i5++;
		}
		return res[index - 1];
    }
};

#endif // DEBUG1