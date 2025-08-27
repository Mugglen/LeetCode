#include <vector>
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/longest-increasing-subsequence/solutions/24173/zui-chang-shang-sheng-zi-xu-lie-dong-tai-gui-hua-2


// 注意本体要求：并没有要求一定是连续的子串，但是要严格递增，且元素顺序不变
// 时间复杂度O（n^2）：最坏情况内层遍历n次
// 空间复杂度O（n）:dp数组长度

class Solution_dp {

public:
	int lengthOfLIS(vector<int>& nums) {
		
		// 异常处理
		if (nums.empty()) return 0;

		// 定义DP数组（dp[i]表示nums中以nums[i]结尾的最长子序列长度）
		vector<int> dp(nums.size(), 1);
	
		// 开始自底向上计算(计算dp数组的每个值，其中j的范围由i来划定)
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				// 注意！！！！不要漏了状态转移条件
				if (nums[j] < nums[i]) {
					// 状态转移方程
					dp[i] = max(dp[i], dp[j] + 1);
				}

			}
		}
		// 注意！！！！！不是max,max是比较两个数的最大值，且返回的是个迭代器，*引用该迭代器才是值
		return *max_element(dp.begin(), dp.end());

	
	}

};


// 优化版本
// dp 加二分查找
class Solution {

public:
	int lengthOfLIS(vector<int>& nums) {

		// 异常处理
		if (nums.empty()) return 0;

		// 定义DP数组（dp_tails[k]表示长度为 k+1 的子序列尾部元素的值。）
		vector<int> dpTails;
		//int length = 0; //存储LIS的长度

		// 开始自底向上计算(计算dp数组的每个值，其中j的范围由i来划定)
		for (int num : nums) {
			//二分查找[0,res) 列表区间，找出 nums[k] 的大小分界点，注意是查
			int left = 0, right = dpTails.size();

			// 要在dpTails中找到第一个比当前num大的
			while (left < right) {
				int mid = left + (right - left) / 2; // (right - left) / 2 会自动向零取整

				if (dpTails[mid] < num) {
					left = mid + 1;
				}
				else { // deTails[mid] >= num
					right = mid;
				}
			}

			// 如果找到合适的位置
			if (left < dpTails.size()) {
				dpTails[left] = num;
			}
			else {
				// 如果未找到合适位置，意味着 num 可以作为新的最大值
				dpTails.push_back(num);
				//length++;
			}


		}
		
		return dpTails.size();


	}

};

//#define DEBUG
#ifdef DEBUG
int main() {

	Solution solution;
	vector<int> nums = { 10, 9, 2, 5, 3, 7, 101, 18 };
	cout << "最长递增子序列长度：" << solution.lengthOfLIS(nums) << endl;

	return 0;
}
#endif // DEBUG
