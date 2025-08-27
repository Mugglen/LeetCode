#include <vector>
using namespace std;


//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param target int整型
     * @param array int整型vector<vector<>>
     * @return bool布尔型
     */
	 // 思路1：从右上角开始查找，因为右边一列每个都是对应行的最大值
	// 当前元素比target小，row++这样可以先确定行，
    // 当前元素比target大，col--再确定列
    // 最后越界了就是没找到
    bool Find(int target, vector<vector<int> >& array) {
        // write code here
        // 异常处理(空数组)
        if (array.empty() || array[0].empty())return false;
        // 获取行列
        int row = array.size();
        int col = array[0].size();
		// 从右上角开始查找
		int r = 0, c = col - 1;
        // 搜索(注意边界条件)
        while (r < row && c >= 0) {
            if (array[r][c] == target) return true;
            else if (array[r][c] < target) r++;//（在更下面的行）
            else c--; // array[r][c] > target (在当前行)
        }
        // 没找到
        return false;
    }
};
#endif // DEBUG
