#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/single-number/solutions/2361995/136-zhi-chu-xian-yi-ci-de-shu-zi-wei-yun-iyd0/?envType=study-plan-v2&envId=top-100-liked
// Ҫ��ʱ�临�Ӷ�O��N��
// �ռ临�Ӷ�O(1)
// �ų� ������ �� ������ϣ��
class Solution {
public:
    // 
    int singleNumber(vector<int>& nums) {

        int x = 0;
        for (int num : nums) {
            x ^= num;
        }
        return x;


    }
};
#endif // DEBUG
