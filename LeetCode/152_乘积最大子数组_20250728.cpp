#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/maximum-product-subarray/solutions/2968916/dong-tai-gui-hua-jian-ji-gao-xiao-python-i778/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //  ÿ��λ������״̬
		// dp_max[i]��ʾ�� nums[i] ��β�����˻�
        // dp_min[i]��ʾ�� nums[i] ��β����С�˻�
        int n = nums.size();
        vector<int> dp_max(n, 0), dp_min(n, 0);
		dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        // ��ʼ����(����㣡������������ѭ�������1)
        //for (int i = 0; i < n; i++) {
        for (int i = 1; i < n; i++) {
            // ״̬ת�Ʒ���(dp_max��dp_min���п�����0�����Եð�nums[i]������һ�����鿼�ǽ�ȥ)
            // ע��max���Զ���������󣬵��Ƕ����������Ҫ
            dp_max[i] = max({ dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i] });
            dp_min[i] = min({ dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i], nums[i] });

        }
        // ʹ������д��,���ص�������������Ҫ�����ã����鷳(�����ٶȻ��ranges���ܶ�)
        //return *max_element(dp_max.begin(), dp_max.end());
        return ranges::max(dp_max);
    }
};


#endif // DEBUG
