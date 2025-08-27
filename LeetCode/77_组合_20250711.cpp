#include <vector>
#include <functional>
using namespace std;



//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // ʹ��ѡ�Ͳ�ѡ��˼·
    // https://leetcode.cn/problems/combinations/solutions/2071017/hui-su-bu-hui-xie-tao-lu-zai-ci-pythonja-65lh/
    vector<vector<int>> combine(int n, int k) {

        // ��ʼ���ṹ����
        vector<vector<int>> ans;
        vector<int> path;

        // dfs
        function<void(int)> dfs = [&](int i) -> void {
            int d = k - path.size(); // ��Ҫѡ d ����
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }

            // ö�ٵ�������̫С���������û��������ѡ
            for (int j = i; j >= d; j--) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back(); // �ָ��ֳ�
            }
            };
        dfs(n); // �� i = n ��ʼ����ö��
        return ans;
    }
};
#endif // DEBUG
