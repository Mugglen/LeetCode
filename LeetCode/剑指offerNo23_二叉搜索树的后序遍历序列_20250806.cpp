#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

// ע�Ȿ���hot100���98��֤������������ͬ���������֤�ǲ��Ǻ������
// ������������ָ���׽ڵ�����������е�ȫ���ڵ㣬����С���������е�ȫ���ڵ����
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        // ����
        if (sequence.empty()) return false; // ��
        if (sequence.size() == 1) return true; // ֻ��һ���ڵ�
        // ��Ϊ�ǶԱ��������н����ж϶�����ȥ����������У����Եݹ鲻�Ǻ����
        return verify(sequence, 0, sequence.size() - 1);
    }

    // �жϵ�ǰ��Χlow��high�ڵ������ǲ��Ƕ����������ĺ������
    bool verify(vector<int>& sequence, int low, int high) {
        // �ݹ�߽磬��Ҷ�ӽڵ�
        if (low >= high) return true;
        int start = low;
        // ��Ϊ������������������ȫ��С�ڸ���������ȫ�����ڸ���
        // �ҵ���һ�����ڸ���Ԫ�أ���ô����֮ǰ������������֮����������
        while (start < high && sequence[start] < sequence[high]) ++start;
        // ��ǰsuquence[start]��ʾ��������������ĵ�һ���ڵ㣬ѭ���ж������������ǲ��Ƕ����ڸ��ڵ�sequence[high
        for (int i = start; i < high; ++i) {
            if (sequence[i] <= sequence[high]) return false; // ����������ȫ�����ڸ�������Ϊ��
        }
        // �����⣬�����������ǲ��Ƕ����������ĺ������, �����������ǲ��Ƕ����������ĺ������
        return verify(sequence, low, start - 1) && verify(sequence, start, high - 1);
    }
};


#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

// ��ϰ
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        // ����
        if (sequence.empty()) return false;
        if (sequence.size() == 1) return true; // ���ڵ��Ƕ���������
        return verify(sequence, 0, sequence.size() - 1);// �����ݹ�
    }

    // �жϵ�ǰ��Χlow��high�ڵ������ǲ��Ƕ����������ĺ������
    bool verify(vector<int>& sequence, int low, int high) {
        // ��ֹ�������ݹ鵽Ҷ��
        if (low >= high) return true;
        // �ҵ���ǰ�������������ı߽磬��һ�����ڸ��Ľڵ�
        int start = low;
        while (start < high && sequence[start] < sequence[high]) ++start;
        // ѭ���ж��������Ƿ񶼴��ڸ�
        for (int i = start; i < high; ++i) {
            if (sequence[i] <= sequence[high]) return false;
        }
        // ��ǰ���п��ſ��ԣ��ݹ鿴��������������
        // ע�⣡����������������Χ��start �� high - 1���ǵ�high
        return verify(sequence, low, start - 1) && verify(sequence, start, high - 1);
    }
};


#endif // DEBUG2