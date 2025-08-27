#include<vector>

using namespace std;
// https://leetcode.cn/problems/sort-colors/solutions/3679069/on-cha-ru-pai-xu-jian-ji-xie-fa-pythonja-zk60/?envType=study-plan-v2&envId=top-100-liked
// #define DEBUG
#ifdef DEBUG

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // 初始化0和1的位置
        int p0 = 0, p1 = 0;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
			nums[i] = 2; // 默认设置为2
            if (x <= 1) {
                nums[p1++] = 1;
            }
            if (x == 0) {
                nums[p0++] = 0;
            }
        }
    }
};



#endif // DEBUG
