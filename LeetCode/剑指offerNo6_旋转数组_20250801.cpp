#include <vector>

using namespace std;


//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param nums int����vector
     * @return int����
     */
    // ʱ�临�Ӷ�O��N��������
    // �ҵ���һ���������ĵ㣬����ά��һ��ȫ����С��������ʱ��Ƚ�
    int minNumberInRotateArray(vector<int>& nums) {
        // write code here
        if (nums.size() == 0) return 0;
        int minNum = nums[0], len = nums.size();
        for (int i = 0; i < len; i++) {
            if (nums[i] < minNum) return nums[i];
        }
        return minNum;
    }
};
#endif // DEBUG1



// ���ַ��Ż�
//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:
    
    int minNumberInRotateArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int low = 0, high = nums.size() - 1;
        // +1Ϊ�˲�������ָ����ȣ�����û�㶮��Ϊʲô��
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            // ����м�ֵС����ָ���ֵ��˵���м�ֵ�����Ҳ�������䣬
            // �����Ҳ�����������˵�����ָ����м�ֵ֮�䣬��������ָ��
            if (nums[mid] < nums[high]) high = mid;
            // ���������������ֻ��һ��һ�����жϣ��������롾1��0��1��1��1����ע����Ŀ˵���Ƿǽ��򣬲��ǵ�����ע�⿴�⣡����������
            else if (nums[mid] == nums[high]) high = high - 1;
            // �м�ֵ������ָ��ֵ��˵���м�ֵ�������������䣬��С��˵� 
            else low = mid;
        }
        // ǰ��Ҫ��֤����ָ�������պ�����ת����������Ҳ�
        // ������������������ÿ��ת�����ǵ����ģ���ʱ����ָ���������ǰ����Ԫ�أ�����ȡ��С������ֱ��ȡ��ָ��
        return min(nums[low], nums[high]);
    }
};
#endif // DEBUG2