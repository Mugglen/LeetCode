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
    // ʹ�ô󶥶�
    vector<int> maxInWindows(vector<int>& num, int size) {
        // �쳣����
        if (size > num.size() || size == 0 || num.size() == 0) return {};
        // ��ʼ��
        int len = num.size(), count = 0;
        priority_queue<int> pq;
        vector<int> ans;

        // ����(�����ά��������ÿ�ζ��Ƕ�������size��Ԫ�أ��жϽ����ٵ����������Ƕ�̬����)
        for (int i = 0; i <= len - size; ++i) {
            // Ԫ���봰
            while (count < size) {
                pq.push(num[i + count]);
                count++;
            }
            // ���ü�������������
            count = 0;
            ans.push_back(pq.top());
            while (!pq.empty()) {
                pq.pop();
            }
        }
        return ans;
    }
};

#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2

class Solution {
public:
    // ʹ��˫�˶���
    vector<int> maxInWindows(vector<int>& num, int size) {
        vector<int> ans;
        int len = num.size();
        if (len == 0 || size == 0 || size > len) return ans;
        deque<int> dq; // �洢num���±꣨ά�����Ԫ���±꣬�������ж����Ԫ���ڲ��ڴ��ڣ�
        // ��ʼ����(�涨��ǰ���дӺ���ǰ���ε���)
        for (int i = 0; i < len; ++i) {
            
            // ���д���1���Ӻ���ǰ��С�ڵ�ǰԪ�صĶ�pop��
            while (!dq.empty() && num[dq.back()] < num[i]) {
                dq.pop_back();
            }
            // ���д���2����ǰ�����ж����Ԫ����û�г�������
            while (!dq.empty() && i - dq.front() + 1 > size) {
                dq.pop_front();
            }
            // ������ϣ�ֱ�Ӳ���(�ڶ�������Ȳ������ŪӦ��Ҳ��)
            dq.push_back(i);
            // ������ɺ�ſ�ʼѹ���
            if (i + 1 >= size) {
                ans.push_back(num[dq.front()]);
            }
        }
        return ans;
    }
};

#endif // DEBUG2