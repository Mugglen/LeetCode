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
    // 阿秀 https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/32-%E5%89%91%E6%8C%87offer.html
    // 牛客解析 https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&&tqId=11185&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
    string PrintMinNumber(vector<int>& numbers) {
        // 转成string备用
        vector<string> temp;
        for(auto num : numbers){
            temp.push_back(to_string(num));
        }
		// 排序 321和123 使用这种排序方式可以看出123321 < 321123
        sort(temp.begin(), temp.end(), [](const string& a, const string& b) { return a + b < b + a; });
		// 拼接
        string result;
        for(const auto& str : temp){
            result += str;
        }
		return result;
    }
};

#endif // DEBUG1