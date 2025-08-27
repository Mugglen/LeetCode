#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// https://leetcode.cn/problems/rotate-array/solutions/2784427/tu-jie-yuan-di-zuo-fa-yi-tu-miao-dong-py-ryfv
//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    void debug(const vector<int>& nums, const string& step) {
        cout << step << ": ";
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
    }

    void rotate(vector<int>& nums, int k) {
        // 注意这个异常值处理，超出数组长度的轮转次数要取余
        k %= nums.size();

        // 打印初始数组
        debug(nums, "Initial nums");

        // 先整体反转，再反转前k位
        // 注意注意（reverse反转的是左边迭代器到右边迭代器前一个元素）
        // nums.end指向的是最后一个元素的后面

        reverse(nums.begin(), nums.end());
        debug(nums, "After reverse whole array");

        reverse(nums.begin(), nums.begin() + k);
        debug(nums, "After reverse first " + to_string(k) + " elements");

        reverse(nums.begin() + k, nums.end());
        debug(nums, "After reverse last " + to_string(nums.size() - k) + " elements");
    }

    // 如果要手写reverse的话可以双指针
    void myReverse(vector<int>& nums, int i, int j) {
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    
    }


};


int main() {
    Solution sol;
    vector<int> nums = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3;

    sol.rotate(nums, k);  // 调用 rotate 方法并打印每一步结果

    return 0;
}
#endif // DEBUG



