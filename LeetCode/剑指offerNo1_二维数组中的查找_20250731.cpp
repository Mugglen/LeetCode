#include <vector>
using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param target int����
     * @param array int����vector<vector<>>
     * @return bool������
     */
	 // ˼·1�������Ͻǿ�ʼ���ң���Ϊ�ұ�һ��ÿ�����Ƕ�Ӧ�е����ֵ
	// ��ǰԪ�ر�targetС��row++����������ȷ���У�
    // ��ǰԪ�ر�target��col--��ȷ����
    // ���Խ���˾���û�ҵ�
    bool Find(int target, vector<vector<int> >& array) {
        // write code here
        // �쳣����(������)
        if (array.empty() || array[0].empty())return false;
        // ��ȡ����
        int row = array.size();
        int col = array[0].size();
		// �����Ͻǿ�ʼ����
		int r = 0, c = col - 1;
        // ����(ע��߽�����)
        while (r < row && c >= 0) {
            if (array[r][c] == target) return true;
            else if (array[r][c] < target) r++;//���ڸ�������У�
            else c--; // array[r][c] > target (�ڵ�ǰ��)
        }
        // û�ҵ�
        return false;
    }
};
#endif // DEBUG
