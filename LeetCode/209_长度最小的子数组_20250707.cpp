#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG


// https://leetcode.cn/problems/minimum-size-subarray-sum/solutions/1959532/biao-ti-xia-biao-zong-suan-cuo-qing-kan-k81nh/
// ʹ�û������ڣ�ö���Ҷ˵㣬��С��˵㣨Ҳ���Կ�����˫ָ�룩
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n + 1, sum = 0, left = 0; // ��ΪansҪ���Ƚϣ����Գ�ʼ��Ϊ����+1
        for (int right = 0; right < n; right++) { // ö���������Ҷ˵�
            sum += nums[right];
            // ��С��˵�
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if (sum >= target) {
                ans = min(ans, right - left + 1); // ���������鳤��ʱ��ȷ���Ӳ���1����ʹ�ô�������ֵ�ķ��������統ǰ����ָ�����ָ��ͬһ��Ԫ��
            }
        }
        return ans <= n ? ans : 0;
    }
};

// ʱ�临�Ӷȣ�O��n��
// �ռ临�Ӷȣ�


#endif // DEBUG


//#define PRETICE
#ifdef PRETICE

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        // ��ȡ���鳤�ȣ���ʼ���𰸣�Ϊ�����Ƚ��ǲ���û��������������Ҫ�󣬳�ʼ���𰸴�СΪn+1
        int n = nums.size();
        int ans = n + 1;
        int left = 0;
        int sum = 0;

        // ������������
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // ����ƶ���ָ��������ܺ��Ƿ����target
            while (sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }

            // ���½��������㣡������ע�����ansҪ���жϣ������Ǵ��ڵ��ڣ����ǵ������ڣ�
            if (sum >= target) {
                ans = min(ans, right - left + 1);
            }
            

        }
        // ����ʱ���治����������ĿҪ���������
        return ans <= n ? ans : 0;
    }
};



#endif // PRETICE
