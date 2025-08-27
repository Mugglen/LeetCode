#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1
//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
// ʹ�ø���ջ�����Լ���֤��˼·һ����������ջ˳����븨��ջ������������ջ˳���ջ����Ԫ�ص�ʱ�������Ԫ�ص���
// ����ģ��һ����ջ��ջ��������ܲ��ܶ�Ӧ��
class Solution {
public:
    // ѹ��ջ���������־������
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // ���ж����г��ȵȲ��ȣ�������Ѿ�˵���˳�������ˣ�Ҳ���ܲ���ȫ��Ԫ�س�ջ��ע�⿴����У�
        if (pushV.size() != popV.size()) return false;
        int n = pushV.size();
        // ����ջ
        stack<int> st;
        // ��ջ�±�
        int in = 0;
        // ��ʼģ�����ջ���Գ�ջ�±�ö��
        for (int out = 0; out < n; out++) {
            // ��ջ����ջΪ�ջ���ջ�������ڵ�ǰ��ջԪ��
            while (in < n && (st.empty() || st.top() != popV[out])) {
                st.push(pushV[in]);
                in++;
            }
            // ��������ջ�������1��ջ�������ǵ�ǰ��ջԪ�أ�����������
            if (st.top() == popV[out]) {
                st.pop();
            }
            else { // in == n�ˣ���ջԪ���Ѿ�ѹ���ˣ����ǵ�ǰ��ջԪ�ز�����ջ��Ԫ�أ�˵����ջ˳���Ǵ��
                return false;
            }
        }
        // ȫ����ջ��˳����ȷ
        return true;
    }
};

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// ����ջ����ϰ
class Solution {
public:
    // ѹ��ջ���������־������
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // ��ͬ���У��������
        // ��Ҫά����ջ�����ͳ�ջ�������Ӹ���ռ
        stack<int> st;
        int in = 0;
        // �Գ�ջԪ������ö��
        for (int out = 0; out < popV.size(); out++) {
            // ��ջ��Ԫ��ûȡ�� && ��ջΪ�� || ջ��Ԫ�ز���ջ
            while (in < pushV.size() && (st.empty() || st.top() != popV[out])) {
                st.push(pushV[in]);
                in++;
            }
            // ��Ҫ��ջ
            if (st.top() == popV[out]) {
                st.pop();
                // out�����Ӹ��ⲿforѭ������
            }
            else {// ȫ��ѹջ��ϣ�����ǰջ��Ԫ�غͳ�ջԪ�ز�ƥ��
                return false;
            }
        }
        return true;
    }
};

#endif // DEBUG2