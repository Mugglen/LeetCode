#include <vector>

using namespace std;

//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n = nums.size();

        // 初始化一个空数组
        vector<int> res(n, 0);

        // 双指针
        int left = 0;
        int right = n - 1;
        int cur = n - 1;

        while (cur != -1) {
            int sqrtL = nums[left] * nums[left];
            int sqrtR = nums[right] * nums[right];

            if (sqrtL <= sqrtR) { // 错误点！！！！！！！！之前直接比较了nums[left]和nums[right]，应该是比较平方
                res[cur] = sqrtR; // 错误点2 ！！！！！！！！！ 赋值的时候原来也只写成了res[cur] = nums[right];
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
