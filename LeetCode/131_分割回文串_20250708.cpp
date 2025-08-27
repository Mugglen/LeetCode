#include <vector>
#include <string>
#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/palindrome-partitioning/solutions/2059414/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-fues/?envType=study-plan-v2&envId=top-100-liked
// 方法2：答案视角
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    // 回文字符串判断
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) { // 换成C++20的写法，这样可以把ans,path维护在函数里

        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        // 注意问题的转换，并不是枚举字符串，而是枚举字符串的分割方式
        // 考虑 s[i] ~ s[n-1] 怎么分割(注意写lamda最后要加分号)

        std::function<void(int)> dfs = [&](int i) {

            // 边界条件
            if (i == n) { // s 分割完成？
                ans.push_back(path);
                return;

            }

            for (int j = i; j < n; j++) { // 枚举子串的结束位置
                if (isPalindrome(s, i, j)) {
                    path.push_back(s.substr(i, j - i + 1)); // 分割
                    // 考虑剩余的 s[j+1] ~ s[n-1]怎么分割
                    dfs(j + 1);
                    path.pop_back(); // 恢复现场
                }
            }
            };
        // C++23才支持this auto&&
        //auto dfs = [&](this auto&& dfs, int i) {
        //    };
        dfs(0);
        return ans;

    }
};
#endif // DEBUG
