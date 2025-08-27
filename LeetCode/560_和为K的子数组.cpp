#include <vector>
#include <unordered_map> 
#include <iostream>
using namespace std;

// ע����������ص�
// �����������ģ�������ԾԪ�أ���
// ���ȿ��Բ�ͬ�������ǵ���Ԫ�أ�Ҳ�������������飩��
// ˳���ܱ䣨���뱣��ԭ������Ԫ�ص����˳�򣩡�


// ��������ǰ׺�� + ��ϣ���Ż�
// ����˼�룬ǰ׺�͵Ĳ�����ִ��ͣ�ֱ�Ӽ�鵱ǰpre-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // ��¼ǰ׺�ͳ��ִ���
        mp[0] = 1;  // ����ǰ׺�ͱ������ k �����
        int count = 0, pre = 0;  // count ͳ���������������������, pre ��¼ǰ׺��

        for (auto& x : nums) {  // ��������
            pre += x;  // ����ǰ׺��
            if (mp.find(pre - k) != mp.end()) {  // ��� pre-k �����ڹ�ϣ����
                count += mp[pre - k];  // �ۼӳ��ִ���
            }
            mp[pre]++;  // ��¼��ǰǰ׺�͵ĳ��ִ���
        }
        return count;
    }
};


//#define DEBUG
#ifdef DEBUG

int main() {
	vector<int> nums = { 1, 1, 1 };
	int k = 2;

	Solution solution;
	int result = solution.subarraySum(nums, k);
	cout << " �������к�Ϊ"<< k << "��������ĸ����ǣ�"  << result<< endl;

}


#endif // DEBUG

