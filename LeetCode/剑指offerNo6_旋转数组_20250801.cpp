#include <vector>

using namespace std;


//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    // 时间复杂度O（N）的做法
    // 找到第一个不递增的点，或者维护一个全局最小，遍历的时候比较
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



// 二分法优化
//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:
    
    int minNumberInRotateArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int low = 0, high = nums.size() - 1;
        // +1为了不让左右指针相等（这里没搞懂是为什么）
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            // 如果中间值小于右指针的值，说明中间值落在右侧递增区间，
            // 所以右侧递增区间的左端点在左指针和中间值之间，所以缩右指针
            if (nums[mid] < nums[high]) high = mid;
            // 这种情况是特例，只能一个一个的判断（用例输入【1，0，1，1，1】，注意题目说的是非降序，不是递增，注意看题！！！！！）
            else if (nums[mid] == nums[high]) high = high - 1;
            // 中间值大于右指针值，说明中间值落在左侧递增区间，缩小左端点 
            else low = mid;
        }
        // 前面要保证左右指针缩到刚好是旋转点的左侧或者右侧
        // 特殊情况是整个数组就每旋转，就是递增的，这时左右指针就是数组前两个元素，所以取最小，不能直接取右指针
        return min(nums[low], nums[high]);
    }
};
#endif // DEBUG2