#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;
//脏东西？包的

//#define DEBUG1
#ifdef DEBUG1
// 自己想的方法，但是空间复杂度太高了
class Solution
{
private:
	// 使用两个容器，一个用来存储字符，一个用来存储字符出现的次数
    vector<char> charStream; // 存储字符流
    unordered_map<char, int> charCount;   // 存储字符出现的次数
    // 用于存储第一个只出现一次的字符
	char firstUniqueChar = '#';
public:

    //Insert one char from stringstream
    void Insert(char ch) {

		// 只出现一次，且是第一个只出现一次的字符
        if (charCount.find(ch) == charCount.end() && firstUniqueChar == '#') {
			charCount[ch]++;
			charStream.push_back(ch);
			firstUniqueChar = ch; // 更新第一个只出现一次的字符
        }
        // 只出现一次，但不是第一个只出现一次的字符
        else if (charCount.find(ch) == charCount.end() && firstUniqueChar != '#') {
            charCount[ch]++;
            charStream.push_back(ch);
        }
        // 出现过了，而且是原来第一个只出现一次的字符
        else if (charCount.find(ch) != charCount.end() && ch == firstUniqueChar) {
			// 需要重新查找第一个只出现一次的字符
            charCount[ch]++;
            // 查找下一个只出现一次的字符
            firstUniqueChar = '#'; // 先标记为无效
            for (char c : charStream) {
                if (charCount[c] == 1) {
                    firstUniqueChar = c;
                    break;
                }
			}
        }
        // 出现过了，也不是第一个只出现一次的字符
        else {
            charCount[ch]++;
        }
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
		return firstUniqueChar;
    }

};


#endif // DEBUG1



//#define DEBUG2
#ifdef DEBUG2

class Solution
{
private:

    vector<char> charStream; // 存储字符流

public:

    //Insert one char from stringstream
    void Insert(char ch) {
		// 直接存储字符到字符流中, 使用count函数来统计
		charStream.push_back(ch);

    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        // 顺序遍历，同时隐含了找第一个
        for (auto& ch : charStream) {
            if (count(charStream.begin(), charStream.end(), ch) == 1) return ch;
        }
		return '#'; // 如果没有找到，返回#
    }

};


#endif // DEBUG2
