#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        // ��ʼ��һ��������
        vector<int> res(n, 0);

        // ˫ָ��
        int left = 0;
        int right = n - 1;
        int cur = n - 1;

        while (cur != -1) {
            int sqrtL = nums[left] * nums[left];
            int sqrtR = nums[right] * nums[right];

            if (sqrtL <= sqrtR) { // ����㣡��������������֮ǰֱ�ӱȽ���nums[left]��nums[right]��Ӧ���ǱȽ�ƽ��
                res[cur] = sqrtR; // �����2 ������������������ ��ֵ��ʱ��ԭ��Ҳֻд����res[cur] = nums[right];
                cur--;
                right--;
            }
            else {
                res[cur] = sqrtL;
                cur--;
                left++;
            
            }
            
        }
        return res;

    }
};
#endif // DEBUG
