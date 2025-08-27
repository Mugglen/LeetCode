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
	// ��ʵҲ�ǻ������ڵ����У���ָofferNo41��ΪS�У�ֻȡ�������ڵ�����Ԫ�غ;��������д��
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.empty()) return {};
        // ��ʼ��˫ָ��
		int left = 0, right = array.size() - 1;
        vector<int> ans;
        while (left < right) {
            int sumTemp = array[left] + array[right];
            if (sumTemp == sum) {
                ans.push_back(array[left]);
                ans.push_back(array[right]);
				return ans; // ע�⣡�����ҵ�һ��ͷ��أ���Ȼ�ͳ�ʱ��
            }
            else if (sumTemp > sum) right--;
            else left++;
        }
        return ans;
    }
};

#endif // DEBUG1