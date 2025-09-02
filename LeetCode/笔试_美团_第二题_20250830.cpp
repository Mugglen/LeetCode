#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <string>
#include <functional>
using namespace std;

// https://mp.weixin.qq.com/s/5StS46XtTm6r5dUJihS24g
//#define DEBUG1
#ifdef DEBUG1

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll p, q, k;
        cin >> p >> q >> k;

        // 化简分数：除以分子分母的最大公约数
        ll g = gcd(p, q);
        q /= g;   // 得到最简分母q'

        // 不断用k和q'的gcd去除q'
        while (q > 1) {
            ll gqk = gcd(q, k);
            if (gqk == 1) break;
            while (q % gqk == 0) {
                q /= gqk;
            }
        }

        if (q == 1) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    return 0;
}

#endif // DEBUG1



