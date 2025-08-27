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
	// ��߽���б߽�
	TreeNode* dfs(vector<int>& nums, int left, int right) {
		
		// ����λ�ñ�ʶ�غϣ���Ϊ�ݹ������ʶ
		if (left == right)  return nullptr;

		// �����м�ڵ�λ��
		int mid = left + (right - left) / 2;

		return new TreeNode(nums[mid], dfs(nums, left, mid), dfs(nums, mid + 1, right));
	
	}

public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {

		// �����ݹ�
		return dfs(nums, 0, nums.size());
	
	}

};