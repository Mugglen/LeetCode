//#define DEBUG1
#ifdef DEBUG1
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

// https://mp.weixin.qq.com/s/qJMFJteSQB6Z_E3YlTJMBA
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dist(n + 1, INF);
    queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // 向左走
        if (u > 1 && dist[u - 1] > dist[u] + 1) {
            dist[u - 1] = dist[u] + 1;
            q.push(u - 1);
        }

        // 向右走
        if (u < n && dist[u + 1] > dist[u] + 1) {
            dist[u + 1] = dist[u] + 1;
            q.push(u + 1);
        }

        // 使用传送门
        if (dist[a[u]] > dist[u]) {
            dist[a[u]] = dist[u];
            q.push(a[u]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << " ";
        cout << dist[i];
    }
    cout << endl;

    return 0;
}

#endif // DEBUG1