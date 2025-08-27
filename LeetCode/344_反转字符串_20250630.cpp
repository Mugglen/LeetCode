#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    // 双指针
    void reverseString(vector<char>& s) {

        if (s.empty())return;

        // 创建双指针
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // 错误点：！！！！！！！这里一开始写成right++了
            swap(s[left++], s[right--]);
        
        }



    }
};


int main() {

    Solution solution;
    vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
    solution.reverseString(s);
    for (const char& c : s) {
        cout << c << endl;
    }

}



#endif // DEBUG
