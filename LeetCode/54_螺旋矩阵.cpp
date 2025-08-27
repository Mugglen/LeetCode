#include <vector>

using namespace std;



// https://leetcode.cn/problems/spiral-matrix/solutions/2362055/54-luo-xuan-ju-zhen-mo-ni-qing-xi-tu-jie-juvi

//顺时针打印矩阵的顺序是 “从左向右、从上向下、从右向左、从下向上” 循环。
//因此，考虑设定矩阵的 “左、上、右、下” 四个边界，模拟以上矩阵遍历顺序。

class Solution {

public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {\

		// 异常值处理
		if (matrix.empty()) return{};

		// 初始化边界(因为是用作索引值，所以要-1)
		int left = 0; 
		int right = matrix[0].size() - 1;
		int top = 0;
		int bottom = matrix.size() - 1;

		// 初始化结果容器
		vector<int> res;

		// 边界处理放在循环里，循环条件写死
		while (true) {
			
			// 顶部从左到右
			for (int i = left; i <= right; i++)  res.push_back(matrix[top][i]); 
			if (++top > bottom) break; // 注意是>不是 == ，考虑单行的情况，top和bottom本来就是相等的,顺带将top提升，注意向下是索引递增
		
			// 右侧从上往下
			for(int i = top; i<=bottom; i++) res.push_back(matrix[i][right]);
			if (--right < left) break;

			// 底部从右往左
			for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
			if (--bottom < top) break;

			// 左侧从下往上
			for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
			if (++left > right) break;
		}
		return res;
	}
};