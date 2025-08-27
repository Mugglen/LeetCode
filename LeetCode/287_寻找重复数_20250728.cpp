#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/find-the-duplicate-number/solutions/2361404/287-xun-zhao-zhong-fu-shu-yuan-di-jiao-h-0eja/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    vector<int> nums;

    int next(int index){
        // ֱ�ӷ��ص�ǰ��������ֵ��Ϊ��һ������
        return nums[index];
    }

    int findDuplicate(vector<int>& nums) {
        // ԭ�ض�����ʹ�û���������˼·��˫ָ��
        this->nums = nums;
        int slow = 0;
        int fast = 0;
        // ��һ������(��do��while����Ϊһ��ʼslow��fast��ʼ��Ϊһ����㣬����ֱ��ʹ��while(slow != fast))
        do {
            slow = next(slow);
            fast = next(next(fast));
        } while (slow != fast);
        slow = 0;
        // �ڶ�������
        while (slow != fast) {
            slow = next(slow);
            fast = next(fast);
        }
        return slow;
    }
};
#endif // DEBUG
