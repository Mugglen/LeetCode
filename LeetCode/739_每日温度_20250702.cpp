#include <stack>
#include <vector>

using namespace std;


// ͨ����һά���飬ҪѰ����һ��Ԫ�ص��ұ߻�����ߵ�һ�����Լ������С��Ԫ�ص�λ�ã���ʱ���Ǿ�Ҫ�뵽�����õ���ջ��
// ����ջ��ֻ��Ҫ���Ԫ�ص��±�i�Ϳ����ˣ������Ҫʹ�ö�Ӧ��Ԫ�أ�ֱ��T[i]�Ϳ��Ի�ȡ��
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // �����ҵ�д��
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        // ��������ջ(���Ԫ���±�)
        stack<int> st;
        // �������
        vector<int> res(temperatures.size(), 0);
        // ��ʼ��ջ��
        st.push(0);

        // �����ұ�����
        for (int i = 0; i < temperatures.size(); i++) {
        
            // ���1����ǰԪ��С��ջ��Ԫ�أ���ջ��Ԫ�ض�С��ѹ��ջ��
            if (temperatures[i] < temperatures[st.top()]) {
                // ֻ����Ԫ���±�
                st.push(i);
            }
            // ���2����ǰԪ�ص���ջ��Ԫ�أ���ջ������Ԫ�ض�С������Ҫѹ��ջ��
            else if (temperatures[i] == temperatures[st.top()]) {
                st.push(i);
            }
            // ���3����ǰԪ�ش���ջ��Ԫ�أ�����
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    
                    // ��ǰλ�õ��±��ȥջ��Ԫ�ص��±�
                    res[st.top()] = i - st.top();
                    st.pop();
                
                }
                st.push(i);
            
            }

        }
        return res;
    }
};
#endif // DEBUG
