#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;





class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		// ������ϣ��
		unordered_map<int, int> hashtable;

		// �߲��ұ�����ϣ����������
		for (int i = 0; i < nums.size(); ++i) {

			// ���û�鵽��ֱ�ӷ���hashtable.end()������鵽�ˣ�it ���Ƕ�Ӧ�ļ�ֵ��(��Ϊ�������ͻ�䣬���Բ�д��auto)
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end()) {

				// ֻ��һ�Լ�ֵ�ԣ�������ĿҪ����Ƿ�����������±꣬�����Ȱ��ҵ��ļ�ֵ�Ե�ֵit->second����
				// ��ǰ����Ԫ�ص��±꣬���ǲ�������������Ԫ�ص�������ע�⣬��ʱ�Ĺ�ϣ��ļ������ݵ�Ԫ�أ�ֵ��������±꣩
				// ��ϣ��ֻ�ܶԼ����в��ң�����Ҫ��Ԫ�ش�ɼ�
				return { it->second, i };
			
			}
			// û�鵽�Ļ��ʹ����ϣ����
			hashtable[nums[i]] = i;


		}
		return {};
	}
};



//#define DEBUG
#ifdef DEBUG

int main() {
	vector<int> nums = { 2,7,11,15 };
	int target = 9;
	Solution solution;
	vector<int> sum_index = solution.twoSum(nums, target);

	for (int i = 0; i < sum_index.size(); i++) {
		cout << "�����к�Ϊ" << target << "��Ԫ���±�Ϊ" << solution.twoSum(nums, target)[i] << endl;
	}
	return 0;

}

#endif // DEBUG
