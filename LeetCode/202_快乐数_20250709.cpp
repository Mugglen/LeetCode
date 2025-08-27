#include <iostream>
#include <unordered_set>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://www.programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html#%E6%80%9D%E8%B7%AF
// 时间复杂度O(log n)
// 空间复杂度O(log n)
class Solution {
public:
    // 取数值各个位上的单数之和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10); // 每次算的都是个位
            n /= 10;
            std::cout << "n : " << n << std::endl;
        }
        return sum;
    
    }


    bool isHappy(int n) {

        // 理解题目中的无限循环，就是同样的平方和会重复出现，用哈希表快速判断这个数有没有出现过
        // 同时难点在于对数值的每一位单独操作
        unordered_set<int> set;

        while (1) {
            int sum = getSum(n);
            
            // 题目条件
            if (sum == 1)return true;

            // 出现过，进入无限循环，直接返回
            if (set.find(sum) != set.end()) {
                return false;
            }
            else {
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main() {

    Solution solution;
    std::cout << solution.getSum(111) << std::endl;;

    return 0;
}


#endif // DEBUG
