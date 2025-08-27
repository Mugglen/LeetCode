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
    // https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&&tqId=11198&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
    //������ĵ�һ�ַ���
    bool IsContinuous(vector<int>& numbers) {
        // ������
        sort(numbers.begin(), numbers.end());
        // ͳ�ƴ�С����������0��������
		int zeroCount = 0;
		int i = 0; // ��һ���Ǵ�С��������
        while (numbers[i] == 0) {
            zeroCount++;
            i++;
        }
        // ��¼����Ԫ��֮���Ϊ˳����Ҫ�����Ԫ�ظ�����Ȼ���0Ԫ�رȽ�
		int needCount = 0;
		// ע��Ҫ��i + 1�Ƚϣ�����������Χ�� i < numbers.size() - 1
        for (; i < numbers.size() - 1; i++) {
			if (numbers[i] == numbers[i + 1]) return false; // ���ظ�Ԫ�أ����ܳ�Ϊ˳��
			needCount += numbers[i + 1] - numbers[i] - 1; // ������Ҫ�����Ԫ�ظ���
        }
		if (zeroCount >= needCount) return true; // �����С�����������ڵ�����Ҫ�����Ԫ�ظ���������Գ�Ϊ˳��
        else return false; // �����ܳ�Ϊ˳��
    }
};
#endif // DEBUG1