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
    // 两哈希表存字母出现次数
    bool canConstruct(string ransomNote, string magazine) {
        // ！！！！少加了快速判断
        if (ransomNote.size() > magazine.size()) return false;
        unordered_map<char, int> mapRan;
        unordered_map<char, int> mapMag;
        for (char c : ransomNote) {
            mapRan[c]++;
        }
        for (char c : magazine) {
            mapMag[c]++;
        }
        // 比较
        // 这行代码要求 ransomNote 中每个字母的出现次数必须完全等于 magazine 中对应字母的出现次数。
        // 但赎金信的要求是：magazine 中的字母数量必须大于等于 ransomNote 中的字母数量。
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

// 只用一份空间就行，第一个记录完第二个减去，减到小于0就是false
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

//作者：灵茶山艾府
//链接：https ://leetcode.cn/problems/ransom-note/solutions/3643383/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-nh3q/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


#endif // DEBUG2