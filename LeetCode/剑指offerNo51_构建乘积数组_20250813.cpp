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
	// 没规定空间复杂度，可以用两个vector，一个存从左往右累乘，一个从右往左累乘
	// 不允许除法，不能直接除掉每个元素
    vector<int> multiply(vector<int>& A) {
        // 特判（用例说了不包含）
        if (A.size() <= 1) return {};
        // 左往右累乘
		vector<int> left(A.size(), 1);
		left[0] = A[0];
        for (int i = 1; i < A.size(); i++) {
			left[i] = left[i - 1] * A[i];
        }
        // 右往左累乘
        vector<int> right(A.size(), 1);
        right[A.size() - 1] = A[A.size() - 1];
        for (int i = A.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * A[i];
        }
		// 结果数组
		vector<int> ans(A.size(), 1);
        for (int i = 0; i < A.size(); i++) {
            // 特殊处理
            if (i == 0) ans[i] = right[i + 1];
            else if (i == A.size() - 1) ans[i] = left[i - 1];
            else ans[i] = left[i - 1] * right[i + 1];
        }
        return ans;
    }
};

#endif // DEBUG1


