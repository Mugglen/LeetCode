#include <vector>
#include <functional>

using namespace std;

//#define DEBUG1
#ifdef DEBUG1

// ʹ��ѡ�벻ѡ��˼·
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    // �ݹ����������ǲ��ü��仯�Ļ��ᳬʱ�����ɼ�������Ƶ���������������ͬ������
	// �����ǲ��ü��仯�ĵݹ�����
    int rob(vector<int>& nums) {

        int n = nums.size();
		// ���嵱ǰ״̬dfs(i)��ʾ��ǰi����������͵���������
        function<int(int)> dfs = [&](int i) -> int {
            // �߽紦��(��������ݹ�)
            if (i < 0)return 0;

			// ��ѡ��ǰ����dfs(i - 1)�� ѡ��ǰ����dfs(i - 2) + nums[i]
            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);
			return res;
            }; // ע��lamda�����ֺ�
        return dfs(n - 1); // ע��n-1�����������
    }
};


#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

// ʹ��ѡ�벻ѡ��˼·
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
// ���Ӷȼ��㹫ʽ��״̬���� * ÿ��״̬�ļ��㸴�Ӷ�
class Solution {
public:
    // �ݹ����������ǲ��ü��仯�Ļ��ᳬʱ�����ɼ�������Ƶ���������������ͬ������
    // �������ü��仯�ĵݹ�����
    int rob(vector<int>& nums) {

        int n = nums.size();
		vector<int> memo(n, -1); // ���仯���飬��ʼ��Ϊ-1��ʾδ����

        // ���嵱ǰ״̬dfs(i)��ʾ��ǰi����������͵���������
        function<int(int)> dfs = [&](int i) -> int {
            // �߽紦��(��������ݹ�)
            if (i < 0)return 0;

			// ���memo������Ѿ��������ֱ�ӷ��ؽ��
			if (memo[i] != -1) return memo[i];

            // ��ѡ��ǰ����dfs(i - 1)�� ѡ��ǰ����dfs(i - 2) + nums[i]
            int res = max(dfs(i - 1), dfs(i - 2) + nums[i]);

			//���������memo
			memo[i] = res;

            return res;
            }; // ע��lamda�����ֺ�
        return dfs(n - 1); // ע��n-1�����������
    }
};


#endif // DEBUG2


//#define DEBUG3
#ifdef DEBUG3

// ʹ��ѡ�벻ѡ��˼·��ͬʱȥ���ݹ��С��ݡ��Ĳ��֣��������顱�Ĳ���
// �ͰѼ��仯�ݹ���������˵��ƣ��Ե����ϣ�
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
// ���Ӷȼ��㹫ʽ��״̬���� * ÿ��״̬�ļ��㸴�Ӷ�
class Solution {
public:
    // �ݹ����������ǲ��ü��仯�Ļ��ᳬʱ�����ɼ�������Ƶ���������������ͬ������
    // �������ü��仯�ĵݹ�����
    int rob(vector<int>& nums) {

        int n = nums.size();
        // �����仯�ݹ������е�״̬dfs(i)ת��Ϊ״̬����dp[i]
        // ��ʼ����ʱ�����������λ�������ʼ���
		// ԭʼ���ƹ�ϵʽdp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        // (��������ָ����±꣬����ͬʱ������i��2�����Ҹ�dpԤ��һ��ʼ�Ŀռ䣬�Ͳ������⴦��ʼ�������)
		vector<int> dp(n + 2, 0);// ��ʼ��Ϊ0, �𰸲�����Ϊ����
        // ע��dp[i]��ʾ��ǰi����������͵���������
        for (int i = 0; i < n; i++) {
            //ע�⣡�����������nums[i]���i���ü�2, ��Ϊ��Ȼdpǰ��Ԥ����2����Ч�ռ䣬���Ƕ���nums��˵��
            // һ��ʼ������Ч�ռ䣬������numsǰ��ҲԤ���������ռ䣬�ű��nums[i+2]
            dp[i + 2] = max(dp[i + 1], dp[i] + nums[i]); 
        }
        return dp[n + 1];
    }
};


#endif // DEBUG3

//#define DEBUG4
#ifdef DEBUG4 // ���Ƶ�ͬʱ������ֱ�ӴӼ��仯�����������ĵ��ƹ�ϵʽ���ֶ��������������Ҫ���Ǹ�dp����ͷ��ʼ����ͬʱҪ����ֻ��1������2�����ӵ������

// ʹ��ѡ�벻ѡ��˼·��ͬʱȥ���ݹ��С��ݡ��Ĳ��֣��������顱�Ĳ���
// �ͰѼ��仯�ݹ���������˵��ƣ��Ե����ϣ�
//https://leetcode.cn/problems/house-robber/solutions/2102725/ru-he-xiang-chu-zhuang-tai-ding-yi-he-zh-1wt1/?envType=study-plan-v2&envId=top-100-liked
// ���Ӷȼ��㹫ʽ��״̬���� * ÿ��״̬�ļ��㸴�Ӷ�
class Solution {
public:
    // �ݹ����������ǲ��ü��仯�Ļ��ᳬʱ�����ɼ�������Ƶ���������������ͬ������
    // �������ü��仯�ĵݹ�����
    int rob(vector<int>& nums) {

        int n = nums.size();
        // �����仯�ݹ������е�״̬dfs(i)ת��Ϊ״̬����dp[i]
        // ԭʼ���ƹ�ϵʽdp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        vector<int> dp(n, 0);// ��ʼ��Ϊ0, �𰸲�����Ϊ����
		// �����������(ע�����ӿ���ֻ��1������2��)
        dp[0] = nums[0]; // ֻ��һ������ʱ��͵�������
        if (n == 1) return dp[0]; // ���ֻ��һ�����ӣ�ֱ�ӷ���
        dp[1] = max(nums[0], nums[1]); // ֻ����������ʱ��͵�����Ǹ�����
        if (n == 2) return max(nums[0], nums[1]); // ���ֻ���������ӣ�͵�����Ǹ�����

        // ע��dp[i]��ʾ��ǰi����������͵���������(����i��2��ʼ)
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); 
        }
        return dp[n-1];
    }
};


#endif // DEBUG4