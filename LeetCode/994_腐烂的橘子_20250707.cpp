#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    int DIRECTION[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };// 预定义四个方向

    int orangesRotting(vector<vector<int>>& grid) {

        // 获取行数，列数
        int m = grid.size(), n = grid[0].size();

        int fresh = 0; // 用于新鲜橘子计数

        vector<pair<int, int>> q; // 用于统计腐烂橘子

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++; // 新鲜橘子
                }
                else if(grid[i][j] == 2) {
                    q.emplace_back(i, j); // 一开始就腐烂的橘子
                }
            }
        }

        int ans = 0; // 经过的时间
        while (fresh && !q.empty()) { // 还有新鲜橘子，同时从腐烂橘子位置开始遍历（保存腐烂橘子位置的意义，减少遍历次数）
            ans++; // 经过一分钟
            vector<pair<int, int>> next; // 当前轮次腐烂的橘子
            for (auto& [x, y] : q) {
                for (auto d : DIRECTION) {
                    // 检查当前腐烂橘子上下左右的位置
                    int i = x + d[0], j = y + d[1];
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) { // 索引在范围内，当前橘子新鲜
                        fresh--;
                        grid[i][j] = 2; // 腐烂
                        next.emplace_back(i, j);
                    }
                }
            
            }
            q = move(next); // 关键点！！！需要单独这个next来保存当前时间轮的腐烂橘子，不然每次遍历都把腐烂橘子加入q，可能会在当前时间轮里处理，本应该在下一秒才腐烂的橘子
        }
        return fresh ? -1 : ans; // 如果有不会腐烂的返回-1，不然返回时间
    }
};
#endif // DEBUG

//#define PRETICE
#ifdef PRETICE

class Solution {
public:
    int DIRECTION[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };// 预定义四个方向

    int orangesRotting(vector<vector<int>>& grid) {

        // 需要先保存新鲜橘子个数和已经腐烂的橘子位置
        int fresh = 0;
        vector<pair<int, int>> rot;

        // 获取行列
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                else if (grid[i][j] == 2) {
                    rot.push_back({ i, j });
                }
            }
        }
        int ans = 0;// 保存腐烂时间

        //BFS
        while (fresh && !rot.empty()) {
            // 更新时间
            ans++;
            // 重置当前轮次的腐烂橘子
            vector<pair<int, int>> next;
            // 开始扩散
            for (auto& [x, y] : rot) { // 注意！！！！错误点，这里的容器引用不要写成{x, y}或者(x, y)
                for (auto& d : DIRECTION) {
                    // 更新索引
                    int i = x + d[0], j = y + d[1];

                    // 如果有新鲜橘子（注意判断索引有没有超出范围）(row和col表示数量，最大索引分别是row-1和col-1)
                    if (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1) {
                        next.push_back({i, j}); // 保存当前轮次腐烂的橘子
                        fresh--;// 更新新鲜计数
                        grid[i][j] = 2; // 更新橘子为腐烂
                    }
                }
            }
            // 这一秒腐烂的橘子更新完毕，保存结果
            rot = move(next);
        }
        // 判断是否全都腐烂了
        return fresh ? -1 : ans;


    }
};





#endif // PRETICE
