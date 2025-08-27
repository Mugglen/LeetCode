#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    int DIRECTION[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };// Ԥ�����ĸ�����

    int orangesRotting(vector<vector<int>>& grid) {

        // ��ȡ����������
        int m = grid.size(), n = grid[0].size();

        int fresh = 0; // �����������Ӽ���

        vector<pair<int, int>> q; // ����ͳ�Ƹ�������

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++; // ��������
                }
                else if(grid[i][j] == 2) {
                    q.emplace_back(i, j); // һ��ʼ�͸��õ�����
                }
            }
        }

        int ans = 0; // ������ʱ��
        while (fresh && !q.empty()) { // �����������ӣ�ͬʱ�Ӹ�������λ�ÿ�ʼ���������港������λ�õ����壬���ٱ���������
            ans++; // ����һ����
            vector<pair<int, int>> next; // ��ǰ�ִθ��õ�����
            for (auto& [x, y] : q) {
                for (auto d : DIRECTION) {
                    // ��鵱ǰ���������������ҵ�λ��
                    int i = x + d[0], j = y + d[1];
                    if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1) { // �����ڷ�Χ�ڣ���ǰ��������
                        fresh--;
                        grid[i][j] = 2; // ����
                        next.emplace_back(i, j);
                    }
                }
            
            }
            q = move(next); // �ؼ��㣡������Ҫ�������next�����浱ǰʱ���ֵĸ������ӣ���Ȼÿ�α������Ѹ������Ӽ���q�����ܻ��ڵ�ǰʱ�����ﴦ����Ӧ������һ��Ÿ��õ�����
        }
        return fresh ? -1 : ans; // ����в��ḯ�õķ���-1����Ȼ����ʱ��
    }
};
#endif // DEBUG

//#define PRETICE
#ifdef PRETICE

class Solution {
public:
    int DIRECTION[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };// Ԥ�����ĸ�����

    int orangesRotting(vector<vector<int>>& grid) {

        // ��Ҫ�ȱ����������Ӹ������Ѿ����õ�����λ��
        int fresh = 0;
        vector<pair<int, int>> rot;

        // ��ȡ����
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
        int ans = 0;// ���港��ʱ��

        //BFS
        while (fresh && !rot.empty()) {
            // ����ʱ��
            ans++;
            // ���õ�ǰ�ִεĸ�������
            vector<pair<int, int>> next;
            // ��ʼ��ɢ
            for (auto& [x, y] : rot) { // ע�⣡����������㣬������������ò�Ҫд��{x, y}����(x, y)
                for (auto& d : DIRECTION) {
                    // ��������
                    int i = x + d[0], j = y + d[1];

                    // ������������ӣ�ע���ж�������û�г�����Χ��(row��col��ʾ��������������ֱ���row-1��col-1)
                    if (i >= 0 && i < row && j >= 0 && j < col && grid[i][j] == 1) {
                        next.push_back({i, j}); // ���浱ǰ�ִθ��õ�����
                        fresh--;// �������ʼ���
                        grid[i][j] = 2; // ��������Ϊ����
                    }
                }
            }
            // ��һ�븯�õ����Ӹ�����ϣ�������
            rot = move(next);
        }
        // �ж��Ƿ�ȫ��������
        return fresh ? -1 : ans;


    }
};





#endif // PRETICE
