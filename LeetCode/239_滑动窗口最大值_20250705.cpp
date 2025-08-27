#include <vector>
#include <queue>
using namespace std;



//#define DEBUG
#ifdef DEBUG
class Solution {
public:
    // https://leetcode.cn/problems/sliding-window-maximum/solutions/2499715/shi-pin-yi-ge-shi-pin-miao-dong-dan-diao-ezj6/?envType=study-plan-v2&envId=top-100-liked
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // ��ʼ�����
        vector<int> ans;
        deque<int> q;

        // ʹ�õ�������(ע��ֻά���±�)
        for (int i = 0; i < nums.size(); i++) {
            // 1.�ұ��루Ԫ�ؽ����β��ͬʱά�����е����ԣ�
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);

            // 2.��߳���Ԫ���뿪���ף�
            if (q.front() <= i - k) {
                q.pop_front();
            }

            // 3.��¼��(��k-1�����ſ�ʼÿ�λ�����¼�𰸣�û����֮ǰ��������k)
            if (i >= k - 1) {
                // ���ڶ��׵���β�����ݼ������Դ������ֵ���ڶ���
                ans.push_back(nums[q.front()]);
            }

        }
        return ans;

    }
};
#endif // DEBUG


//#define PRETICE
#ifdef PRETICE

class Solution {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // ��Ŀ��ʾ��k < nums.length���ÿ���
        // ��ʼ�����
        vector<int> ans;

        // ʹ�õ������У���Ϊÿ��ѭ��Ҫ��˳��룩
        deque<int> dq;

        for (int i = 0; i < nums.size(); i++) {
        
            // 1.��β����ʱ���бȽϣ�������дӶ��׵���β������(ע����д�ŵ�������)

            // ����д��������������������ֻ�Ƚ���һ�Σ�Ҫ�Ѷ���������С�ڵ�ǰֵ�Ķ�pop��
            /*if (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
                dq.push_back(i);
            }*/
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            
            // 2.������Ԫ�������Ƿ��Ѿ�������ǰ���ڣ�������ȥ��(��ʵ���ǵ��ڵ����)
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // 3. �Ӵ��ĳ����㹻ʱ��ʼ��¼��
            if (i >= k - 1) {
                //ans.push_back(dq.front()); // ����д��2������������ֻ��������û������ֵ
                ans.push_back(nums[dq.front()]);
            }
        
        }
        return ans;

    }
};




#endif // PRETICE