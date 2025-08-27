
#include <string>
#include <iostream>

using namespace std;


//#define DEBUG
#ifdef DEBUG
// https://www.programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html#%E6%80%9D%E8%B7%AF
class Solution {
public:
    string reverseStr(string s, int k) {

        // 利用步长机制控制
        // 每隔2k个字符的前k个进行反转
        // 剩余字符小于2k但是大于k个则反转前k个，可以归为一类
        for (int i = 0; i < s.size(); i += (2 * k)) {
            
            // 可使用坐标起点加步长判断的方式，原来是想用整体尺寸来减来判断
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                // 不够一个k，直接全部反转
                reverse(s.begin() + i, s.end());
            }
        
        }
        return s;

    }

    // 如果需要自己实现reverse的话
    void reverse(string& s, int start, int end) {
    
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }




};



#endif // DEBUG
