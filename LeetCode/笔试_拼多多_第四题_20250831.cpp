//#define DEBUG1
#ifdef DEBUG1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

const int MAXM = 1000010;

// https://mp.weixin.qq.com/s/qJMFJteSQB6Z_E3YlTJMBA
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        // 构建图，大小为m+1
        vector<vector<int>> graph(m + 1);
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                graph[a[i]].push_back(b[i]);
                graph[b[i]].push_back(a[i]);
            }
        }

        // DFS计算连通分量
        vector<bool> visited(m + 1, false);
        int components = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    dfs(neighbor);
                }
            }
            };

        for (int i = 1; i <= m; i++) {
            if (!visited[i] && !graph[i].empty()) {
                components++;
                dfs(i);
            }
        }

        cout << components << endl;
    }
    return 0;
}
#endif // DEBUG1