#include <vector>
#include <algorithm>
//#include <ranges>

using namespace std;

// https://leetcode.cn/problems/merge-intervals/solutions/2798138/jian-dan-zuo-fa-yi-ji-wei-shi-yao-yao-zh-f2b3

// �Ȱ���˵�����Ϊ�˽��ϲ�������������������

// ʱ�临�Ӷȣ�O(nlogn)������ n �� intervals �ĳ��ȡ�ƿ���������ϡ�
// �ռ临�Ӷȣ�O(1)�������ջ�����ͷ���ֵ�����롣

class Solution {

public:

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		
		// C++20��ranges����ĺ��������Զ�������������Ĭ�ϰ��������е�Ԫ�ص���Ȼ˳��������������ǰ�����˵�����
		// ranges:sort(intervals); 

		// ��ͳ�İ�����˵�����ķ���(ʹ����Lambda)
		sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
			return a[0] < b[0];
		});

		vector<vector<int>> ans;
		for (vector<int> p : intervals){
			//���β鿴�Ҷ˵㣬���µ�ǰ����p���Ҷ˵㣨�ϲ���
			//ע����������������䡾1��3����2��4����3��5��
			// ����ÿ�κϲ���������˵���Ѻϲ������һ������ans.back()���Ҷ˵�Ƚ�

			// ���ص�����
			if (!ans.empty() && p[0] <= ans.back()[1]) {

				// �����Ҷ˵����ֵ
				ans.back()[1] = max(ans.back()[1], p[1]);
			
			}
			else { // ���ཻ���޷��ϲ��� ��Ϊ�µĴ��ϲ�����
				ans.emplace_back(p);
			}
		}
		return ans;
	}
};