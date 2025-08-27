#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

// 当前思路是在46全排列的基础上修改的，加上了对重复字符的处理。
// 下面这个链接是牛客上的题解，还没看过
// https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&&tqId=11180&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	// 与hot100里的46 全排列不一样在这里是字符串,而且本题str中可能有重复字符，如输入“aa”，输出应该是【“aa”】而不是【“aa”，“aa”】
    vector<string> Permutation(string str) {
        int n = str.size();
        vector<string> ans;
        string path;
        vector<bool> on_path(n, false);
		// 注意！！！！！！！这里预留要用resize不能用reserve
        path.resize(n);// 所有排列的长度都是一样的 n

        // 相比46全排列，修改关键点！！！先排序，让相同字符相邻
        sort(str.begin(), str.end());

        // 递归接受整个字符串和当前path枚举位置
        function<void(int)> dfs = [&](int i) {

			// 递归终止条件
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                // 相比46全排列，修改关键点！！！跳过已经在path上的字符，和重复字符的处理
                if (on_path[j] || (j > 0 && str[j] == str[j - 1] && !on_path[j - 1])) continue;

                // if (!on_path[j]) {
				path[i] = str[j];
				on_path[j] = true; // 标记当前字符已使用
                dfs(i + 1);
				on_path[j] = false; // 回溯，恢复现场
                //}
            }
            };
        dfs(0);
        return ans;
    }
};


#endif // DEBUG1

