#include <vector>
#include <unordered_set>
using namespace std;
// https://leetcode.cn/problems/longest-consecutive-sequence/solutions/3005726/ha-xi-biao-on-zuo-fa-pythonjavacgojsrust-whop/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

		int ans = 0;
        unordered_set<int> set(nums.begin(), nums.end()); // ��numsת�ɹ�ϣ����
        // ע���Ǳ�����ϣ���ϣ����Ա�����ظ�Ԫ�صļ��㣩
        for (int x : set) {
			if (set.contains(x - 1)) continue; // �����ǰ���ֵ�ǰһ�������ڼ����У�˵����ǰ���ֲ����������е���㣬����
            
			// û�б�x��С���������֣�˵��x��һ���������е����
			int y = x + 1; // ��ǰ���ֵ���һ������
            while (set.contains(y)) { y++; }// ���ϲ�����һ������

			// ע��ѭ���� y - 1�����һ����������
			// ���ֱ���� y - x �����㵱ǰ�������еĳ���
			ans = max(ans, y - x); // ������������еĳ���
        
        }
        return ans;

    }
};
#endif // DEBUG

//#define PRETICE
#ifdef PRETICE
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // ��ĿҪ��O��n������������O(nlogn)
        int ans = 0;
        unordered_set<int> set(nums.begin(), nums.end());

		// ע�������ϣ����
        for(int x : set){
            if (set.contains(x - 1)) continue;

			int y = x + 1; // ��ǰ���ֵ���һ������
            while (set.contains(y)) { y++; }

			ans = max(ans, y - x); // ������������еĳ���
        }
        return ans;

    }
};
#endif // PRETICE
