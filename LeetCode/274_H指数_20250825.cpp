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
    // https://leetcode.cn/problems/h-index/solutions/2502837/mei-kan-dong-ti-yi-yi-zhang-tu-miao-dong-8zps/?envType=study-plan-v2&envId=top-interview-150
    int hIndex(vector<int>& citations) {
        // ע�⵽ h ָ��һ���������n
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int c : citations) {
            // ͳ�����ô���ǡ��Ϊ k ��������
            cnt[min(c, n)]++; // ���ô��� > n���ȼ������ô���Ϊ n
        }
        int s = 0;
        for (int i = n; ; i--) { // i = 0��ʱ�� s >= iһ������
            s += cnt[i]; // s �ͱ�ʾ��ǰ����������i�������м�ƪ
            if (s >= i) { // ˵�������� i ƪ���ĵ����ô�������Ϊi
                return i;
            }
        }
    }
};

#endif // DEBUG1
