#include <vector>
#include <numeric> // reduceͷ�ļ�

using namespace std;

// 0-1��������(���������Ŀ�����������ͣ���Ϊ����������nums��Ԫ����Ϊ�������뱳��������)
// ע����ĿҪ�����������������������������������ֵ
// https://www.bilibili.com/video/BV16Y411v7Y6/?vd_source=7863beabe20c537c924d81df79243393
// https://leetcode.cn/problems/target-sum/
//#define DEBUG
#ifdef DEBUG

// ��ǰʹ������Ƶ���˼·
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

		// ֱ��ʹ��target��Ϊ��������������м����������ѡȡ����������Ϊ��������
        // ��������Ϊp����������ֵ��Ϊn = s - p��sΪ����Ԫ�غ�
        // ����target = p - (s - p)���õ�p = (s + t)/2
		// ʹ��C++17�����reduce��������������Ԫ�غ�
        target += reduce(nums.begin(), nums.end());
        // ����(����С��0����Ϊ��ʾ���������͵����������ұ�����ż��)
        if (target < 0 || target % 2) return 0;
        // ȡ�����鳤��
        int n = nums.size();

		// ���㱳������
		int capacity = target / 2;

        // д���������ⷶʽ�����仯��������capacity + 1��Ϊ�˼���0�������
		vector<vector<int>> memo(n, vector<int>(capacity + 1, -1)); // -1��ʾδ����

		// ��ǰ����ʣ������capacity����ǰ��Ʒ����i�������������
		// C++ 23�����lambda���ʽ����ֱ��ʹ�õݹ�s
        auto dfs = [&](this auto&& dfs, int i, int capacity)-> int {
            // �߽紦��
			if (i < 0) return capacity == 0; // û����Ʒ��,����Ƿ�պ���������
            // ���仯����(��������dfs�Ĳ���)
            int& res = memo[i][capacity];
			if (res != -1) return res; // ����Ѿ��������ֱ�ӷ��ؽ��
            // ��ʼѡ����Ʒ
            // ��ǰ��Ʒ�������ڱ���ʣ�����������ܷ��뱳����ֻ�ܲ�ѡ
			if (capacity < nums[i]) return res = dfs(i-1, capacity); 
			// ��ǰ��Ʒ����С�ڵ��ڱ���ʣ������������ѡ�񲻷�������
			// ע������ļӷ�ԭ�������뱳��������Ͳ����뱳��������������ǻ���ģ�������н���
            return res = dfs(i - 1, capacity) + dfs(i - 1, capacity - nums[i]);

            };
        return dfs(n - 1, capacity);
    }
};



#endif // DEBUG


//#define DEBUG2
#ifdef DEBUG2
// ��ǰʹ������Ƶ���˼·������ɵ���
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        // ֱ��ʹ��target��Ϊ��������������м����������ѡȡ����������Ϊ��������
        // ��������Ϊp����������ֵ��Ϊn = s - p��sΪ����Ԫ�غ�
        // ����target = p - (s - p)���õ�p = (s + t)/2
        // ʹ��C++17�����reduce��������������Ԫ�غ�
        target += reduce(nums.begin(), nums.end());
        // ����(����С��0����Ϊ��ʾ���������͵����������ұ�����ż��)
        if (target < 0 || target % 2) return 0;
        // ȡ�����鳤��
        int n = nums.size();

        // ���㱳������
        int capacity = target / 2;

        // д���������ⷶʽ����ʼ��dp���飩(ע��!!!!!!����Ϊ�˴���Խ�����⣬���ƹ�ϵʽ���i����1�ˣ������ʼ��dp�����ʱ��nҲҪ����1)
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0)); 
		dp[0][0] = 1; // ��ʼ״̬����������Ϊ0ʱ����һ�ַ���(��ѡ�κ���Ʒ)

        // ��ǰ����ʣ������capacity����ǰ��Ʒ����i���������ұ���
		// ��ö����Ʒ
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= capacity; c++) { // ע��!!!!!!����С�ڵ���
                // ��ʼѡ����Ʒ
                // ��ǰ��Ʒ�������ڱ���ʣ�����������ܷ��뱳����ֻ�ܲ�ѡ
				// Ϊ�˱���Խ�磬c��0��ʼ������������ж���c < nums[i]��ͬʱi����������1��������Ϊnums����������
                if (c < nums[i]) dp[i + 1][c] = dp[i][c];
                // ��ǰ��Ʒ����С�ڵ��ڱ���ʣ������������ѡ�񲻷�������
                else dp[i + 1][c] = dp[i][c] + dp[i][c - nums[i]];
            }
        }
        return dp[n][capacity];
    }
};

#endif // DEBUG2


//#define DEBUG3
#ifdef DEBUG3
// ��ǰʹ������Ƶ���˼·������ɵ��ƺ󣬽��пռ��Ż���ʹ��2������ռ�
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        target += reduce(nums.begin(), nums.end());
        if (target < 0 || target % 2) return 0;
        int n = nums.size();
        int capacity = target / 2;
        
		// �Ż��㣬ֻ��ʼ�����У���Ϊ���ֻ������ǰһ�еĽ���������������벻ʹ�õ���
        vector<vector<int>> dp(2, vector<int>(capacity + 1, 0));
        dp[0][0] = 1; 

        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= capacity; c++) {
				// ͨ�������� % 2���л��У�����ʹ�ö���Ŀռ�
                if (c < nums[i]) 
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else 
                    dp[(i + 1) % 2][c] = dp[i % 2][c] + dp[i % 2][c - nums[i]];
            }
        }
        return dp[n % 2][capacity];
    }
};

#endif // DEBUG3



//#define DEBUG3
#ifdef DEBUG3
// ��ǰʹ������Ƶ���˼·������ɵ��ƺ󣬽��пռ��Ż���
// ʹ��1������ռ䣬Ϊ�˱��������и��ǵ��������к������ڼ����ֵ�������Զ����µķ�����ÿ�α�֤���������Ḳ�Ǻ���Ҫʹ�õ�ֵ
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        target += reduce(nums.begin(), nums.end());
        if (target < 0 || target % 2) return 0;
        int n = nums.size();
        int capacity = target / 2;

		// �Ż��㣬ֻ��ʼ��1�У���Ϊ��������ڵ�ǰ����С������Ԫ�أ�����Ҫ�����Զ����µķ���
        vector<int> dp(capacity + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int c = capacity; c >= nums[i]; c--) {
                // �����Զ�����
                dp[c] = dp[c] + dp[c - nums[i]];
            }
        }
        return dp[capacity];
    }
};

#endif // DEBUG3