#include <vector>
#include <bitset>
using namespace std;

//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    
    int NumberOf1(int n) {
        
        return bitset<32>(n).count();
    }
};
#endif // DEBUG1



//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    // 把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1
    //变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
    int NumberOf1(int n) {

        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};
#endif // DEBUG1