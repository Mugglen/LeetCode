#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {

public:
	int longestConsecutive(vector<int>& nums) { // ע�����ô���

		// ������ϣ���ڲ�Ҫֵ��ֻ��Ҫ���ٲ��ҵ�ʱ��ʹ��set
		unordered_set<int> num_set;

		// ���������������ϣ��
		for (const int& num : nums) {
			num_set.insert(num);
		}

		// ��ʼ����������еĳ���Ϊ0
		int longestStreak = 0;

		// ���� unordered_set �е�ÿ������
		for (const int& num : num_set) {
			// �����ǰ���ֵ�ǰһ�����ֲ��ڼ����У�˵����ǰ������һ���������е����
			if (!num_set.count(num - 1)) { // countֻ�ǲ��ҵ�ǰ��ϣ������û�ж�ӦԪ�أ��оͷ���1��û�ͷ���0
				int currentNum = num;// ��ǰ���֣���ǰ����������е��м������
				int currentStreak = 1;// ��ǰ�������еĳ��ȣ��������г��ȼ�������

				// ���ϼ�鵱ǰ���ֵ���һ�������Ƿ��ڼ�����
				while (num_set.count(currentNum + 1)) {
					currentNum += 1;// �ƶ�����һ������
					currentStreak += 1; // ���ӵ�ǰ�������еĳ���
				
				
				}

				// �����i�������еĳ���
				longestStreak = max(longestStreak, currentStreak);
			
			}
		
		
		}
		return longestStreak;
	
	
	}

};

//#define DEBUG
#ifdef DEBUG

int main() {

	vector<int> nums = { 100,4,200,1,3,2 };
	Solution solution;
	int longestStreak = solution.longestConsecutive(nums);
	cout << "��������еĳ�����" << longestStreak << endl;


	return 0;
}




#endif // DEBUG


