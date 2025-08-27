#include <iostream>
#include <vector>
using namespace std;

// ��33��ļ򻯰�,33��˼·��һ��ʼ���ַ��ҵ������������������һ��,����ת������,��Сֵ��Զ�����������������һ������һ��,
// Ҳ����˵���Ҳ���������ĵ�һ��,�����{1,2,3}�������������Ҫȡģ

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2 + 1;
            // mid ��������������
            if (nums[mid] >= nums[0]) { left = mid; }
            else { right = mid - 1; }
        }
        // ע����ĿҪ�����ֵ��ȡģ��ѭ��ȡ��������ֹ����{1��2��3}����������
        int result = nums[(right + 1) % nums.size()];
        return result;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {
    vector<int> nums = { 4,5,6,7,0,1,2 };
    Solution solution;
    int result = solution.findMin(nums);
    cout << "�㷨����Ľ��Ϊ��" << result << endl;
}

#endif // DEBUG
