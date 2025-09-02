#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// https://mp.weixin.qq.com/s/5StS46XtTm6r5dUJihS24g
//#define DEBUG1
#ifdef DEBUG1
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 200005;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b % MOD;
}

int n, q;
vector<int> tree[MAXN];
int w[MAXN];
char color[MAXN];
int parent[MAXN];

void dfs(int u, int p) {
    parent[u] = p;
    for (int v : tree[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

ll query(int x) {
    vector<int> nodes;
    int cur = x;
    while (cur != 0) {
        if (color[cur] == 'B') {
            nodes.push_back(w[cur]);
        }
        cur = parent[cur];
    }
    if (nodes.empty()) return 1;
    ll res = nodes[0];
    for (int i = 1; i < nodes.size(); i++) {
        res = lcm(res, nodes[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        color[i + 1] = s[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);

    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            // ·­×ªÑÕÉ«
            color[x] = (color[x] == 'B') ? 'W' : 'B';
        }
        else {
            // ²éÑ¯
            cout << query(x) << '\n';
        }
    }

    return 0;
}
#endif // DEBUG1