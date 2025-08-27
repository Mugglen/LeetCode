#include <iostream>
#include <vector>
using namespace std;
#ifdef DEBUG
long long mergeAndCount(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    long long invCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

long long mergeSortAndCount(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

long long countInversions(vector<int>& arr) {
    vector<int> temp(arr.size());
    return mergeSortAndCount(arr, temp, 0, arr.size() - 1);
}

vector<int> getSpiralOrder(const vector<vector<int>>& matrix, int n) {
    vector<int> spiral;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        // 从左到右遍历最上层
        for (int i = left; i <= right; ++i) {
            spiral.push_back(matrix[top][i]);
        }
        top++;

        // 从上到下遍历最右列
        for (int i = top; i <= bottom; ++i) {
            spiral.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            // 从右到左遍历最下层
            for (int i = right; i >= left; --i) {
                spiral.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            // 从下到上遍历最左列
            for (int i = bottom; i >= top; --i) {
                spiral.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return spiral;
}


int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> spiral = getSpiralOrder(matrix, n);

    // 打印螺旋顺序
    /*for (int i = 0; i < spiral.size(); ++i) {
        if (i != 0) cout << " ";
        cout << spiral[i];
    }
    cout << endl;*/

    long long minSwaps = countInversions(spiral);
    cout << minSwaps << endl;

    return 0;
}
#endif // DEBUG

