#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;


// https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/1959540/xia-biao-zong-suan-cuo-qing-kan-zhe-by-e-iaks

class Solution {

public:
	// 写法1， 哈希表（整形数组）
	// 时间复杂度O（n），n为数组的长度
	int lengthOfLongestSubstring(string s) {
		// std::string 的 .size() 和 .length() 方法在 C++ 中是等效的，
		// 没有实际的区别。它们的作用和返回值是一样的，都是返回字符串中字符的个数。
		// 只是size是C++容器的命名惯例，length是C的命名惯例
		int n = s.size(), ans = 0, left = 0;
		
		// 维护从下标 left到下标right的字符, key 是字符，value是出现的次数
		unordered_map<char, int> cnt; 

		for (int right = 0; right < n; right++) {
			
			// 取出窗口右边界的字符
			char c = s[right];
			
			// 更新哈希表内统计
			cnt[c]++;

			// 重复逻辑检测，调整左窗口，缩小至没有重复元素为止
			while (cnt[c] > 1) {

				// 边缩小边减少左窗口边界上字符的出现次数，一直缩到没有右窗口边界上的字符为止
				cnt[s[left]]--;
				left++;
			
			}
			
			// 每次移动右窗口会出现一个复合要求的子串，要每次都更新满足要求的字串长度
			// 加1是当right和left都指向同一个元素时，字串大小就是1
			ans = max(ans, right - left + 1);
		
		}
		return ans;

	}

};


//#define DEBUG
#ifdef DEBUG

int main() {

	string s = "abcabcbb";
	Solution solution;

	cout << "count:" << solution.lengthOfLongestSubstring(s) << endl;

}



#endif