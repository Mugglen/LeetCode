#include <vector>
#include <algorithm>
#include <iostream>

// ˫ָ�뷨
// ��left��right�Ĵ����е���2�ַ�������������������������>0����<0�Ͷ�left��right����Ӧ�Ĵ���
// ����������ƶ�left ��right�أ� ���nums[i] + nums[left] + nums[right] > 0 
// ��˵�� ��ʱ����֮�ʹ��ˣ���Ϊ������������ˣ�����right�±��Ӧ�������ƶ�����������������֮��СһЩ��



class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        // �ҳ�a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // ����֮�������һ��Ԫ���Ѿ������㣬��ô���������϶������ܴճ���Ԫ�飬ֱ�ӷ��ؽ���Ϳ�����
            if (nums[i] > 0) {
                return result;
            }
            // ����ȥ��a����������©��-1,-1,2 �������
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */  
            // ��ȷȥ��a����(Ҫ�ͺ�һ��Ԫ�ر���ȥ��)
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                // ȥ�ظ��߼�����������0��0��0 �����������ֱ�ӵ��� right<=left �ˣ��Ӷ�©���� 0,0,0 ������Ԫ��
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                    // ȥ���߼�Ӧ�÷����ҵ�һ����Ԫ��֮�󣬶�b �� cȥ��
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;

                    // �ҵ���ʱ��˫ָ��ͬʱ����(����м�ʣ�µĽ���ﻹ��û�б�Ĵ�)
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {

    Solution solution;
    std::vector<int> nums = { -1,0,1,2,-1,-4 };
    std::vector<std::vector<int>> result = solution.threeSum(nums);
    for (std::vector<int> vector : result) {
        std::cout << "(";
        for (int num : vector) {
            std::cout << num << ",";
        }
        std::cout << ")" << std::endl;
    
    }
}


#endif // DEBUG
