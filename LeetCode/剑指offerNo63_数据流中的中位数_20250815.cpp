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

// ��Ҫ����ȡ���м�ֵ�����ڶԶ����㷨�ĵ���Ӧ��
// ���ñ���������
class Solution {
public:
    vector<int> nums;

    void Insert(int num) {
        nums.push_back(num);
    }

    double GetMedian() {
		sort(nums.begin(), nums.end());
        int len = nums.size();
        // ż��
        if (len % 2 == 0) 
			// ע��������2.0 ,�������ܷ���double����
            return (nums[len / 2] + nums[-1 + len / 2]) / 2.0;
        else// ����
			return nums[len / 2];
    }

};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

// ʹ����������ά������������λ��
class Solution {

private:
	int count = 0; // ��ż����
	priority_queue<int, vector<int>, less<int>> big_heap; // �󶥶ѣ����ڵ����
    priority_queue<int, vector<int>, greater<int>> small_heap; // С���ѣ����ڵ���С��

public:
    // ע�⵱ǰ��Լ������ͬ��Լ������ʵ�ֲ�ͬ
    // ������λ������ȡ���Ͱ���һ����
    // �����ż������λ��Ϊ mid = (leftMax + rightMin)/2
    // �������������λ��Ϊ mid = leftMax
    // ����Ӧ�������Ȳ���������ѣ���֤��������ʱ�����ѱ�С����Ԫ�ض�1
    // ����������Ԫ�����ܳ���1������������ж�̬�����Ĺ���

    void Insert(int num) {
        // ����
		count++;
        // ��ǰ�ǵ�������Ԫ��
        if (count % 2 == 1) {
            // �ն����Բ������
            if (big_heap.empty()) big_heap.push(num);
            // �ǿ���Ҫ���Ƕ�ƽ�⣬ֱ�Ӳ�����࣬���ȽϵĻ����ܵ��� leftMax > rightMin
            else {
                // ��rightMin�ȱ�һ��
                int rightMin = small_heap.top();
                if (num <= rightMin) big_heap.push(num); // ��ȫ�ģ�ֱ�Ӳ�����༴��
                else {// ��rightMin���ˣ�Ҫ����һ�£���rightMin�ó����������
                    // ע�⣬����˵�ɣ�������Ҳ���ԣ�������,�п��ܱ�rightMin��ܶ࣬����small_heap���п��ܲ��ǵ����ڶ�С�ģ�
                    // ����ֱ�Ӳ����pop������С�����Զ�ѡ����С��
                    small_heap.push(num);
                    small_heap.pop();
                    big_heap.push(rightMin);
                }
                
            }
        }
        // ��ǰ�ǵ�ż����Ԫ�أ��Ѿ���֤��������ж����ˣ�Ҫ�����Ҳ���ܲ���
        // ��ͬ�����Բ�����ܵ���rightMin < leftMax������Ҫ�ж�һ�£�
        // ����small_heap�ղ���Ӧ�ö���һ���ж��߼�
        else {
            int leftMax = big_heap.top();
            if (num >= leftMax) small_heap.push(num); // �Ϸ������Բ����Ҳ�
            else { // ��leftMaxС�ˣ���leftMax�����Ҳ�
                big_heap.push(num);
                big_heap.pop();
                small_heap.push(leftMax);
            }
        }

    }

    double GetMedian() {
        // ��������
        if (count % 2 == 1) {
            return big_heap.top();
        }
        else {
            return double((small_heap.top() + big_heap.top()) / 2.0);
        }

    }
};

#endif // DEBUG2