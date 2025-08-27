#include <vector>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG
#ifdef DEBUG

class Solution {

private:
    int DIRS[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (board[i][j] != word[k]) { // 匹配失败
                return false;
            }
            if (k + 1 == word.length()) { // 匹配成功
                return true;
            }
            board[i][j] = 0; // 标记访问过
            for (auto& [dx, dy] : DIRS) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < m && 0 <= y && y < n && dfs(x, y, k + 1)) {
                    return true;
                }
            }
			board[i][j] = word[k]; // 恢复现场(因为遍历过的格子也有可能作为其他组合中的成员)
            return false;
            };
        // 每个格子都可以作为起点
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) {
                    return true; // 搜到了
                }
            }
        }
		return false; // 没有搜到
    }
};

#endif // DEBUG


//#define PRETICE
#ifdef PRETICE

class Solution {

private:
    int DIRS[4][2] = { {0, 1}, { 0, -1 }, {1, 0}, {-1, 0} }; // 上， 下， 右， 左

public:
    bool exist(vector<vector<char>>& board, string word) {
        
		// 先获取行列数
        int row = board.size();
        int col = board[0].size();

        // 定义dfs函数（要输入当前搜索起点， 搜索目标， 通过捕获传入搜索边界）
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) ->bool {

            // 搜索终点(注意错误点1！！！！！！现在是一步一步搜索，但要找到最后的那个字符才return true)
            //if (board[i][j] == word[k])return true;
            if (board[i][j] != word[k])return false; // 中间字符不匹配，直接返回false
            // 使用当前目标字符位置k来判断是否已经匹配到最后一个字符
            if (k + 1 == word.length()) return true; // 匹配成功

            // 当前字符匹配上，但是不是最后一个字符，继续搜索
            board[i][j] = 0; // 标记访问过
            for (auto& [dx, dy] : DIRS) { // 遍历四个方向
				int x = i + dx, y = j + dy; // 计算下一个位置
                if (0 <= x && x < row && 0 <= y && y < col && dfs(x, y, k + 1)) {
                    return true;
                }
            }
			board[i][j] = word[k]; // 恢复现场(因为遍历过的格子也有可能作为其他组合中的成员)
			return false; // 没有找到匹配的字符
            };
        // 每个格子都可以作起点
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(i, j, 0)) { // 从每个起点都要搜索加判断一下
                    return true;
                }
            }
        }
		return false; // 没有找到匹配的字符
    }
};

#endif // PRETICE