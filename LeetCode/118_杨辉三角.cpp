#include <vector>

using namespace std;

// https://leetcode.cn/problems/pascals-triangle/solutions/2784222/jian-dan-ti-jian-dan-zuo-pythonjavaccgoj-z596

// 时间复杂度：O(numRows^2)
// 空间复杂度：O(1)

class Solution {

public:
	vector<vector<int>> generate(int numRows) {
		
		// 初始话结果矩阵，但是不规定行宽
		vector<vector<int>> c(numRows);
		
		for (int i = 0; i < numRows; i++) {
			// 索引访问，观察得每行行宽为行号+1，从0开始，同时初始化为1，直接解决每行第一和最后一个元素
			c[i].resize(i + 1, 1);

			// 将三角左对齐，发现除了每行第一和最后一个元素是1外，剩下的每个元素是前一行同位置元素和前一个元素的和
			for (int j = 1; j < i; j++) { // (!!!!注意j从1开始，小于i不是小于i+1)
				// 左上方的数 + 正上方的数
				c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			}
		}
		return c;
	
	}

};