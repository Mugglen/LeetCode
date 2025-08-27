#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;





class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		// 创建哈希表
		unordered_map<int, int> hashtable;

		// 边查找边往哈希表里塞东西
		for (int i = 0; i < nums.size(); ++i) {

			// 如果没查到，直接返回hashtable.end()，如果查到了，it 就是对应的键值对(因为返回类型会变，所以才写的auto)
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {

				// 只查一对键值对，而且题目要求的是返回数组里的下标，所以先把找到的键值对的值it->second，和
				// 当前数组元素的下标，就是参与和运算的两个元素的索引（注意，此时的哈希表的键是数据的元素，值是数组的下标）
				// 哈希表只能对键进行查找，所以要把元素存成键
				return { it->second, i };
			
			}
			// 没查到的话就存进哈希表里
			hashtable[nums[i]] = i;


		}
		return {};
	}
};



//#define DEBUG
#ifdef DEBUG

int main() {
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	Solution solution;
	vector<int> sum_index = solution.twoSum(nums, target);

	for (int i = 0; i < sum_index.size(); i++) {
		cout << "数组中和为" << target << "的元素下标为" << solution.twoSum(nums, target)[i] << endl;
	}
	return 0;

}

#endif // DEBUG
