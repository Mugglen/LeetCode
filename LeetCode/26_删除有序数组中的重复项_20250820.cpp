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
    // ���ϸ�����������ظ�Ԫ�أ��ظ�Ԫ��Ҫ��һ��
    // Ҫ��num �޸ģ�ǰk��Ԫ���ǵ������ظ�Ԫ��
    // �����������������̫�����ˣ�swap(nums[left], nums[right]);��һ�л�Ҫ���Ѵ���
    // ��DEBUG2�ɣ������ظ�Ԫ�غ���ֱ�ӿ�һ��whileѭ����������������ָ�������
    int removeDuplicates(vector<int>& nums) {
        // ʹ��˫ָ�룬ͨ������Ԫ�����Ѳ��ظ�Ԫ�ػ���ǰ k ��
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        // ˫ָ��
        int left = 0;
        int right = 1;
        while(right < nums.size()) {
            // ��һ�γ����ظ�,��ָ���ƶ����ظ�Ԫ�ص���һ��λ�ã�
            // ��ָ������һ�����ظ���Ԫ�أ�����ǰ����
            if (nums[left] == nums[right]) {
                int tmp = nums[left];
                left++;
                while (nums[right] == tmp) {
                    right++;
                    if (right == nums.size()) break; // ������
                }
                swap(nums[left], nums[right]);
                // ��ָ�����ƶ�һ������ָ�벻������Ϊ��֪����ָ���ǲ���Ҳ�Ǵ����ظ���
                // ������һ�αȽ�
                right++;
            }
            else { // ���ظ�����ָ��ǰ��һ������������ָ�룬��ָ�벽����������һ��ѭ��
                left++;
                swap(nums[left], nums[right]);
                right++;
            }
        }
        // ѭ��������ǰk���Ѿ��ǵ������ظ�Ԫ�أ����ظ���
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
                // �ҵ��ظ�Ԫ�أ���ָ�����Ѱ����һ�����ظ���Ԫ��
                right++;
            }
            else {
                // �ҵ����ظ���Ԫ�أ���ָ��ǰ����������Ԫ��
                left++;
                nums[left] = nums[right];
                right++;
            }
        }

        return left + 1;
    }
};

#endif // DEBUG2