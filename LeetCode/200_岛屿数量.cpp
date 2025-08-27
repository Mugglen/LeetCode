#include<vector>
#include<functional>

using namespace std;


// https://leetcode.cn/problems/number-of-islands/solutions/2965773/ba-fang-wen-guo-de-ge-zi-cha-shang-qi-zi-9gs0

// 注意DFS核心要点，不能重复访问走过的格子

// 时间复杂度O(mn)
// 空间复杂度O(mn)

// 岛屿上插旗
// C++20写法，C++11里的lambda不能自己调用自己，就是没有this auto && dfs这样，但使用lambda递归好像性能更好
//class SolutionCpp20 {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
//            // 出界，或者不是 '1'，就不再往下递归
//            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
//                return;
//            }
//            grid[i][j] = '2'; // 插旗！避免来回横跳无限递归
//            dfs(i, j - 1); // 往左走
//            dfs(i, j + 1); // 往右走
//            dfs(i - 1, j); // 往上走
//            dfs(i + 1, j); // 往下走
//            };
//
//        int ans = 0;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == '1') { // 找到了一个新的岛
//                    dfs(i, j); // 把这个岛插满旗子，这样后面遍历到的 '1' 一定是新的岛
//                    ans++;
//                }
//            }
//        }
//        return ans;
//    }
//};


// C++11写法（用包装器来让lambda实现递归）

class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        
        // 异常值处理
        if (grid.empty() || grid[0].empty()) return 0;

        // 计算边界
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        // 定义 std::function
        function<void(int, int)> dfs;

        //递归lambda(注意是赋值要加分号)
        dfs = [&](int i, int j) {
            // 边界处理(注意m和n分别是行数和列数，但索引是从0开始，所以i == m的时候已经超出索引了)
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                return;
            }
            grid[i][j] = '2'; //插旗，变成不是‘1’的值就行

            dfs(i, j - 1);// 左
            dfs(i, j + 1);// 右
            dfs(i - 1, j);// 上
            dfs(i + 1, j);// 下

         };
        
        // 遍历网络
        for (int i = 0; i < m; ++i) {
            for (int j = 0; i < n; ++j) {
                // 撞到岛了
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }
};



// 成员函数写法，需要手动管理多个变量的传递
class Solution2 {
private:
    void dfs(std::vector<std::vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '2';
        dfs(grid, i, j - 1, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    ++ans;
                }
            }
        }
        return ans;
    }
};