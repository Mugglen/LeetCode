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

		// ��ʼ�� cnt ����ʾ·����Ϊ0��·������һ��
		// Ҫ�������·���Ͷ���ʾ������ǰ׺�͵Ĳ�������һ�� 0
		// ���ڵ�ֵΪ 1��targetSum=1��������� 0 �ӵ���ϣ���У�
		// �������ǵ��㷨��û����������� 1 ������Ҫ���·��
		unordered_map<long long, int> cnt{ {0, 1} };

		// �����ݹ�
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
		// �쳣ֵ�ж�
		if (node == nullptr) return;

		// ���µ�ǰ·����
		pathSum += node->val;
		
		// �ж��Ƿ����·����Ϊ targetSum��·��
		// C++20д��
		//ans += cnt.contains(s - targetSum) ? cnt[s - targetSum] : 0;

		// ��ע���ȸ���ans�����ȸ���cnt��targetSumΪ0��ʱ��������

		// C++11
		if (cnt.find(pathSum - targetSum) != cnt.end()) {
			ans += cnt[pathSum - targetSum];
		}
		
		// ���� cnt, ��ʾ·����Ϊ pathSum ��·��������һ��
		cnt[pathSum]++;

		// �ݹ������������
		dfs(node->left, targetSum, pathSum, ans, cnt);
		dfs(node->right, targetSum, pathSum, ans, cnt);

		// �ָ��ֳ�������·����
		cnt[pathSum]--;
	
	}

};