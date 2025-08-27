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

// �ȱ���һ�£���ϣ����꣬�����Ҵ���Ϊ1��λ��
void FindNumsAppearingOnce(vector<int>& nums, int& num1, int& num2) {
	// ��ϣ��洢ÿ�����ֳ��ֵĴ���
	unordered_map<int, int> countMap;
	for (int num : nums) {
		countMap[num]++;
	}
	// ������ϣ���ҳ�����һ�ε�����
	/*for (const auto& pair : countMap) {
		if (pair.second == 1) {
			// �õ�һ�����Ƿ�Ϊ�����ж��Ƿ��Ѿ��ҵ���һ��ֻ����һ�ε�����
			// ���������ܻ������⣬�����һ��������0����ônum1�ͻᱻ��ֵΪ0
			if (num1 == 0) {
				num1 = pair.first; // ��һ��ֻ����һ�ε�����
			} else {
				num2 = pair.first; // �ڶ���ֻ����һ�ε�����
				break; // �ҵ������Ϳ����˳���
			}
		}
	}*/
	// ���ǲ��õڶ��ֱ�������
	auto it = countMap.begin();
	while (it != countMap.end()) {
		if (it->second == 1) {
			num1 = it->first; // ��һ��ֻ����һ�ε�����
			++it;// �ƶ�����һ��Ԫ��
			break; // �ҵ�һ�����˳��ٽ����ҵڶ�������Ϊ�����ж������һ���ĵ��Ǹ�ֵ��䲻ͬ
		}
		else {
			++it; // �ƶ�����һ��Ԫ��
		}
	}
	while (it != countMap.end()) {
		if (it->second == 1) {
			num2 = it->first; // �ڶ���ֻ����һ�ε�����
			break; // �ҵ��ڶ����Ϳ����˳���
		}
		else {
			++it; // �ƶ�����һ��Ԫ��
		}
	}
}

#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2
// https://interviewguide.cn/notes/03-hunting_job/03-algorithm/02-sword-offer/40-%E5%89%91%E6%8C%87offer.html
// ����������������û��ô����
void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {


	if (data.size() < 2) return;

	int totalNum = 0;
	for (int i = 0; i < data.size(); i++) {
		totalNum ^= data[i];//��������򣬽��Ϊ��ͬ���������ֵ����
	}

	int sign = 0;//��־λ����¼totalNum�еĵ�һ��1���ֵ�λ��
	for (; sign < data.size(); sign++) {
		if ((totalNum & (1 << sign)) != 0) { //���� sign λ�����������ֽ�������signλ������λ����0
			break;
		}
	}
	cout << sign << endl;
	num1[0] = 0;
	num2[0] = 0;
	for (int i = 0; i < data.size(); i++) {
		if ((data[i] & (1 << sign)) == 0) {//��־λΪ0��Ϊһ�飬����صõ�һ�����֣�����ע��==�����ȼ�����&������ǰ��ӣ�����
			num1[0] ^= data[i];
			cout << "0 " << data[i] << " " << (1 << sign) << endl;
		}
		else {
			num2[0] ^= data[i];//��־λΪ1��Ϊһ��
			cout << "1 " << data[i] << " " << (1 << sign) << endl;
		}
	}
	cout << num1[0] << num2[0] << endl;
}


#endif // DEBUG2