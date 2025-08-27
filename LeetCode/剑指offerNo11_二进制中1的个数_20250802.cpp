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
    // ��һ��������ȥ1���ٺ�ԭ�����������㣬��Ѹ��������ұ�һ��1
    //���0.��ôһ�������Ķ������ж��ٸ�1���Ϳ��Խ��ж��ٴ������Ĳ�����
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