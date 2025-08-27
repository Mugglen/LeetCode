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
        // ע������쳣ֵ�����������鳤�ȵ���ת����Ҫȡ��
        k %= nums.size();

        // ��ӡ��ʼ����
        debug(nums, "Initial nums");

        // �����巴ת���ٷ�תǰkλ
        // ע��ע�⣨reverse��ת������ߵ��������ұߵ�����ǰһ��Ԫ�أ�
        // nums.endָ��������һ��Ԫ�صĺ���

        reverse(nums.begin(), nums.end());
        debug(nums, "After reverse whole array");

        reverse(nums.begin(), nums.begin() + k);
        debug(nums, "After reverse first " + to_string(k) + " elements");

        reverse(nums.begin() + k, nums.end());
        debug(nums, "After reverse last " + to_string(nums.size() - k) + " elements");
    }

    // ���Ҫ��дreverse�Ļ�����˫ָ��
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

    sol.rotate(nums, k);  // ���� rotate ��������ӡÿһ�����

    return 0;
}
#endif // DEBUG



