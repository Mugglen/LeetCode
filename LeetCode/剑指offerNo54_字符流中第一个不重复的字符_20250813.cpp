#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
using namespace std;
//�ණ��������

//#define DEBUG1
#ifdef DEBUG1
// �Լ���ķ��������ǿռ临�Ӷ�̫����
class Solution
{
private:
	// ʹ������������һ�������洢�ַ���һ�������洢�ַ����ֵĴ���
    vector<char> charStream; // �洢�ַ���
    unordered_map<char, int> charCount;   // �洢�ַ����ֵĴ���
    // ���ڴ洢��һ��ֻ����һ�ε��ַ�
	char firstUniqueChar = '#';
public:

    //Insert one char from stringstream
    void Insert(char ch) {

		// ֻ����һ�Σ����ǵ�һ��ֻ����һ�ε��ַ�
        if (charCount.find(ch) == charCount.end() && firstUniqueChar == '#') {
			charCount[ch]++;
			charStream.push_back(ch);
			firstUniqueChar = ch; // ���µ�һ��ֻ����һ�ε��ַ�
        }
        // ֻ����һ�Σ������ǵ�һ��ֻ����һ�ε��ַ�
        else if (charCount.find(ch) == charCount.end() && firstUniqueChar != '#') {
            charCount[ch]++;
            charStream.push_back(ch);
        }
        // ���ֹ��ˣ�������ԭ����һ��ֻ����һ�ε��ַ�
        else if (charCount.find(ch) != charCount.end() && ch == firstUniqueChar) {
			// ��Ҫ���²��ҵ�һ��ֻ����һ�ε��ַ�
            charCount[ch]++;
            // ������һ��ֻ����һ�ε��ַ�
            firstUniqueChar = '#'; // �ȱ��Ϊ��Ч
            for (char c : charStream) {
                if (charCount[c] == 1) {
                    firstUniqueChar = c;
                    break;
                }
			}
        }
        // ���ֹ��ˣ�Ҳ���ǵ�һ��ֻ����һ�ε��ַ�
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

    vector<char> charStream; // �洢�ַ���

public:

    //Insert one char from stringstream
    void Insert(char ch) {
		// ֱ�Ӵ洢�ַ����ַ�����, ʹ��count������ͳ��
		charStream.push_back(ch);

    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        // ˳�������ͬʱ�������ҵ�һ��
        for (auto& ch : charStream) {
            if (count(charStream.begin(), charStream.end(), ch) == 1) return ch;
        }
		return '#'; // ���û���ҵ�������#
    }

};


#endif // DEBUG2
