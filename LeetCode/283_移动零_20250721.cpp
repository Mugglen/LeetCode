#include <vector>

using namespace std;

// ����1��˫ָ�뷨
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
	// ע�⿴�����ƶ��������ĩβ
    void moveZeroes(vector<int>& nums) {

        // ��Ҫ˫ָ�룬һ��ά��0Ԫ����磬һ����������
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != 0) {
                swap(nums[right], nums[left]);
				left++;
            }
            else {
				continue; // ��ָ������0������
            }
        }

    }
};
#endif // DEBUG

// ����2����nums����ջ
//#define PRETICE
#ifdef PRETICE
class Solution {
public:
    // ע�⿴�����ƶ��������ĩβ
    void moveZeroes(vector<int>& nums) {

		int stackSize = 0; // ջ�Ĵ�С
        for (int x : nums) {
			if (x) nums[stackSize++] = x; // ��0Ԫ����ջ��ע��stackSizeҪ���ӣ�
        }
		fill(nums.begin() + stackSize, nums.end(), 0); // ���ʣ��Ԫ��Ϊ0
    }
};
#endif // PRETICE
