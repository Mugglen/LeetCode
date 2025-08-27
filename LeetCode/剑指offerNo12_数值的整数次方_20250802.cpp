#include <vector>
#include <bitset>
using namespace std;

//#define DEBUG1
#ifdef DEBUG1
class Solution {
public:
    double Power(double base, int exponent) {
        // ע������Ϊ������ʱ��˳����Ƿ�ĸ
        if (exponent == 0) return 1;
        if (base == 0.0) return 0.0;

        bool negative = false;
        if (exponent < 0) {
            negative = true;
            exponent *= -1;// ��ת��
        }
        double res = base;
        for (int i = 2; i <= exponent; ++i) {
            res *= base;
        }
        if (negative) return 1.0 / res;
        else
            return res;
    }
};
#endif // DEBUG1