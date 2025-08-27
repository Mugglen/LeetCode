#include<vector>
#include<functional>

using namespace std;


// https://leetcode.cn/problems/number-of-islands/solutions/2965773/ba-fang-wen-guo-de-ge-zi-cha-shang-qi-zi-9gs0

// ע��DFS����Ҫ�㣬�����ظ������߹��ĸ���

// ʱ�临�Ӷ�O(mn)
// �ռ临�Ӷ�O(mn)

// �����ϲ���
// C++20д����C++11���lambda�����Լ������Լ�������û��this auto && dfs��������ʹ��lambda�ݹ�������ܸ���
//class SolutionCpp20 {
//public:
//    int numIslands(vector<vector<char>>& grid) {
//        int m = grid.size(), n = grid[0].size();
//        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
//            // ���磬���߲��� '1'���Ͳ������µݹ�
//            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
//                return;
//            }
//            grid[i][j] = '2'; // ���죡�������غ������޵ݹ�
//            dfs(i, j - 1); // ������
//            dfs(i, j + 1); // ������
//            dfs(i - 1, j); // ������
//            dfs(i + 1, j); // ������
//            };
//
//        int ans = 0;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if (grid[i][j] == '1') { // �ҵ���һ���µĵ�
//                    dfs(i, j); // ��������������ӣ���������������� '1' һ�����µĵ�
//                    ans++;
//                }
//            }
//        }
//        return ans;
//    }
//};


// C++11д�����ð�װ������lambdaʵ�ֵݹ飩

class Solution {

public:
    int numIslands(vector<vector<char>>& grid) {
        
        // �쳣ֵ����
        if (grid.empty() || grid[0].empty()) return 0;

        // ����߽�
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        // ���� std::function
        function<void(int, int)> dfs;

        //�ݹ�lambda(ע���Ǹ�ֵҪ�ӷֺ�)
        dfs = [&](int i, int j) {
            // �߽紦��(ע��m��n�ֱ����������������������Ǵ�0��ʼ������i == m��ʱ���Ѿ�����������)
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
                return;
            }
            grid[i][j] = '2'; //���죬��ɲ��ǡ�1����ֵ����

            dfs(i, j - 1);// ��
            dfs(i, j + 1);// ��
            dfs(i - 1, j);// ��
            dfs(i + 1, j);// ��

         };
        
        // ��������
        for (int i = 0; i < m; ++i) {
            for (int j = 0; i < n; ++j) {
                // ײ������
                if (grid[i][j] == '1') {
                    dfs(i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }
};



// ��Ա����д������Ҫ�ֶ������������Ĵ���
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