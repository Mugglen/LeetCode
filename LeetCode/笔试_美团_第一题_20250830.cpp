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
using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << n << endl;
        return 0;
    }
    ll count = 0;
    while (count < k) {
        if (n == 1) {
            break;
        }
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n = n * 3 + 1;
        }
        count++;
    }
    if (count == k) {
        cout << n << endl;
    }
    else {
        ll rem = k - count;
        if (rem % 3 == 0) {
            cout << 1 << endl;
        }
        else if (rem % 3 == 1) {
            cout << 4 << endl;
        }
        else {
            cout << 2 << endl;
        }
    }
    return 0;
}

#endif // DEBUG1



