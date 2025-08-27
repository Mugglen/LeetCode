#include <string>
#include <vector>
#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/generate-parentheses/?envType=study-plan-v2&envId=top-100-liked
// 枚举当前位置是左括号还是右括号（有约束的从2n个位置中选n个放左括号）
// 约束：因为当前左括号个数不能超过n ，右括号个数不能超过左括号个数
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string path(n * 2, 0); // 所有括号长度都是一样的 2n

        // 目前填入了left个左括号，right个右括号
        //auto dfs = [&](this auto&& dfs, int left, int right) -> void {
        function<void(int, int)> dfs = [&](int left, int right) -> void {
            // 结束条件
            if (right == n) { // 左括号个数始终大于等于右括号，所以用右括号来判断
                ans.emplace_back(path);
                return;
            }
            if (left < n) { // 可以填入左括号
                path[left + right] = '('; // 直接覆盖（相当于恢复现场）
                dfs(left + 1, right); // 直接一路选左括号到n个然后选满右括号return
            }
            if (right < left) { // 可以填入右括号
                path[left + right] = ')'; // 直接覆盖(上一个if的结果，这样上一个if里的dfs结束后就不用还原现场了)
                dfs(left, right + 1);
            }
            };
        dfs(0, 0);
        return ans;
    }
};

int main() {

    Solution solution;
    solution.generateParenthesis(3);
    return 0;
}


#endif // DEBUG
