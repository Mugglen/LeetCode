#include <iostream>
#include <vector>
using namespace std;



//#define DEBUG
#ifdef DEBUG

int maxArea(vector<int>& height) {
    int i = 0, j = height.size() - 1, res = 0;
    while (i < j) {
        if (height[i] < height[j]) {
            res = max(res, height[i] * (j - i));
            i++;
        }
        else {
            res = max(res, height[j] * (j - i));
            j--;
        }

    }
    return res;
}

int main() {
    int n = 0;
    if (!(cin >> n)) return 0;
    vector<int> height(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        // cout <<  height[i] << endl;

    }
    cout << maxArea(height);
    return  0;
}



// 64 Î»Êä³öÇëÓÃ printf("%lld")
#endif // DEBUG

