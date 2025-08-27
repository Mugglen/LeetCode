#include<unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x, TreeNode* left = nullptr, TreeNode* right = nullptr)
		: val(x), left(left), right(right) {}
};


// https://leetcode.cn/problems/path-sum-iii/solutions/2784856/zuo-fa-he-560-ti-shi-yi-yang-de-pythonja-fmzoc

class Solution {

public:
	int pathSum(TreeNode* root, int targetSum) {
		int ans = 0;

		// 初始化 cnt ，表示路径和为0的路径出现一次
		// 要想把任意路径和都表示成两个前缀和的差，必须添加一个 0
		// 根节点值为 1，targetSum=1。如果不把 0 加到哈希表中，
		// 按照我们的算法，没法算出这里有 1 条符合要求的路径
		unordered_map<long long, int> cnt{ {0, 1} };

		// 启动递归
		dfs(root, targetSum, 0, ans, cnt);

		return ans;
	
	}
	
private:
	void dfs(TreeNode* node,
		int targetSum,
		long long pathSum,
		int& ans,
		unordered_map<long long, int>& cnt
	) {
		// 异常值判断
		if (node == nullptr) return;

		// 更新当前路径和
		pathSum += node->val;
		
		// 判断是否存在路径和为 targetSum的路径
		// C++20写法
		//ans += cnt.contains(s - targetSum) ? cnt[s - targetSum] : 0;

		// （注意先更新ans还是先更新cnt在targetSum为0的时候有区别）

		// C++11
		if (cnt.find(pathSum - targetSum) != cnt.end()) {
			ans += cnt[pathSum - targetSum];
		}
		
		// 更新 cnt, 表示路径和为 pathSum 的路径出现了一次
		cnt[pathSum]++;

		// 递归遍历左右子树
		dfs(node->left, targetSum, pathSum, ans, cnt);
		dfs(node->right, targetSum, pathSum, ans, cnt);

		// 恢复现场，回退路径和
		cnt[pathSum]--;
	
	}

};