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
    // https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/solutions/3060042/yong-zhan-si-kao-yuan-di-shi-xian-python-zw8l/?envType=study-plan-v2&envId=top-interview-150
    // ��ջ��˼ά��˼�����о�����Ҳ��˫ָ��ʵ��
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int stack_size = 2; // ��ǰջ��С��ǰ����Ԫ��Ĭ�ϱ�������Ϊ�������򣬲�����ô��ǰ����Ԫ��һ������
        for (int i = 2; i < n; i++) {
            // ��ջ���·�Ԫ�رȽϣ���ʵ������Ϊ���������ظ�Ԫ��һ����������
            // ����ȽϾ��ǱȽ��Ѵ���ĵ����ڶ���Ԫ��
            if (nums[i] != nums[stack_size - 2]) { 
                nums[stack_size] = nums[i];
                stack_size++;
            }
        }
        return min(stack_size, n);
    }
};


#endif // DEBUG1