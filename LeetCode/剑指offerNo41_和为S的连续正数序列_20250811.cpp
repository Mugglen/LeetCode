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
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/41-%E5%89%91%E6%8C%87offer.html
	// �������ڷ�����С���ƶ��Ҷ˵㣬�����ƶ���˵�
    vector<vector<int> > FindContinuousSequence(int sum) {
        // ��Ϊ�������1-100������˫ָ���ָ���Ƕ�ӦԪ��
		int left = 1, right = 2; // ����ָ���ʼλ��
        vector<vector<int>> ans;
		// ע�������ֹ������Ӧ���Ǳ�������right���ڵ���sumһ�����������һֱ������ָ��
        while (left < right) {
            // ����������͹�ʽ(a0 + an)*n/2
			int sumTemp = (left + right) * (right - left + 1) / 2; // ���㵱ǰ���ڵĺ�(ע����ǰ���ȳ��ٳ�2)
            if (sumTemp == sum) { // ��ȣ������ڷ�Χ��������������
                vector<int> ansTemp;
                for (int i = left; i <= right; i++) {
                    ansTemp.push_back(i);
                }
                ans.push_back(ansTemp); // ����ǰ���ڵĽ�����뵽�������
                left++; // ע�⣡�����������ƶ���ָ�룬����Ѱ����һ�����ܵ���������
            }
            else if (sumTemp < sum) right++; // �����ǰ���ڵĺ�С��Ŀ��ͣ��ƶ���ָ�����󴰿�
			else left++; // �����ǰ���ڵĺʹ���Ŀ��ͣ��ƶ���ָ����С����
        }
		return ans; // ���������ҵ�����������
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// �����ⷨ���������п��ܵ���������
class Solution {
public:
    // https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/41-%E5%89%91%E6%8C%87offer.html
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > result;
        for (int n = sqrt(2 * sum); n >= 2; --n) {
            if (((n & 1) == 1 && sum % n == 0) || (sum % n * 2 == n)) {
                vector<int> res;
                //j���ڼ�����k���ڱ�����ֵ
                for (int j = 0, k = sum / n - (n - 1) / 2; j < n; j++, k++)//ע�⿴k����
                    res.push_back(k);
                result.push_back(res);
            }
        }
        return result;
    }

};

#endif // DEBUG2