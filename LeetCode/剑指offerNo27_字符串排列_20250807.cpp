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

// ��ǰ˼·����46ȫ���еĻ������޸ĵģ������˶��ظ��ַ��Ĵ���
// �������������ţ���ϵ���⣬��û����
// https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&&tqId=11180&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	// ��hot100���46 ȫ���в�һ�����������ַ���,���ұ���str�п������ظ��ַ��������롰aa�������Ӧ���ǡ���aa���������ǡ���aa������aa����
    vector<string> Permutation(string str) {
        int n = str.size();
        vector<string> ans;
        string path;
        vector<bool> on_path(n, false);
		// ע�⣡����������������Ԥ��Ҫ��resize������reserve
        path.resize(n);// �������еĳ��ȶ���һ���� n

        // ���46ȫ���У��޸Ĺؼ��㣡��������������ͬ�ַ�����
        sort(str.begin(), str.end());

        // �ݹ���������ַ����͵�ǰpathö��λ��
        function<void(int)> dfs = [&](int i) {

			// �ݹ���ֹ����
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                // ���46ȫ���У��޸Ĺؼ��㣡���������Ѿ���path�ϵ��ַ������ظ��ַ��Ĵ���
                if (on_path[j] || (j > 0 && str[j] == str[j - 1] && !on_path[j - 1])) continue;

                // if (!on_path[j]) {
				path[i] = str[j];
				on_path[j] = true; // ��ǵ�ǰ�ַ���ʹ��
                dfs(i + 1);
				on_path[j] = false; // ���ݣ��ָ��ֳ�
                //}
            }
            };
        dfs(0);
        return ans;
    }
};


#endif // DEBUG1

