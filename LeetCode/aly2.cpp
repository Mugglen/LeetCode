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
//    long long total = 0;  // ��ֹint�����n=1e5ʱ������ܴܺ�
//
//    // ö�������Ӵ�
//    for (int l = 0; l < n; ++l) {
//        for (int r = l; r < n; ++r) {
//            int len = r - l + 1;
//            if (len == 1) {
//                total += 0;  // ����Ϊ1ʱȨֵΪ0
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