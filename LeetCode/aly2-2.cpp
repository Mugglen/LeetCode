//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    int count = 0;
//
//    // 枚举所有长度≥2的子数组
//    for (int l = 0; l < n; ++l) {
//        unordered_map<int, int> freq;  // 记录数字出现次数
//        int odd = 0;                   // 当前奇数次数字的个数
//
//        for (int r = l; r < n; ++r) {
//            int num = a[r];
//            freq[num]++;
//            if (freq[num] % 2 == 1) {
//                odd++;  // 奇数次数字+1
//            }
//            else {
//                odd--;  // 奇数次数字-1（变为偶数次）
//            }
//
//            // 子数组长度≥2且满足伪回文条件
//            if (r - l + 1 >= 2 && odd <= 1) {
//                count++;
//            }
//        }
//    }
//
//    cout << count << endl;
//    return 0;
//}

//#include <iostream>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    int count = 0;
//    const int kMaxNum = 9;  // 题目中数字范围1-9
//
//    // 枚举所有子数组
//    for (int l = 0; l < n; ++l) {
//        int mask = 0;  // 位掩码，第i位表示数字i+1的奇偶性
//        for (int r = l; r < n; ++r) {
//            int num = a[r] - 1;  // 转换为0-based
//            mask ^= (1 << num);  // 翻转对应位的奇偶性
//
//            // 检查伪回文条件：最多1位是1
//            if (r - l + 1 >= 2 && (mask == 0 || (mask & (mask - 1)) == 0)) {
//                count++;
//            }
//        }
//    }
//
//    cout << count << endl;
//    return 0;
//}

//#include <cstdint>
//#include <iostream>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    unordered_map<int, int> prefix_counts;
//    prefix_counts[0] = 1;
//    int prefix_xor = 0;
//    long long count = 0;
//
//    for (int num : a) {
//        prefix_xor ^= (1 << num);
//        count += prefix_counts[prefix_xor];
//        for (int i = 0; i < 20; ++i) { // Assuming numbers are up to 20 bits
//            int temp_xor = prefix_xor ^ (1 << i);
//            count += prefix_counts[temp_xor];
//        }
//        prefix_counts[prefix_xor]++;
//    }
//
//    cout << count << endl;
//    return 0;
//}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//#define DEBUG
#ifdef DEBUG


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int count = 0;
    unordered_map<int, int> xor_count;
    xor_count[0] = 1;
    int prefix_xor = 0;

    for (int num : a) {
        prefix_xor ^= num;
        count += xor_count[prefix_xor];
        for (int i = 0; i < 20; ++i) {
            int mask = 1 << i;
            count += xor_count[prefix_xor ^ mask];
        }
        xor_count[prefix_xor]++;
    }

    cout << count << endl;
    return 0;
}

#endif // DEBUG


