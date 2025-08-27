#include <vector>

using namespace std;
// https://leetcode.cn/problems/jump-game-ii/solutions/2926993/tu-jie-yi-zhang-tu-miao-dong-tiao-yue-yo-h2d4/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
// ע����Ŀ˵�ˣ������������Ա�֤�ɴ�����û���ǲ��ɴ�����
class Solution {
public:
    int jump(vector<int>& nums) {

        // ����Ծ��Ϸ1�Ļ����ϣ�ÿ��ѡȡ��ǰ������Χ�ڣ��Ҷ˵㣩��Զ��������Ϊ��һ���Ĳ���
		// ע�ⲻ��ѡ��ǰ������Χ�ڵ���󲽳���������Զ�������������һ��ʼ�����
        int ans = 0;
		int cur_right = 0; // ��ǰ��Ծ��Χ���Ҷ˵�
        int next_right = 0; // ��һ�����Ҷ˵�����ֵ

        for (int i = 0; i + 1 < nums.size(); i++) {
            // ���������У���¼��һ����ѡ����Զ��
            next_right = max(next_right, i + nums[i]);
            // �����굱ǰһ����Ծ��Χ�����е㣬�ٸ�����һ����Ծ
            if (i == cur_right) {
				// ���������￼�ǲ��ɴ��������������cur_rightʱ��next_right����cur_right��Ӧ�þͲ��ɴ���ɴ�Ӧ�����һλ����0
                cur_right = next_right;
                ans++;
            }
        }
        return ans;

    }
};
#endif // DEBUG

//#define PRETICE
#ifdef PRETICE
class Solution {
public:
    int jump(vector<int>& nums) {

        int ans = 0;
		int cur_right = 0; // ��ǰ��Ծ��Χ���Ҷ˵�
        int next_right = 0; // ��һ���Ҷ˵����ֵ

        // ����˼·���Ǳ��������У��ҵ���ǰ��Ծ��Χ�ڣ���һ�������Ҷ˵���Զ��
        for (int i = 0; i + 1 < nums.size(); i++) {
            next_right = max(next_right, i + nums[i]);
            if (i == cur_right) {
                cur_right = next_right;
                ans++;
            }
        }
        return ans;
    }
};
#endif // PRETICE