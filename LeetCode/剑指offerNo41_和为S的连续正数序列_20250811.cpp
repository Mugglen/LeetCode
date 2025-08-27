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
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/41-%E5%89%91%E6%8C%87offer.html
	// 滑动窗口法，和小了移动右端点，大了移动左端点
    vector<vector<int> > FindContinuousSequence(int sum) {
        // 因为数组就是1-100，所以双指针的指就是对应元素
		int left = 1, right = 2; // 左右指针初始位置
        vector<vector<int>> ans;
		// 注意这个终止条件，应该是遍历到了right大于等于sum一半的情况，最后一直收缩左指针
        while (left < right) {
            // 连续序列求和公式(a0 + an)*n/2
			int sumTemp = (left + right) * (right - left + 1) / 2; // 计算当前窗口的和(注意是前面先乘再除2)
            if (sumTemp == sum) { // 相等，将窗口范围内所有数加入结果
                vector<int> ansTemp;
                for (int i = left; i <= right; i++) {
                    ansTemp.push_back(i);
                }
                ans.push_back(ansTemp); // 将当前窗口的结果加入到结果集中
                left++; // 注意！！！！！！移动左指针，继续寻找下一个可能的连续序列
            }
            else if (sumTemp < sum) right++; // 如果当前窗口的和小于目标和，移动右指针扩大窗口
			else left++; // 如果当前窗口的和大于目标和，移动左指针缩小窗口
        }
		return ans; // 返回所有找到的连续序列
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// 暴力解法，遍历所有可能的连续序列
class Solution {
public:
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/41-%E5%89%91%E6%8C%87offer.html
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        for (int n = sqrt(2 * sum); n >= 2; --n) {
            if (((n & 1) == 1 && sum % n == 0) || (sum % n * 2 == n)) {
                vector<int> res;
                //j用于计数，k用于遍历求值
                for (int j = 0, k = sum / n - (n - 1) / 2; j < n; j++, k++)//注意看k的求法
                    res.push_back(k);
                result.push_back(res);
            }
        }
        return result;
    }

};

#endif // DEBUG2