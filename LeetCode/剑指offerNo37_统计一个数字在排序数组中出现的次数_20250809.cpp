#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {
public:
    // ע���Ƿǽ������飬������������������ͬ��������������
    // ʱ�临�Ӷ�Ҫ��O(logn)
    int GetNumberOfK(vector<int>& nums, int k) {
        // ����һ��STL���д��
        auto pos = equal_range(nums.begin(), nums.end(), k);
		return pos.second - pos.first; // ���ص��ǵ�����������Ҫ���
    }
};


#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// �������ַ�
class Solution {
public:
    // ע���Ƿǽ������飬������������������ͬ��������������
    // ʱ�临�Ӷ�Ҫ��O(logn)
    int GetNumberOfK(vector<int>& nums, int k) {
        // �쳣
        if (nums.empty()) return 0;
		// ���ַ�
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
			int mid = left + (right - left) / 2; // ��ֹ���
            if (nums[mid] > k) right = mid - 1; // ����
            else if (nums[mid] < k) left = mid + 1; // С��
            else { // �䵽k���������ˣ����м�����������
                int count = 1;
                // �������
                int index = mid - 1;
                while (index >= 0 && nums[index] == k) { // ����index >= 0 ��ֹԽ��
                    count++;
                    index--;
                }
                // ���ұ���
                index = mid + 1; // ע��Index��Ҫ�ظ�����
                while (index <= nums.size() - 1 && nums[index] == k) {
                    count++;
                    index++;
                }
                return count;
            }
        }
        return 0; // û�ҵ�
    }
};


#endif // DEBUG2