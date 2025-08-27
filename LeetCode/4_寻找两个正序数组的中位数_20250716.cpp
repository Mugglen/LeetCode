#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/median-of-two-sorted-arrays/solutions/2950686/tu-jie-xun-xu-jian-jin-cong-shuang-zhi-z-p2gd/?envType=study-plan-v2&envId=top-100-likedv
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
			swap(nums1, nums2); // ��֤ nums1 �ǽ�С������,������֤�����i ���Դ�0 ��ʼö��
        }

		int m = nums1.size(), n = nums2.size();
        nums1.insert(nums1.begin(), INT_MIN); // ����߲���
        nums2.insert(nums2.begin(), INT_MIN);
		nums1.push_back(INT_MAX); // ���ұ߲���
		nums2.push_back(INT_MAX);

        // ö�� nums1 �� i �����ڵ�һ��
        // nums2 �� j = (m + n + 1) / 2 - i �����ڵ�һ��
        int i = 0, j = (m + n + 1) / 2; // ע������� j ������ȡ����
        while (true) {
            if (nums1[i] <= nums2[j + 1] && nums1[i + 1] > nums2[j]) { // д >= Ҳ����
				int max1 = max(nums1[i], nums2[j]); // ��һ������ֵ
				int min2 = min(nums1[i + 1], nums2[j + 1]); // �ڶ������Сֵ
				return (m + n) % 2 ? max1 : (max1 + min2) / 2.0; // ���������������ֵ��ż����������ƽ��ֵ
            }
            i++;
            j--;
        
        }
    }
};
#endif // DEBUG
