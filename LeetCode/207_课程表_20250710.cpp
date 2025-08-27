#include <vector>
#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG

// https://leetcode.cn/problems/course-schedule/solutions/2992884/san-se-biao-ji-fa-pythonjavacgojsrust-by-pll7/?envType=study-plan-v2&envId=top-100-liked
// 三色标记法
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // 创建有向图, 注意原来提供的依赖关系,在有向图里是从前置课程走向原课程
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]); // 注意!!!!反向推入
        }

        vector<int> colors(numCourses);

        // 遍历逻辑,返回true表示找到了环
        function<bool(int x)> dfs = [&](int x) -> bool {
            colors[x] = 1; // 标记 x 正在访问中
            for (int y : graph[x]) {
                if (colors[y] == 1 || colors[y] == 0 && dfs(y)) {
                    return true;// 找到环
                }
            }
            colors[x] = 2; // 标记完全访问完毕
            return false;
            };

        // 启动遍历,有环则返回false
        for (int i = 0; i < numCourses; i++) {
            if (colors[i] == 0 && dfs(i)) {
                return false;
            }
        }

        return true;
    }
};


#endif // DEBUG
