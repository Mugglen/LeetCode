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
    // ����ϣ�����ĸ���ִ���
    bool canConstruct(string ransomNote, string magazine) {
        // ���������ټ��˿����ж�
        if (ransomNote.size() > magazine.size()) return false;
        unordered_map<char, int> mapRan;
        unordered_map<char, int> mapMag;
        for (char c : ransomNote) {
            mapRan[c]++;
        }
        for (char c : magazine) {
            mapMag[c]++;
        }
        // �Ƚ�
        // ���д���Ҫ�� ransomNote ��ÿ����ĸ�ĳ��ִ���������ȫ���� magazine �ж�Ӧ��ĸ�ĳ��ִ�����
        // ������ŵ�Ҫ���ǣ�magazine �е���ĸ����������ڵ��� ransomNote �е���ĸ������
        for (auto it = mapRan.begin(); it != mapRan.end(); it++) {
            //if (it->second != mapMag[it->first]) return false;
            if (it->second > mapMag[it->first]) return false;
        }
        return true;
    }
};


#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2

// ֻ��һ�ݿռ���У���һ����¼��ڶ�����ȥ������С��0����false
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        int cnt[26]{};
        for (char c : magazine) {
            cnt[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (--cnt[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};

//���ߣ����ɽ����
//���ӣ�https ://leetcode.cn/problems/ransom-note/solutions/3643383/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-nh3q/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������


#endif // DEBUG2