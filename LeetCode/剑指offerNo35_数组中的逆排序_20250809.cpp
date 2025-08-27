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
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/35-%E5%89%91%E6%8C%87offer.html
    int InversePairs(vector<int>& nums) {
        // ʱ�临�Ӷ�Ҫ��O(n),���ܱ�����,����д������
        const int kmod = 1000000007;
        int ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    ret += 1;
                    ret %= kmod; // �п������ʱ��,��ÿ�ζ�modһ��
                }
            }
        }
        return ret;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2
class Solution {
public:
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/35-%E5%89%91%E6%8C%87offer.html
    // �����ù鲢��������WXG������˺��
    int InversePairs(vector<int>& nums) {
        // ����
        if (nums.size() == 0) return 0;
		vector<int> copy(nums);// �������飬ÿ�εݹ������
        return recursion(nums, copy, 0, nums.size() - 1);
    }

    int recursion(vector<int>& data, vector<int>& copy, int begin, int end) {
		if (begin == end) return 0; // ֻ��һ��Ԫ��,û�������
		int mid = begin + (end - begin) / 2; // �м�λ��
		// ���Σ��ֱ������Ҳ��ֵ����������
        // Ϊʲô����Ҫ����data��copy����Ϊÿ�εݹ��data������ģ�copy�������
		// ͬʱ�������Ա���ÿ�ζ�Ҫ��ʽ��������
        int left = recursion(copy, data, begin, mid); 
		int right = recursion(copy, data, mid + 1, end);

        // �ٱȽ���������֮��������
		int end1 = mid; // ��ߵ�ĩβ
		int end2 = end; // �ұߵ�ĩβ
        int index_copy = end; // �ȽϽ�����븨�������β��
        long res = 0;

        // �鲢�����൱��������������ϲ���һ���������β�˿�ʼ��Ϊ�˼�����
        while (begin <= end1 && mid + 1 <= end2) {
            // �������룬β�˴�����δ��븨������β��
            if (data[end1] > data[end2]) {
                copy[index_copy--] = data[end1--];
				res += end2 - mid; // �ұߵ�Ԫ�ر���ߵ�Ԫ��С��˵���ұߵ�����Ԫ�ض�����ߵ����Ԫ��С
				res %= 1000000007; // ��ֹ���
            }
            else {
				copy[index_copy--] = data[end2--];
            }
        }
		while (begin <= end1) copy[index_copy--] = data[end1--]; // ��ߵ�Ԫ��ȫ�����븨������
		while (mid + 1 <= end2) copy[index_copy--] = data[end2--]; // �ұߵ�Ԫ��ȫ�����븨������
		return (left + right + res) % 1000000007; // ���ؽ��
    }

};

#endif // DEBUG2