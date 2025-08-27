#include <vector>
#include <unordered_map> 
#include <iostream>
using namespace std;

// 注意子数组的特点
// 必须是连续的（不能跳跃元素）。
// 长度可以不同（可以是单个元素，也可以是整个数组）。
// 顺序不能变（必须保持原数组中元素的相对顺序）。


// 方法二：前缀和 + 哈希表优化
// 核心思想，前缀和的差就是字串和，直接检查当前pre-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // 记录前缀和出现次数
        mp[0] = 1;  // 处理前缀和本身等于 k 的情况
        int count = 0, pre = 0;  // count 统计满足条件的子数组个数, pre 记录前缀和

        for (auto& x : nums) {  // 遍历数组
            pre += x;  // 更新前缀和
            if (mp.find(pre - k) != mp.end()) {  // 如果 pre-k 出现在哈希表中
                count += mp[pre - k];  // 累加出现次数
            }
            mp[pre]++;  // 记录当前前缀和的出现次数
        }
        return count;
    }
};


//#define DEBUG
#ifdef DEBUG

int main() {
	vector<int> nums = { 1, 1, 1 };
	int k = 2;

	Solution solution;
	int result = solution.subarraySum(nums, k);
	cout << " 该数组中和为"<< k << "的子数组的个数是："  << result<< endl;

}


#endif // DEBUG

