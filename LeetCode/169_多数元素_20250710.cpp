#include <vector>

using namespace std;

// https://leetcode.cn/problems/majority-element/solutions/2362000/169-duo-shu-yuan-su-mo-er-tou-piao-qing-ledrh/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    // Ħ��ͶƱ
    // ʱ�临�Ӷ�O��N��
    // �ռ临�Ӷ�O��1��
    int majorityElement(vector<int>& nums) {

        int x = 0, votes = 0;

        for (int num : nums) {
            if (votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        return x;

    }
};



#endif // DEBUG
