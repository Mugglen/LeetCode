#include <string>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/minimum-window-substring/solutions/2713911/liang-chong-fang-fa-cong-o52mn-dao-omnfu-3ezz/?envType=study-plan-v2&envId=top-100-liked
class Solution {

private:
    bool is_covered(int cnt_s[], int cnt_t[]) {
        for (int i = 'A'; i <= 'Z'; i++) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        for (int i = 'a'; i <= 'z'; i++) {
            if (cnt_s[i] < cnt_t[i]) {
                return false;
            }
        }
        return true;
    }

public:

    string minWindow(string s, string t) {
		int cnt_s[128] = { 0 }; // ͳ��s���ַ����ִ���(������Сд��ĸ)
		int cnt_t[128] = { 0 }; // ͳ��t���ַ����ִ���(������Сд��ĸ) 
        for (char c : t) {
			cnt_t[c]++;
        }

        int m = s.size();
		int ans_left = -1, ans_right = m; // ��ʼ���𰸵����ұ߽�(��ʼ����ʱ����Ƿ�ֵ������ans_right - ans_left�����ԭ���鳤��)
        int left = 0;
        // ö���Ҷ˵�
        for (int right = 0; right < m; right++) {
			cnt_s[s[right]]++; // �Ҷ˵��ַ����ִ�����1(right�Ǵ�0��ʼ�ģ�ȷ����һ���˵����ͳ������)
            while (is_covered(cnt_s, cnt_t)) {
                if (right - left < ans_right - ans_left) { // �ҵ����̵��Ӵ�
					ans_left = left;
                    ans_right = right;
                }
                cnt_s[s[left]]--; // ��˵���ĸ�Ƴ��Ӵ�
				left++; // ��˵�����
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1); // ���ans_left��-1��˵��û���ҵ������������Ӵ������ؿ��ַ��������򷵻��Ӵ�
    }
};
#endif // DEBUG
