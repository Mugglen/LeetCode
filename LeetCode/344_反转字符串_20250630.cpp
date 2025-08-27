#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//#define DEBUG
#ifdef DEBUG

class Solution {
public:
    // ˫ָ��
    void reverseString(vector<char>& s) {

        if (s.empty())return;

        // ����˫ָ��
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // ����㣺������������������һ��ʼд��right++��
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
