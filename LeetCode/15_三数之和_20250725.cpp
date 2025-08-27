#include <vector>
#include <algorithm>
using namespace std;



// https://leetcode.cn/problems/3sum/solutions/1968332/shuang-zhi-zhen-xiang-bu-ming-bai-yi-ge-pno55/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // �ǵ��ȸ��������򣬷��������ظ�����
        sort(nums.begin(), nums.end());

        // ��ʼ�����
        vector<vector<int>> result;

		// ÿ����������ƥ��һ�³�ʼ��˫ָ�루i-2�ǿ��Ǹ�˫ָ����λ�ã����ǣ�i��-2�������while(left < right)��Ҳ�ᱻ���ˣ�������ʵû�
        for (int i = 0; i < nums.size() - 2; i++) {
            
			// ���жϵ�ǰ�����Ƿ����0���������0��ֱ�ӷ��ؽ������Ϊ���治����������֮��Ϊ0�������
            if (nums[i] > 0)return result;

            // �жϵ�ǰ�����ǲ����ظ��ģ���ǰһ�������Ԫ�رȣ�ͬʱ��һ��Ԫ�ز��ñ�
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // ��ǰ�����ظ�Ԫ�ض��ҿ��ܴ�����Ԫ��
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
            
                if (nums[i] + nums[left] + nums[right] > 0)right--;
                else if (nums[i] + nums[left] + nums[right] < 0)left++;
                else {// �ҵ���
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // �����ظ�Ԫ��
                    while (left < right && nums[right] == nums[right - 1])right--;
                    while (left < right && nums[left] == nums[left + 1])left++;
                    // ����Ҫ����һ��˫ָ�룬����ȥ�غ���ָ����ͬ��Ԫ�أ�ע�����ҵ��𰸲��ƶ���˫ָ�룩
                    right--;
                    left++;
                }
                //// ����㣡�������ⲻ��
                //right--;
                //left++;
            }
        }
        return result;
    }
};


#endif // DEBUG
