#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/maximum-product-subarray/solutions/2968916/dong-tai-gui-hua-jian-ji-gao-xiao-python-i778/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int maxProduct(vector<int>& nums) {

		// ά������dp���飬һ����¼��0��i���������˻���һ����¼��С������˻�
        int n = nums.size();
		vector<int> dp_max(n, 0), dp_min(n, 0);
        // ��ʼ��
        dp_max[0] = dp_min[0] = nums[0];
		// �� i = 1 ��ʼ��������   
        for (int i = 1; i < n; i++) {
			int x = nums[i];
            // �� x �ӵ��Ҷ˵�Ϊ i-1 �ģ��˻����/��С����������棬
            // ���ߵ������һ�������飬ֻ�� x һ��Ԫ��
            // ע��max(����Ҫ����һ������{})
            dp_max[i] = max({ dp_max[i - 1] * x, dp_min[i - 1] * x, x });
            dp_min[i] = min({ dp_max[i - 1] * x, dp_min[i - 1] * x, x });
        }
        return ranges::max(dp_max);
    }
};


#endif // DEBUG
