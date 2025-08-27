#include <vector>
#include <algorithm>

using namespace std;

// ����
// ʱ�临�Ӷ� O(NlogN) �� ���� N Ϊ����Ԫ��������
// �ռ临�Ӷȣ� ȡ�������������㷨�ľ�����ơ�
class Solution_sort {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

//https://leetcode.cn/problems/kth-largest-element-in-an-array/solutions/2361969/215-shu-zu-zhong-de-di-k-ge-zui-da-yuan-d786p
// ����2������ѡ��(�ڱ����ֺ͵ݹ�)
//ʱ�临�Ӷȣ�O(N)
//�ռ临�Ӷȣ�O(logN)

class Solution {

public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }

private:
    int quickSelect(vector<int>& nums, int k) {
        //���ѡ���׼��
        int pivot = nums[rand() % nums.size()];

        // �����ڡ�С�ڡ����� pivot��Ԫ�ػ�����big, small, equal ��
        vector<int> big, equal, small;

        for (int num : nums) {
            if (num > pivot) {
                big.push_back(num);
            }
            else if (num < pivot) {
                small.push_back(num);
            }
            else {
                equal.push_back(num);
            }

        }

        // ��k��Ԫ����big�У��ݹ黮��
        if (k <= big.size()) {
            return quickSelect(big, k);
        }

        // ��k��Ԫ����small�У��ݹ黮��
        if (nums.size() - small.size() < k) {
            return quickSelect(small, k - nums.size() + small.size());
        }
        return pivot;
    
    }

};