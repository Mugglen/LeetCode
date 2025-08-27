#include <vector>



using namespace std;

// https://leetcode.cn/problems/rotate-image/solutions/1228078/48-xuan-zhuan-tu-xiang-fu-zhu-ju-zhen-yu-jobi

// 原地选装
// 时间复杂度O（N^2）
// 空间复杂度O（1）

class Solution {

public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();

		// 一轮可以完成矩阵 4 个元素的旋转。因而，
		// 只要分别以矩阵左上角 1/4 的各元素为起始点执行以上旋转操作，即可完整实现矩阵旋转。

		// matrix[i][j] → matrix[j][n−1−i]
		// 原索引位置   → 旋转后索引位置
		// 注意这行在代码中应该是matrix[j][n - 1 - i] = tmp;

		// 如果按照外环旋转完再到内环的化索引会很难控制
		for (int i = 0; i < n / 2; i++) {

			// 注意是 n+1
			for (int j = 0; j < (n + 1) / 2; j++) {

				// 暂存每轮交换中第一个被修改位置的值
				int tmp = matrix[i][j];

				// 注意赋值顺序

				// ④ matrix[n−1−j][i] → matrix[i][j]
				matrix[i][j] = matrix[n - 1 - j][i];

				// ③ matrix[n−1−i][n−1−j] → matrix[n−1−j][i]
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];

				// ② matrix[j][n−1−i] → matrix[n−1−i][n−1−j]
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];

				// 必须放在最后，但是就推导来说得第一个写，然后按照递推下个赋值位置，然后反方向赋值
				// ① matrix[i][j] → matrix[j][n−1−i]
				matrix[j][n - 1 - i] = tmp;

			}

		}
	}

};