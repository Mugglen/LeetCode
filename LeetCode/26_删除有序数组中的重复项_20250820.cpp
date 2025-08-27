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
    // 非严格递增，考虑重复元素，重复元素要留一个
    // 要对num 修改，前k个元素是递增不重复元素
    // ！！！！！！！想的太复杂了，swap(nums[left], nums[right]);这一行还要报堆错误
    // 看DEBUG2吧，遇到重复元素后不用直接开一个while循环单独处理，步进右指针就行了
    int removeDuplicates(vector<int>& nums) {
        // 使用双指针，通过交换元素来把不重复元素换到前 k 个
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        // 双指针
        int left = 0;
        int right = 1;
        while(right < nums.size()) {
            // 第一次出现重复,左指针移动到重复元素的下一个位置，
            // 右指针找下一个不重复的元素，换到前面来
            if (nums[left] == nums[right]) {
                int tmp = nums[left];
                left++;
                while (nums[right] == tmp) {
                    right++;
                    if (right == nums.size()) break; // 找完了
                }
                swap(nums[left], nums[right]);
                // 右指针再移动一步，左指针不动，因为不知道左指针是不是也是存在重复的
                // 进入下一次比较
                right++;
            }
            else { // 不重复，左指针前进一步，交换左右指针，右指针步进，进入下一次循环
                left++;
                swap(nums[left], nums[right]);
                right++;
            }
        }
        // 循环结束，前k个已经是递增非重复元素，返回个数
        return left + 1;
    }
};


#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        int left = 0;
        int right = 1;

        while (right < nums.size()) {
            if (nums[left] == nums[right]) {
                // 找到重复元素，右指针继续寻找下一个不重复的元素
                right++;
            }
            else {
                // 找到不重复的元素，左指针前进，并复制元素
                left++;
                nums[left] = nums[right];
                right++;
            }
        }

        return left + 1;
    }
};

#endif // DEBUG2