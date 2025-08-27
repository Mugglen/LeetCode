#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {

public:
	int longestConsecutive(vector<int>& nums) { // 注意引用传入

		// 创建哈希表，在不要值，只需要快速查找的时候使用set
		unordered_set<int> num_set;

		// 遍历容器，插入哈希表
		for (const int& num : nums) {
			num_set.insert(num);
		}

		// 初始化最长连续序列的长度为0
		int longestStreak = 0;

		// 遍历 unordered_set 中的每个数字
		for (const int& num : num_set) {
			// 如果当前数字的前一个数字不在集合中，说明当前数字是一个连续序列的起点
			if (!num_set.count(num - 1)) { // count只是查找当前哈希表内有没有对应元素，有就返回1，没就返回0
				int currentNum = num;// 当前数字（当前检查连续序列的中间变量）
				int currentStreak = 1;// 当前连续序列的长度（连续序列长度计数器）

				// 不断检查当前数字的下一个数字是否在集合中
				while (num_set.count(currentNum + 1)) {
					currentNum += 1;// 移动到下一个数字
					currentStreak += 1; // 增加当前连续序列的长度
				
				
				}

				// 更新最长i连续序列的长度
				longestStreak = max(longestStreak, currentStreak);
			
			}
		
		
		}
		return longestStreak;
	
	
	}

};

//#define DEBUG
#ifdef DEBUG

int main() {

	vector<int> nums = { 100,4,200,1,3,2 };
	Solution solution;
	int longestStreak = solution.longestConsecutive(nums);
	cout << "最长连续序列的长度是" << longestStreak << endl;


	return 0;
}




#endif // DEBUG


