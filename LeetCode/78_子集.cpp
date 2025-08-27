#include<vector>
#include<functional>

using namespace std;


// https://leetcode.cn/problems/subsets/solutions/2059409/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-8tkl

// �ܵ�ʱ�临�Ӷ��� �ݹ����Ľڵ��� * ÿ���ڵ�Ĵ���ʱ�䣺
// ʱ�临�Ӷ� = O(2^n)*O(n) = O(n*2^n)
// �ռ临�Ӷ�O��n��

class Solution {

public:
	vector<vector<int>> subsets(vector<int>& nums) {

		// ����Ӽ�����
		vector<vector<int>> ans;
		// ���ڹ�����Ӽ�
		vector<int> path;
		int n = nums.size();

        // ʹ�� lambda ���ʽ����ݹ麯�� dfs
        // dfs ������������ö�����п��ܵ��Ӽ�
        // i ������ʾ��ǰ�ݹ������ڿ��ǵ�Ԫ�ص�����
        // 
        // C++20д��
        //auto dfs = [&](this auto&& dfs, int i) -> void {
        //    ans.emplace_back(path);  // ����ǰ�Ӽ���ӵ�����

        //    // ������ i ��ʼ������ÿ��Ԫ�ؼ��뵱ǰ�Ӽ�
        //    for (int j = i; j < n; j++) {
        //        path.push_back(nums[j]);  // ����ǰԪ����ӵ��Ӽ� path ��
        //        dfs(j + 1);  // �ݹ鴦����һ��Ԫ�أ�ע������ j + 1 ��֤���ظ�ѡ����ͬ��Ԫ��
        //        path.pop_back();  // �ָ��ֳ������ݣ������Ե�ǰԪ�ص�ѡ��
        //    }
        //    };

        function<void(int)> dfs;
        dfs = [&](int i) -> void {
            ans.emplace_back(path); // ����ǰ�Ӽ���ӵ�����

            // ������ i ��ʼ������ÿ��Ԫ�ؼ��뵱ǰ�Ӽ�
            for (int j = i; j < n; j++) {
                path.push_back(nums[j]); // ����ǰԪ����ӵ��Ӽ� path ��
                dfs(j + 1); // �ݹ鴦����һ��Ԫ�أ�ע������ j + 1 ��֤���ظ�ѡ����ͬ��Ԫ��
                path.pop_back();  // �ָ��ֳ��� ���ݣ������Ե�ǰԪ�ص�ѡ��
            }
            };
        
        // ������0��ʼ���� dfs �������������е��Ӽ�
        dfs(0);

        return ans;
	
	}

};

// ������������ö��
class Solution_violence {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();  // ��ȡ�������� nums �Ĵ�С����������Ԫ�صĸ���
        vector<vector<int>> ans(1 << n);  // ����һ����ά���� ans �����洢�����Ӽ�
        // 2^n ���Ӽ���ÿ���Ӽ���һ�� vector<int>

// ö��ȫ�� U �������Ӽ�
        for (int i = 0; i < (1 << n); i++) { // 1 << n �� 2^n����ʾȫ�� U �����Ӽ��ĸ���
            for (int j = 0; j < n; j++) {
                if (i >> j & 1) { // �жϼ��� i �Ƿ���� nums[j]
                    ans[i].push_back(nums[j]);  // ����������� nums[j] �����Ӽ� ans[i] ��
                }
            }
        }

        return ans;  // ���ذ��������Ӽ��Ľ��
    }
};
