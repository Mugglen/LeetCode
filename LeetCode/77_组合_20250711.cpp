#include <vector>
#include <functional>
using namespace std;



//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // 使用选和不选的思路
    // https://leetcode.cn/problems/combinations/solutions/2071017/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-65lh/
    vector<vector<int>> combine(int n, int k) {

        // 初始化结构矩阵
        vector<vector<int>> ans;
        vector<int> path;

        // dfs
        function<void(int)> dfs = [&](int i) -> void {
            int d = k - path.size(); // 还要选 d 个数
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }

            // 枚举的数不能太小，否则后面没有数可以选
            for (int j = i; j >= d; j--) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back(); // 恢复现场
            }
            };
        dfs(n); // 从 i = n 开始倒着枚举
        return ans;
    }
};
#endif // DEBUG
