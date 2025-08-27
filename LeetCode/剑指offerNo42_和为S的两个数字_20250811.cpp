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
	// 其实也是滑动窗口的特列，剑指offerNo41和为S中，只取滑动窗口的两端元素和就是这题的写法
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.empty()) return {};
        // 初始化双指针
		int left = 0, right = array.size() - 1;
        vector<int> ans;
        while (left < right) {
            int sumTemp = array[left] + array[right];
            if (sumTemp == sum) {
                ans.push_back(array[left]);
                ans.push_back(array[right]);
				return ans; // 注意！！！找到一组就返回，不然就超时了
            }
            else if (sumTemp > sum) right--;
            else left++;
        }
        return ans;
    }
};

#endif // DEBUG1