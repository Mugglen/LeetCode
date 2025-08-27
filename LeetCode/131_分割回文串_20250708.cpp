#include <vector>
#include <string>
#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/palindrome-partitioning/solutions/2059414/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-fues/?envType=study-plan-v2&envId=top-100-liked
// ����2�����ӽ�
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    // �����ַ����ж�
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) { // ����C++20��д�����������԰�ans,pathά���ں�����

        int n = s.size();
        vector<vector<string>> ans;
        vector<string> path;

        // ע�������ת����������ö���ַ���������ö���ַ����ķָʽ
        // ���� s[i] ~ s[n-1] ��ô�ָ�(ע��дlamda���Ҫ�ӷֺ�)

        std::function<void(int)> dfs = [&](int i) {

            // �߽�����
            if (i == n) { // s �ָ���ɣ�
                ans.push_back(path);
                return;

            }

            for (int j = i; j < n; j++) { // ö���Ӵ��Ľ���λ��
                if (isPalindrome(s, i, j)) {
                    path.push_back(s.substr(i, j - i + 1)); // �ָ�
                    // ����ʣ��� s[j+1] ~ s[n-1]��ô�ָ�
                    dfs(j + 1);
                    path.pop_back(); // �ָ��ֳ�
                }
            }
            };
        // C++23��֧��this auto&&
        //auto dfs = [&](this auto&& dfs, int i) {
        //    };
        dfs(0);
        return ans;

    }
};
#endif // DEBUG
