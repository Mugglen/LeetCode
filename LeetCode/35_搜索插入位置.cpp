#include <iostream>
#include <vector>
using namespace std;

// �����ⷨ
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)

class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            // ��С����ʼ��
            // �ֱ��������������
            // Ŀ��ֵ����������Ԫ��֮ǰ
            // Ŀ��ֵ����������ĳһ��Ԫ��
            // Ŀ��ֵ���������е�λ��
            if (nums[i] >= target) { // һ�����ִ��ڻ��ߵ���target��num[i]����ôi��������Ҫ�Ľ��
                return i;
            }
        }
        // Ŀ��ֵ����������Ԫ��֮������
        return nums.size(); // ���target�����ģ����� numsΪ�գ��򷵻�nums�ĳ���
    }
};

// �����ⷨ
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
		return right + 1;// ����ֲ�����Ҫ������㣬���ֲ����Ҳ�������-1,ע���Ƿ���whileѭ�������,���������ֱ���˳���
    }
};

//#define DEBUG
#ifdef DEBUG
int main() {
    vector<int> nums = { 1,3,5,6 };
    int target = 5;
    Solution solution;
    int result = solution.searchInsert(nums, target);
    cout << "Ŀ��ֵ" << target << "�Ĳ���λ��Ϊ" << result << endl;
    return 0;
};
#endif // DEBUG

