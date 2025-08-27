//#include <iostream>
//#include <string>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    int n;
//    string s;
//    cin >> n >> s;
//
//    long long total = 0;  // 防止int溢出（n=1e5时结果可能很大）
//
//    // 枚举所有子串
//    for (int l = 0; l < n; ++l) {
//        for (int r = l; r < n; ++r) {
//            int len = r - l + 1;
//            if (len == 1) {
//                total += 0;  // 长度为1时权值为0
//            }
//            else {
//                int sum = 0;
//                int left = l, right = r;
//                while (left < right) {
//                    sum += abs(s[left] - s[right]);
//                    left++;
//                    right--;
//                }
//                total += sum;
//            }
//        }
//    }
//
//    cout << total << endl;
//    return 0;
//}