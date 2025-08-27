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
		int cnt_s[128] = { 0 }; // 统计s中字符出现次数(包含大小写字母)
		int cnt_t[128] = { 0 }; // 统计t中字符出现次数(包含大小写字母) 
        for (char c : t) {
			cnt_t[c]++;
        }

        int m = s.size();
		int ans_left = -1, ans_right = m; // 初始化答案的左右边界(初始化的时候给非法值，这样ans_right - ans_left会大于原数组长度)
        int left = 0;
        // 枚举右端点
        for (int right = 0; right < m; right++) {
			cnt_s[s[right]]++; // 右端点字符出现次数加1(right是从0开始的，确保第一个端点加入统计数组)
            while (is_covered(cnt_s, cnt_t)) {
                if (right - left < ans_right - ans_left) { // 找到更短的子串
					ans_left = left;
                    ans_right = right;
                }
                cnt_s[s[left]]--; // 左端点字母移出子串
				left++; // 左端点右移
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1); // 如果ans_left是-1，说明没有找到满足条件的子串，返回空字符串，否则返回子串
    }
};
#endif // DEBUG
