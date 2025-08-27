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
	// û�涨�ռ临�Ӷȣ�����������vector��һ������������۳ˣ�һ�����������۳�
	// ���������������ֱ�ӳ���ÿ��Ԫ��
    vector<int> multiply(vector<int>& A) {
        // ���У�����˵�˲�������
        if (A.size() <= 1) return {};
        // �������۳�
		vector<int> left(A.size(), 1);
		left[0] = A[0];
        for (int i = 1; i < A.size(); i++) {
			left[i] = left[i - 1] * A[i];
        }
        // �������۳�
        vector<int> right(A.size(), 1);
        right[A.size() - 1] = A[A.size() - 1];
        for (int i = A.size() - 2; i >= 0; i--) {
            right[i] = right[i + 1] * A[i];
        }
		// �������
		vector<int> ans(A.size(), 1);
        for (int i = 0; i < A.size(); i++) {
            // ���⴦��
            if (i == 0) ans[i] = right[i + 1];
            else if (i == A.size() - 1) ans[i] = left[i - 1];
            else ans[i] = left[i - 1] * right[i + 1];
        }
        return ans;
    }
};

#endif // DEBUG1


