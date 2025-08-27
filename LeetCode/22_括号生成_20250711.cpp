#include <string>
#include <vector>
#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG
// https://leetcode.cn/problems/generate-parentheses/?envType=study-plan-v2&envId=top-100-liked
// ö�ٵ�ǰλ���������Ż��������ţ���Լ���Ĵ�2n��λ����ѡn���������ţ�
// Լ������Ϊ��ǰ�����Ÿ������ܳ���n �������Ÿ������ܳ��������Ÿ���
class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string> ans;
        string path(n * 2, 0); // �������ų��ȶ���һ���� 2n

        // Ŀǰ������left�������ţ�right��������
        //auto dfs = [&](this auto&& dfs, int left, int right) -> void {
        function<void(int, int)> dfs = [&](int left, int right) -> void {
            // ��������
            if (right == n) { // �����Ÿ���ʼ�մ��ڵ��������ţ����������������ж�
                ans.emplace_back(path);
                return;
            }
            if (left < n) { // ��������������
                path[left + right] = '('; // ֱ�Ӹ��ǣ��൱�ڻָ��ֳ���
                dfs(left + 1, right); // ֱ��һ·ѡ�����ŵ�n��Ȼ��ѡ��������return
            }
            if (right < left) { // ��������������
                path[left + right] = ')'; // ֱ�Ӹ���(��һ��if�Ľ����������һ��if���dfs������Ͳ��û�ԭ�ֳ���)
                dfs(left, right + 1);
            }
            };
        dfs(0, 0);
        return ans;
    }
};

int main() {

    Solution solution;
    solution.generateParenthesis(3);
    return 0;
}


#endif // DEBUG
