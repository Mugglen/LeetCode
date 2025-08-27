#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG


class Solution {
public:
    bool canJump(vector<int>& nums) {

        // 初始化最大可达距离
        int mx = 0;

        for (int i = 0; i < nums.size(); i++) {
        
            // 先检查mx是否小于当前i，小于的话当前位置已经不可达了
			if (mx < i)return false;
            // 当前位置可达，更新最大可达距离
            mx = max(mx, i + nums[i]);

			// 如果可达距离已经超过了最后一个位置，直接返回true
			if (mx >= nums.size() - 1)return true;
        
        }
        return true;
    }
};
#endif // DEBUG
