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

// ����Ѱ�����һ�����ʵ����һλ��ǰһλ�ո�
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;
        int left, right = s.size() - 1;
        while (s[right] == ' ') { right--; }
        left = right;
        // ע�� && �Ķ�·���ԣ��ж��������ȼ���
        // �������s[left] != ' '��ǰ�棬left < 0ʱ�Ի�Խ�����
        //while (s[left] != ' ' && left >= 0) { 
        while (left >= 0 && s[left] != ' ') {
            left--; 
        }
        return right - left;

    }
};

// �⺯��д��
// https://leetcode.cn/problems/length-of-last-word/solutions/2787453/liang-chong-xie-fa-shou-xie-xun-huan-ku-nmzli/?envType=study-plan-v2&envId=top-interview-150
class Solution_1 {
public:
    int lengthOfLastWord(string s) {
        int i = s.find_last_not_of(' ');
        int j = s.find_last_of(' ', i);
        return i - j;
    }
};



#endif // DEBUG1



