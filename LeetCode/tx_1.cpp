// 找到数组中a[i] ,a[j]，i<j时a[i]>a[j]的组数

#include <iostream>
#include <vector>

using namespace std;

// 归并排序的合并阶段，用来计算逆序对
int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
    int count = 0;
    int i = left, j = mid + 1;
    vector<int> temp;

    // 合并两个已排序的部分
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            // nums[i] > nums[j]，说明从 i 到 mid 之间的元素都大于 nums[j]，构成逆序对
            temp.push_back(nums[j]);
            count += (mid - i + 1); // 逆序对数目增加
            j++;
        }
    }

    // 把剩余的元素加入到 temp
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(nums[j]);
        j++;
    }

    // 将临时数组中的元素拷贝回原数组
    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }

    return count;
}

// 归并排序函数，返回逆序对的数量
int mergeSortAndCount(vector<int>& nums, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(nums, left, mid); // 左半部分的逆序对
        count += mergeSortAndCount(nums, mid + 1, right); // 右半部分的逆序对
        count += mergeAndCount(nums, left, mid, right); // 合并两部分时计算逆序对
    }
    return count;
}


//#define DEBUG
#ifdef DEBUG

int main() {
    vector<int> nums = { 7, 5, 6, 4 };
    int result = mergeSortAndCount(nums, 0, nums.size() - 1);
    cout << "逆序对的数量: " << result << endl;
    return 0;
}

#endif // DEBUG


