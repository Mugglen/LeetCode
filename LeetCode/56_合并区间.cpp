#include <vector>
#include <algorithm>
//#include <ranges>

using namespace std;

// https://leetcode.cn/problems/merge-intervals/solutions/2798138/jian-dan-zuo-fa-yi-ji-wei-shi-yao-yao-zh-f2b3

// 先按左端点排序，为了将合并区间变成连续的子数组

// 时间复杂度：O(nlogn)，其中 n 是 intervals 的长度。瓶颈在排序上。
// 空间复杂度：O(1)。排序的栈开销和返回值不计入。

class Solution {

public:

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		
		// C++20的ranges库里的函数，可以对容器进行排序，默认按照容器中的元素的自然顺序（在这个例子中是按照左端点排序）
		// ranges:sort(intervals); 

		// 传统的按照左端点排序的方法(使用了Lambda)
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] < b[0];
		});

		vector<vector<int>> ans;
		for (vector<int> p : intervals){
			//依次查看右端点，更新当前区间p的右端点（合并）
			//注意会有连续交叠区间【1，3】【2，4】【3，5】
			// 所以每次合并都得拿左端点和已合并的最后一个区间ans.back()的右端点比较

			// 有重叠部分
			if (!ans.empty() && p[0] <= ans.back()[1]) {

				// 更新右端点最大值
				ans.back()[1] = max(ans.back()[1], p[1]);
			
			}
			else { // 不相交，无法合并， 成为新的待合并区间
				ans.emplace_back(p);
			}
		}
		return ans;
	}
};