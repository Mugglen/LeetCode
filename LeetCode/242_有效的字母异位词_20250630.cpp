#include <string>
#include <unordered_map>

using namespace std;

//#define DEBUG
#ifdef DEBUG


class Solution {
public:
    bool isAnagram(string s, string t) {

        // �ȼ���Ƿ������ݣ����ԣ�ֱ�Ӽ�������ǲ��ǵȳ��ģ�
        //if (s.empty() || t.empty())return false;
        if (s.size() != t.size())return false;

        unordered_map<char, int> map;

        // ����������ϣ��(ע���ϣ��������ͳ���ַ������ģ�ѹ���ͬʱҪά������)
        for (char i : s) {
            map[i] += 1;
        }

        // ����һ��ʼû�뵽��ֱ�Ӷ�ԭ�ֵ䣬ʹ�õڶ���string����-=������
        for (char i : t) {
            map[i] -= 1;
        }

        // ���������������Ż��㣬����ʹ��&�������������
        //for (auto iter : map) {
        for (const auto& iter : map) {

            // !!!!!!!!����㣺iter��std::pair<const Key, T> ���󣬶�second�ǳ�Ա�������ǳ�Ա������������.second
            //if (iter.second() != 0) return false;
            if (iter.second != 0) return false;
        }

        return true;

    }
};




#endif