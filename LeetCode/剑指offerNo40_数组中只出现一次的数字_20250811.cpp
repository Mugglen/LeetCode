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

// 先暴力一下，哈希表存完，遍历找次数为1的位置
void FindNumsAppearingOnce(vector<int>& nums, int& num1, int& num2) {
	// 哈希表存储每个数字出现的次数
	unordered_map<int, int> countMap;
	for (int num : nums) {
		countMap[num]++;
	}
	// 遍历哈希表，找出出现一次的数字
	/*for (const auto& pair : countMap) {
		if (pair.second == 1) {
			// 用第一个数是否为空来判断是否已经找到第一个只出现一次的数字
			// 但这样可能会有问题，如果第一个数字是0，那么num1就会被赋值为0
			if (num1 == 0) {
				num1 = pair.first; // 第一个只出现一次的数字
			} else {
				num2 = pair.first; // 第二个只出现一次的数字
				break; // 找到两个就可以退出了
			}
		}
	}*/
	// 我们采用第二种遍历方法
	auto it = countMap.begin();
	while (it != countMap.end()) {
		if (it->second == 1) {
			num1 = it->first; // 第一个只出现一次的数字
			++it;// 移动到下一个元素
			break; // 找到一个先退出再接着找第二个，因为他们判断语句是一样的但是赋值语句不同
		}
		else {
			++it; // 移动到下一个元素
		}
	}
	while (it != countMap.end()) {
		if (it->second == 1) {
			num2 = it->first; // 第二个只出现一次的数字
			break; // 找到第二个就可以退出了
		}
		else {
			++it; // 移动到下一个元素
		}
	}
}

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/40-%E5%89%91%E6%8C%87offer.html
// 阿秀的异或做法，还没怎么看懂
void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {


	if (data.size() < 2) return;

	int totalNum = 0;
	for (int i = 0; i < data.size(); i++) {
		totalNum ^= data[i];//所有数异或，结果为不同的两个数字的异或
	}

	int sign = 0;//标志位，记录totalNum中的第一个1出现的位置
	for (; sign < data.size(); sign++) {
		if ((totalNum & (1 << sign)) != 0) { //左移 sign 位，将所有数字进行左移sign位，而低位补上0
			break;
		}
	}
	cout << sign << endl;
	num1[0] = 0;
	num2[0] = 0;
	for (int i = 0; i < data.size(); i++) {
		if ((data[i] & (1 << sign)) == 0) {//标志位为0的为一组，异或后必得到一个数字（这里注意==的优先级高于&，需在前面加（））
			num1[0] ^= data[i];
			cout << "0 " << data[i] << " " << (1 << sign) << endl;
		}
		else {
			num2[0] ^= data[i];//标志位为1的为一组
			cout << "1 " << data[i] << " " << (1 << sign) << endl;
		}
	}
	cout << num1[0] << num2[0] << endl;
}


#endif // DEBUG2