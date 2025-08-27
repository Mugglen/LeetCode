#include <vector>
using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {
public:

	// ������д����������С������ nums[i] >= target �� i
    int lower_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; 
        while (left <= right) { // ���䲻Ϊ��
            // ������ֵ���ǵô��������
			int mid = left + (right - left) / 2; // ��ֹ���
            if(nums[mid] >= target)right = mid - 1; // �ұ߽�����(�ڼ�⵽target����Ȼ�ƶ�)
			else left = mid + 1; // ��߽��������ұ߽����ջ���������һ��target�����һ������left��right���ʱ��left + 1��ָ���˵�һ��target����ʱ����left��
        }
		return left; // ������߽�
    }

    int higher_bound(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) { // ���䲻Ϊ��
            // ������ֵ���ǵô��������
            int mid = left + (right - left) / 2; // ��ֹ���
            if (nums[mid] <= target) left = mid + 1; // ��߽�����(�ڼ�⵽target����Ȼ�ƶ�)
            else right = mid - 1; // �ұ߽���������߽����ջ����������һ��target���ұ�һ������left��right���ʱ��right - 1��ָ�������һ��target����ʱ����right��
        }
        return right; // �����ұ߽�
    }

    vector<int> searchRange(vector<int>& nums, int target) {
		int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target) {
            return { -1, -1 };
        }
        // ���start���ڣ���ôend һ������
		//int end = lower_bound(nums, target + 1) - 1; // �ҵ���һ������target��Ԫ�ص��±꣬��һ�������һ������target��Ԫ��
		
        // ֱ�����Ͻ磬�о�����ʹ���½纯�����Ͻ羫��һ��
        int end = higher_bound(nums, target);
        return { start, end };
    }
};
#endif