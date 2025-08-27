#include <vector>

using namespace std;

struct TreeNode {

	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x = -1, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), left(left), right(right) {}

};


class Solution {

private:
	// 左边界和有边界
	TreeNode* dfs(vector<int>& nums, int left, int right) {
		
		// 左右位置标识重合，作为递归结束标识
		if (left == right)  return nullptr;

		// 计算中间节点位置
		int mid = left + (right - left) / 2;

		return new TreeNode(nums[mid], dfs(nums, left, mid), dfs(nums, mid + 1, right));
	
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {

		// 启动递归
		return dfs(nums, 0, nums.size());
	
	}

};