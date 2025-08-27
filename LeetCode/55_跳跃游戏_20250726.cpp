#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG


class Solution {
public:
    bool canJump(vector<int>& nums) {

        // ��ʼ�����ɴ����
        int mx = 0;

        for (int i = 0; i < nums.size(); i++) {
        
            // �ȼ��mx�Ƿ�С�ڵ�ǰi��С�ڵĻ���ǰλ���Ѿ����ɴ���
			if (mx < i)return false;
            // ��ǰλ�ÿɴ�������ɴ����
            mx = max(mx, i + nums[i]);

			// ����ɴ�����Ѿ����������һ��λ�ã�ֱ�ӷ���true
			if (mx >= nums.size() - 1)return true;
        
        }
        return true;
    }
};
#endif // DEBUG
