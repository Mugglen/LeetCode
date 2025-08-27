#include <string>
#include <unordered_map>

using namespace std;

//#define DEBUG
#ifdef DEBUG


class Solution {
public:
    bool isAnagram(string s, string t) {

        // 先检查是否都有内容（不对，直接检查两个是不是等长的）
        //if (s.empty() || t.empty())return false;
        if (s.size() != t.size())return false;

        unordered_map<char, int> map;

        // 挨个整进哈希表(注意哈希表是用来统计字符数量的，压入的同时要维护数量)
        for (char i : s) {
            map[i] += 1;
        }

        // 这里一开始没想到，直接对原字典，使用第二个string进行-=就行了
        for (char i : t) {
            map[i] -= 1;
        }

        // ！！！！！！！优化点，可以使用&来替代拷贝操作
        //for (auto iter : map) {
        for (const auto& iter : map) {

            // !!!!!!!!错误点：iter是std::pair<const Key, T> 对象，而second是成员变量不是成员函数，所以是.second
            //if (iter.second() != 0) return false;
            if (iter.second != 0) return false;
        }

        return true;

    }
};




#endif