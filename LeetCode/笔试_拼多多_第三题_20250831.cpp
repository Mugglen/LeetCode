//#define DEBUG1
#ifdef DEBUG1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long ll;

// https://mp.weixin.qq.com/s/qJMFJteSQB6Z_E3YlTJMBA
// 预处理字符串，统计连续段长度分布
void countSegments(const string& s, unordered_map<ll, ll>& cnt) {
    int n = s.size();
    int i = 0;
    while (i < n) {
        if (s[i] == 'a') {
            int j = i;
            while (j < n && s[j] == 'a') j++;
            int len = j - i;
            for (int l = 1; l <= len; l++) {
                cnt[l] += len - l + 1;
            }
            i = j;
        }
        else {
            i++;
        }
    }
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    string A, B;
    cin >> A >> B;

    unordered_map<ll, ll> cntA, cntB;
    countSegments(A, cntA);
    countSegments(B, cntB);

    ll ans = 0;
    // 枚举k的所有因子对(r, c)
    for (ll r = 1; r * r <= k; r++) {
        if (k % r != 0) continue;
        ll c = k / r;

        if (cntA.count(r) && cntB.count(c)) {
            ans += cntA[r] * cntB[c];
        }
        if (r != c) {
            if (cntA.count(c) && cntB.count(r)) {
                ans += cntA[c] * cntB[r];
            }
        }
    }

    cout << ans << endl;
    return 0;
}
#endif // DEBUG1