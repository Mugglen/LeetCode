#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {

private:
    int minVal = INT_MAX;
    stack<int> st;

public:
    void push(int value) {
        // ά��ȫջ��С��ע�⵱ǰ��Ҳ��min��ָ�������ռ�
        minVal = std::min(value, minVal);
        // �ؼ���ÿ�β���ǰͬʱ����ά����ǰ��С״̬
        st.push(minVal);
        st.push(value);
    }

    void pop() {
        // �ǵ�����һ��������ֵ����ʱvalue�Ͳ���valueʱ����Сֵ
        st.pop();
        int preMin = st.top();
        st.pop();
        // ����������һ����Сֵ��Ӧ��Ҳ���Լ�鵯�����ǲ�����Сֵ���ٸ��°ɣ�
        if (!st.empty() && preMin == minVal) {
            int temp = st.top();
            st.pop();
            minVal = st.top();
            st.push(temp);
        }

    }
    int top() {
        return st.top();
    }
    int min() {
        return minVal;
    }
};

#endif // DEBUG1