//#define DEBUG1
#ifdef DEBUG1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

// https://mp.weixin.qq.com/s/qJMFJteSQB6Z_E3YlTJMBA
int main() {
    int T;
    cin >> T;
    while (T--) {
        ll H;
        int N;
        cin >> H >> N;

        vector<pair<ll, ll>> intervals;
        for (int i = 0; i < N; i++) {
            ll x, y;
            cin >> x >> y;
            intervals.emplace_back(x, y);
        }

        // �������������
        sort(intervals.begin(), intervals.end());

        // �ϲ��ص�����
        vector<pair<ll, ll>> merged;
        ll start = intervals[0].first;
        ll end = intervals[0].second;

        for (int i = 1; i < N; i++) {
            if (intervals[i].first <= end + 1) {
                end = max(end, intervals[i].second);
            }
            else {
                merged.emplace_back(start, end);
                start = intervals[i].first;
                end = intervals[i].second;
            }
        }
        merged.emplace_back(start, end);

        // ����Ԥ����ʱ��
        ll warning_time = 0;
        for (auto& interval : merged) {
            warning_time += interval.second - interval.first + 1;
        }

        // �������ʱ��
        cout << H - warning_time << endl;
    }
    return 0;
}

#endif // DEBUG1