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
        // 正反标记符号、小数点、e是否出现过
        bool sign = false, decimal = false, hasE = false;
        for (int i = 0; i < strlen(string); ++i) {
            // 挨个列举特殊字符出错的情况
			// 科学计数法的e或E
            if (string[i] == 'e' || string[i] == 'E') {
				if (i == strlen(string) - 1) return false; // e后面必须有数字(小数点在后面处理)
				if (hasE) return false; // e只能出现一次
				hasE = true; // 标记e出现过
            }
            // 正负号
            else if (string[i] == '+' || string[i] == '-') {
				// 第一次出现正负号，但不在开头，也不紧挨着e后面
                if (!sign && i > 0 && string[i - 1] != 'e' && string[i - 1] != 'E') return false;
                // 第二次出现正负号，必须紧挨在e后面(出现过了，可以判断i不是0，不用担心i - 1溢出)
                if (sign && string[i - 1] != 'e' && string[i - 1] != 'E') return false;
				sign = true; // 标记正负号出现过
            }
            // 小数点
            else if (string[i] == '.') {
				// e 后面不能有小数点(不只是string[i - 1]不能是e，整个e后面都不能出现)
                if (hasE || decimal) return false;
				decimal = true; // 标记小数点出现过
            }
            // 判断数字
			else if (string[i] < '0' || string[i] > '9')  return false; // 不是数字
        }
        // 判断完毕
		return true; // 如果没有返回false，说明是数字
    }
};

#endif // DEBUG1


