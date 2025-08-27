#include<vector>
#include<functional>

using namespace std;


// https://leetcode.cn/problems/subsets/solutions/2059409/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-8tkl

// 总的时间复杂度是 递归树的节点数 * 每个节点的处理时间：
// 时间复杂度 = O(2^n)*O(n) = O(n*2^n)
// 空间复杂度O（n）

class Solution {

public:
	vector<vector<int>> subsets(vector<int>& nums) {

		// 结果子集数组
		vector<vector<int>> ans;
		// 正在构造的子集
		vector<int> path;
		int n = nums.size();

        // 使用 lambda 表达式定义递归函数 dfs
        // dfs 函数的作用是枚举所有可能的子集
        // i 参数表示当前递归中正在考虑的元素的索引
        // 
        // C++20写法
        //auto dfs = [&](this auto&& dfs, int i) -> void {
        //    ans.emplace_back(path);  // 将当前子集添加到答案中

        //    // 从索引 i 开始，尝试每个元素加入当前子集
        //    for (int j = i; j < n; j++) {
        //        path.push_back(nums[j]);  // 将当前元素添加到子集 path 中
        //        dfs(j + 1);  // 递归处理下一个元素，注意这里 j + 1 保证不重复选择相同的元素
        //        path.pop_back();  // 恢复现场，回溯：撤销对当前元素的选择
        //    }
        //    };

        function<void(int)> dfs;
        dfs = [&](int i) -> void {
            ans.emplace_back(path); // 将当前子集添加到答案中

            // 从索引 i 开始，尝试每个元素加入当前子集
            for (int j = i; j < n; j++) {
                path.push_back(nums[j]); // 将当前元素添加到子集 path 中
                dfs(j + 1); // 递归处理下一个元素，注意这里 j + 1 保证不重复选择相同的元素
                path.pop_back();  // 恢复现场， 回溯：撤销对当前元素的选择
            }
            };
        
        // 从索引0开始调用 dfs 函数，生成所有的子集
        dfs(0);

        return ans;
	
	}

};

// 方法：二进制枚举
class Solution_violence {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();  // 获取输入数组 nums 的大小，即集合中元素的个数
        vector<vector<int>> ans(1 << n);  // 创建一个二维数组 ans 用来存储所有子集
        // 2^n 个子集，每个子集是一个 vector<int>

// 枚举全集 U 的所有子集
        for (int i = 0; i < (1 << n); i++) { // 1 << n 是 2^n，表示全集 U 所有子集的个数
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) { // 判断集合 i 是否包含 nums[j]
                    ans[i].push_back(nums[j]);  // 如果包含，将 nums[j] 加入子集 ans[i] 中
                }
            }
        }

        return ans;  // 返回包含所有子集的结果
    }
};
