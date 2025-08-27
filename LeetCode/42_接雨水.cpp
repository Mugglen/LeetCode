
#include <vector>

using namespace std;

// https://leetcode.cn/problems/trapping-rain-water/solutions/1974340/zuo-liao-nbian-huan-bu-hui-yi-ge-shi-pin-ukwm

// ����˫ָ��
// ʱ�临�Ӷ�O(n)
// �ռ临�Ӷ�O(1)

//���Ӹ߶ȣ�
//0 1 0 2 1 0 1 3 2 1 2 1
//
//������ӣ�
//- ��ߣ�[0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3]
//- �ұߣ�[3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 1]
//
//��ˮ����
//0 0 1 0 1 2 1 0 1 2 1 0

//ÿ��λ�õĽ�ˮ�� = min(��ߵ����߶�, �ұߵ����߶�) - ��ǰ���ӵĸ߶�




class Solution {

public:
	int trap(vector<int>& height) {
		
		int ans = 0;  // �洢�ܵĽ�ˮ��
		int left = 0, right = height.size() - 1;  // ��ָ�����ָ��
		int pre_max = 0, suf_max = 0;  // ��ߺ��ұߵ����߶�(ǰ׺prefix, ��׺suffix)

		// ע�� while ѭ�����Բ��ӵȺţ�
		// ��Ϊ�ڡ�˭С�ƶ�˭���Ĺ����£�������λ��һ������ߵ����ӣ�����������޷���ˮ�ġ�
		while (left < right) {
			
			// �����������ߵ����߶�
			pre_max = max(pre_max, height[left]);
			suf_max = max(suf_max, height[right]);

			// �ж��������߶��ĸ�С��С��һ�߲��п��ܻ�ˮ������ˮ���ٿ���ǰ���Ӹ߶ȣ�
			if (pre_max < suf_max) {
				// ����������ӽӵ�ˮ��
				ans += pre_max - height[left];
				left++;
			}else{
				// �����ұ����ӽӵ�ˮ��
				ans += suf_max - height[right];
				right--;
			}
		
		}
		return ans;
	
	}
};