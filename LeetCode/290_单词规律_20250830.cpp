#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Ҳ��һһ��Ӧ��ϵ����
        // �����s��Ŀ��˵�˲��ÿ���ǰ����β��ո�,����ÿ�������ɵ����ո�ָ�
        // ������ϣ���ӳ��
        unordered_map<char, string> mapC2S;
        unordered_map<string, char> mapS2C;
        // ˫ָ����string
        int left = 0, right = 0;
        for (char c : pattern) {
            // ���pattern���ȴ��ڵ�������
            if (right >= s.size()) return false;
            // ��ȡ��ǰ����
            while (right < s.size() && s[right] != ' ') right++;
            string sub = s.substr(left, right - left); //ע�⣡����substr�ڶ��������ǳ���
            // ˫���ж�
            if (mapC2S.find(c) != mapC2S.end()) {
                if (mapC2S[c] != sub) return false;
            }
            else {
                mapC2S[c] = sub;
            }
            if (mapS2C.find(sub) != mapS2C.end()) {
                if (mapS2C[sub] != c) return false;
            }
            else {
                mapS2C[sub] = c;
            }
            // �ж�ͨ�����ƶ�˫ָ�뵽��һ�����ʿ�ͷ����Ŀ˵��ֻ��һ���ո�
            left = ++right;
        }
        // ���pattern С�ڵ�������
        if (right < s.size()) return false;
        // ����ƥ��ɹ�
        return true;
    }
};

#endif // DEBUG1



