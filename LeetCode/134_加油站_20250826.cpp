#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1


class Solution {
public:
    // https://leetcode.cn/problems/gas-station/solutions/2933132/yong-zhe-xian-tu-zhi-guan-li-jie-pythonj-qccr/?envType=study-plan-v2&envId=top-interview-150
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (gas.size() == 0) return -1;
        // �ҵ���һ��gas ���� cost��λ�ã��������������̫�ԣ��ж��gas ���� costӦ�ò�һ���Ǵӵ�һ��������
        // ���ģ��ж�gas �ܺʹ��ڵ��� cost �ܺ;ͻ��н�
        // �����ô�ÿ���ɳ����ĵ��жϣ�ȥ�Ҵӵ�һ�������ʱ���м�gas����С�ĵ㣨����Ϊ�������������ǵĳ����㣨����������ͼ�⣩
        int ans = 0;// ���λ��
        int minFuel = 0; // ��С������
        int fuel = 0;
        // �ڱ�����������ͣ����fuel��ֵ����gas�ܺͼ�cost�ܺ�
        for (int i = 0; i < gas.size(); i++) {
            fuel += gas[i] - cost[i]; // i�����ͣ��ߵ�i+1��
            if (fuel < minFuel) {
                minFuel = fuel;
                ans = i + 1; // ����������С��λ��
            }
        }
        // �ж�gas �ܺ���cose�ܺ͹�ϵ
        return fuel < 0 ? -1 : ans;
    }
};


#endif // DEBUG1