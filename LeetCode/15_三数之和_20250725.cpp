#include <vector>
#include <algorithm>
using namespace std;



// https://leetcode.cn/problems/3sum/solutions/1968332/shuang-zhi-zhen-xiang-bu-ming-bai-yi-ge-pno55/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // 记得先给数组排序，方便跳过重复数字
        sort(nums.begin(), nums.end());

        // 初始化结果
        vector<vector<int>> result;

		// 每个数都拿来匹配一下初始化双指针（i-2是考虑给双指针腾位置，但是，i不-2的情况在while(left < right)里也会被过滤，所以其实没差）
        for (int i = 0; i < nums.size() - 2; i++) {
            
			// 先判断当前数字是否大于0，如果大于0，直接返回结果，因为后面不可能有三数之和为0的情况了
            if (nums[i] > 0)return result;

            // 判断当前数字是不是重复的，和前一个算过的元素比，同时第一个元素不用比
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // 当前不是重复元素而且可能存在三元组
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
            
                if (nums[i] + nums[left] + nums[right] > 0)right--;
                else if (nums[i] + nums[left] + nums[right] < 0)left++;
                else {// 找到了
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 跳过重复元素
                    while (left < right && nums[right] == nums[right - 1])right--;
                    while (left < right && nums[left] == nums[left + 1])left++;
                    // 还需要收缩一次双指针，上面去重后仍指向相同的元素（注意是找到答案才移动的双指针）
                    right--;
                    left++;
                }
                //// 错误点！！！放这不行
                //right--;
                //left++;
            }
        }
        return result;
    }
};


#endif // DEBUG
