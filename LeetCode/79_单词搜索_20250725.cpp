#include <vector>
#include <string>
#include <functional>
using namespace std;


//#define DEBUG
#ifdef DEBUG

class Solution {

private:
    int DIRS[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) -> bool {
            if (board[i][j] != word[k]) { // ƥ��ʧ��
                return false;
            }
            if (k + 1 == word.length()) { // ƥ��ɹ�
                return true;
            }
            board[i][j] = 0; // ��Ƿ��ʹ�
            for (auto& [dx, dy] : DIRS) {
                int x = i + dx, y = j + dy;
                if (0 <= x && x < m && 0 <= y && y < n && dfs(x, y, k + 1)) {
                    return true;
                }
            }
			board[i][j] = word[k]; // �ָ��ֳ�(��Ϊ�������ĸ���Ҳ�п�����Ϊ��������еĳ�Ա)
            return false;
            };
        // ÿ�����Ӷ�������Ϊ���
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) {
                    return true; // �ѵ���
                }
            }
        }
		return false; // û���ѵ�
    }
};

#endif // DEBUG


//#define PRETICE
#ifdef PRETICE

class Solution {

private:
    int DIRS[4][2] = { {0, 1}, { 0, -1 }, {1, 0}, {-1, 0} }; // �ϣ� �£� �ң� ��

public:
    bool exist(vector<vector<char>>& board, string word) {
        
		// �Ȼ�ȡ������
        int row = board.size();
        int col = board[0].size();

        // ����dfs������Ҫ���뵱ǰ������㣬 ����Ŀ�꣬ ͨ�������������߽磩
        function<bool(int, int, int)> dfs = [&](int i, int j, int k) ->bool {

            // �����յ�(ע������1������������������һ��һ����������Ҫ�ҵ������Ǹ��ַ���return true)
            //if (board[i][j] == word[k])return true;
            if (board[i][j] != word[k])return false; // �м��ַ���ƥ�䣬ֱ�ӷ���false
            // ʹ�õ�ǰĿ���ַ�λ��k���ж��Ƿ��Ѿ�ƥ�䵽���һ���ַ�
            if (k + 1 == word.length()) return true; // ƥ��ɹ�

            // ��ǰ�ַ�ƥ���ϣ����ǲ������һ���ַ�����������
            board[i][j] = 0; // ��Ƿ��ʹ�
            for (auto& [dx, dy] : DIRS) { // �����ĸ�����
				int x = i + dx, y = j + dy; // ������һ��λ��
                if (0 <= x && x < row && 0 <= y && y < col && dfs(x, y, k + 1)) {
                    return true;
                }
            }
			board[i][j] = word[k]; // �ָ��ֳ�(��Ϊ�������ĸ���Ҳ�п�����Ϊ��������еĳ�Ա)
			return false; // û���ҵ�ƥ����ַ�
            };
        // ÿ�����Ӷ����������
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(i, j, 0)) { // ��ÿ����㶼Ҫ�������ж�һ��
                    return true;
                }
            }
        }
		return false; // û���ҵ�ƥ����ַ�
    }
};

#endif // PRETICE