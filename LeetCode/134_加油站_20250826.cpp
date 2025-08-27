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
        // 找到第一个gas 大于 cost的位置，从这里出发（不太对，有多个gas 大于 cost应该不一定是从第一个出发）
        // 核心：判断gas 总和大于等于 cost 总和就会有解
        // 但不用从每个可出发的点判断，去找从第一个点出发时，中间gas量最小的点（可以为负数）就是我们的出发点（解析见链接图解）
        int ans = 0;// 结果位置
        int minFuel = 0; // 最小的油量
        int fuel = 0;
        // 在遍历过程中求和，最后fuel的值就是gas总和减cost总和
        for (int i = 0; i < gas.size(); i++) {
            fuel += gas[i] - cost[i]; // i处加油，走到i+1处
            if (fuel < minFuel) {
                minFuel = fuel;
                ans = i + 1; // 保存油量最小的位置
            }
        }
        // 判断gas 总和与cose总和关系
        return fuel < 0 ? -1 : ans;
    }
};


#endif // DEBUG1