#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
using namespace std;

//#define DEBUG1
#ifdef DEBUG1

// 也没要求最后的数组有序，反正奇数在前面，可以使用双指针（移动零的思路），把奇数交换到前面
// 不过要保证偶数之间和奇数之间相对位置
// 【1，3，5，2，4，6，7, 9】
// 当前这个好像不能保证偶数之间相对顺序，排序完变成【1，3，5，7，9，6，2, 4】
// 解决方法：
// 可以把偶数段先reverse 【1，3，5，7，9，4，2, 6】
// 再把前半段和后半段分别reverse 【1，3，5，7，9，2，4, 6】
class Solution
{
public:
	void reOrderArray(vector<int>& array) {

		if (array.size() == 0) return;
		// 初始化双指针,都初始化为0，处理的时候可以把第一个元素带上
		int left = 0; // 右指针自增交给for循环
		int firstSwap = -1;
		bool marked = false;

		for (int right = 0; right < array.size(); right++) {
			// 找到奇数
			if (array[right] % 2 == 1) {
				// 记录第一次交换偶数的右指针位置，就是最后偶数部分后半段的起点
				// （注意检测是不是交换的奇偶，否则可能是奇数原地交换）
				// 整个偶数部分的起点是最后left指向的位置
				if (!marked && array[right] % 2 == 1 && array[left] % 2 == 0) {
					firstSwap = right;
					marked = true;
				}

				swap(array[left], array[right]);
				left++;

			}
		}

		if (firstSwap != -1 && left < array.size()) {
			// 计算偶数部分的分割点
			int evenCount = array.size() - left;  // 偶数总数
			// 注意！！！！！reverse传入参数的后一个是需要反转元素的后一个的索引位置，所以下面这个splitOffset要+1
			int splitOffset = evenCount - (array.size() - firstSwap) + 1;  // 分割偏移

			cout << "evenCount = " << evenCount << ", splitOffset = " << splitOffset << endl;

			if (splitOffset > 0 && splitOffset < evenCount) {
				// 整体反转偶数部分
				reverse(array.begin() + left, array.end());

				cout << "整体反转后: ";
				for (int x : array) cout << x << " ";
				cout << endl;

				// 分别反转前后两部分
				reverse(array.begin() + left, array.begin() + left + splitOffset);
				//reverse(array.begin() + left, array.end());

				cout << "反转前部分: ";
				for (int x : array) cout << x << " ";
				cout << endl;

				reverse(array.begin() + left + splitOffset, array.end());
			}
			
		}
	}


};




int main() {
	vector<int> test = { 1, 3, 5, 2, 4, 6, 7, 9 };

	cout << "原数组: ";
	for (int x : test) cout << x << " ";
	cout << endl;

	Solution sol;
	sol.reOrderArray(test);

	cout << "结果: ";
	for (int x : test) cout << x << " ";
	cout << endl;

	// 期望输出: 1 3 5 7 9 2 4 6
	// 奇数在前: ✓
	// 奇数相对顺序: 1,3,5,7,9 ✓
	// 偶数相对顺序: 2,4,6 ✓

	return 0;
}

#endif // DEBUG1