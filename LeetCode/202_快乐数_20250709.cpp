#include <iostream>
#include <unordered_set>

using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://www.programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html#%E6%80%9D%E8%B7%AF
// ʱ�临�Ӷ�O(log n)
// �ռ临�Ӷ�O(log n)
class Solution {
public:
    // ȡ��ֵ����λ�ϵĵ���֮��
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10); // ÿ����Ķ��Ǹ�λ
            n /= 10;
            std::cout << "n : " << n << std::endl;
        }
        return sum;
    
    }


    bool isHappy(int n) {

        // �����Ŀ�е�����ѭ��������ͬ����ƽ���ͻ��ظ����֣��ù�ϣ������ж��������û�г��ֹ�
        // ͬʱ�ѵ����ڶ���ֵ��ÿһλ��������
        unordered_set<int> set;

        while (1) {
            int sum = getSum(n);
            
            // ��Ŀ����
            if (sum == 1)return true;

            // ���ֹ�����������ѭ����ֱ�ӷ���
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
