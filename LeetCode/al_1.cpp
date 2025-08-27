// 删除链表倒数第N个节点



// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
// 题目好像是（模拟大数乘法，但是LeetCode上没看见）

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:
	string multiply(string num1, string num2) {

		// 如果其中一个数字是“0”，直接返回“0”
		if (num1 == "0" || num2 == "0") return "0";

		int m = num1.size(), n = num2.size();

		// 初始化一个 m + n 长度的数组，用来存放每一位的乘积(注意初始化方式和长度)
		vector<int> res(m + n, 0);

		// 从后向前遍历num1 和 num2（这里当时也写错了！！！！注意低位是数组高位）
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				// 当前两个数字的乘积			
				int mul = (num1[i] - '0') * (num2[j] - '0');

				// 加上当前位置原有的值（因为可能有进位，注意结果数组的索引！！！）
				// 索引推导就用最简单的情况来说，两个最低位（高低位说的是字符串表示的数）i = m - 1,j = n - 1的时候，乘积应该保存在
				// res最低位m + n - 1里,所以索引是i + j + 1
				int sum = mul + res[i + j + 1];

				// 存储个位数，并把进位加到前一位
				res[i + j + 1] = sum % 10;
				res[i + j] += sum / 10;

			}
		
		}

		// 将结果数组转换为字符串
		string result = "";
		for (int i = 0; i < res.size(); ++i) {
		
			// 跳过前导零(为啥判断result要不为空？哦哦因为如果result里有值了，后面出现的零就是有效的了)
			if (!(result.empty() && res[i] == 0)) {
				result += to_string(res[i]);
			}
		}

		return result;

	}

};

//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;

	string num1 = "123", num2 = "456"; // 输出56088
		cout << "Result:" << solution.multiply(num1, num2) << endl;

	return 0;
}

#endif // DEBUG

