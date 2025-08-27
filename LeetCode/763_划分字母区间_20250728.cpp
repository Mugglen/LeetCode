#include <vector>
#include <string>
using namespace std;
//https://leetcode.cn/problems/partition-labels/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
// 注意这题说的是字母，实际上是小写字母，所以可以用一个长度为26的数组来记录每个字母最后出现的位置
// 每个字母第一次出现和最后出现位置，就是一个片段要包含这个字母的话，要取的最小区间，因为一个字母只能出现在一个片段里
class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n = s.size();
		int last[26]; // 记录每个字母最后出现的位置
        for (int i = 0; i < n; i++) {
			last[s[i] - 'a'] = i;// 这里是 'a' 的 ASCII 值，要这样转成索引
        }

        vector<int> ans;
		int start = 0, end = 0; // 当前片段的起始和结束位置(有点滑动窗口的感觉)
        for (int i = 0; i < n; i++) {
            // 一直取当前遍历过的字母的最大结束位置
			end = max(end, last[s[i] - 'a']); // 更新当前片段的结束位置
            if (end == i) { // 区间合并完毕
				ans.push_back(end - start + 1); // 片段长度
				start = i + 1; // 更新下一个片段的起始位置
            }
        }
        return ans;
    }
};


#endif // DEBUG


//#define PRETICE
#ifdef PRETICE
// 注意这题说的是字母，实际上是小写字母，所以可以用一个长度为26的数组来记录每个字母最后出现的位置
// 每个字母第一次出现和最后出现位置，就是一个片段要包含这个字母的话，要取的最小区间，因为一个字母只能出现在一个片段里
class Solution {
public:
    vector<int> partitionLabels(string s) {

        // 需要区间长度
        int n = s.size();
        // 记录每个字母最后出现的位置
		int last[26] = { 0 }; // 初始化为0，表示没有出现过
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        // 计算结果
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            // 更新片段的结束位置
            end = max(end, last[s[i] - 'a']);
            // 找到了
            if (end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};


#endif // PRETICE