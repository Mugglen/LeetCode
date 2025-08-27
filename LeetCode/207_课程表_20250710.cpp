#include <vector>
#include <functional>
using namespace std;

//#define DEBUG
#ifdef DEBUG

// https://leetcode.cn/problems/course-schedule/solutions/2992884/san-se-biao-ji-fa-pythonjavacgojsrust-by-pll7/?envType=study-plan-v2&envId=top-100-liked
// ��ɫ��Ƿ�
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // ��������ͼ, ע��ԭ���ṩ��������ϵ,������ͼ���Ǵ�ǰ�ÿγ�����ԭ�γ�
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]); // ע��!!!!��������
        }

        vector<int> colors(numCourses);

        // �����߼�,����true��ʾ�ҵ��˻�
        function<bool(int x)> dfs = [&](int x) -> bool {
            colors[x] = 1; // ��� x ���ڷ�����
            for (int y : graph[x]) {
                if (colors[y] == 1 || colors[y] == 0 && dfs(y)) {
                    return true;// �ҵ���
                }
            }
            colors[x] = 2; // �����ȫ�������
            return false;
            };

        // ��������,�л��򷵻�false
        for (int i = 0; i < numCourses; i++) {
            if (colors[i] == 0 && dfs(i)) {
                return false;
            }
        }

        return true;
    }
};


#endif // DEBUG
