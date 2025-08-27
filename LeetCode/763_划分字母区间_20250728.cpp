#include <vector>
#include <string>
using namespace std;
//https://leetcode.cn/problems/partition-labels/?envType=study-plan-v2&envId=top-100-liked
//#define DEBUG
#ifdef DEBUG
// ע������˵������ĸ��ʵ������Сд��ĸ�����Կ�����һ������Ϊ26����������¼ÿ����ĸ�����ֵ�λ��
// ÿ����ĸ��һ�γ��ֺ�������λ�ã�����һ��Ƭ��Ҫ���������ĸ�Ļ���Ҫȡ����С���䣬��Ϊһ����ĸֻ�ܳ�����һ��Ƭ����
class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n = s.size();
		int last[26]; // ��¼ÿ����ĸ�����ֵ�λ��
        for (int i = 0; i < n; i++) {
			last[s[i] - 'a'] = i;// ������ 'a' �� ASCII ֵ��Ҫ����ת������
        }

        vector<int> ans;
		int start = 0, end = 0; // ��ǰƬ�ε���ʼ�ͽ���λ��(�е㻬�����ڵĸо�)
        for (int i = 0; i < n; i++) {
            // һֱȡ��ǰ����������ĸ��������λ��
			end = max(end, last[s[i] - 'a']); // ���µ�ǰƬ�εĽ���λ��
            if (end == i) { // ����ϲ����
				ans.push_back(end - start + 1); // Ƭ�γ���
				start = i + 1; // ������һ��Ƭ�ε���ʼλ��
            }
        }
        return ans;
    }
};


#endif // DEBUG


//#define PRETICE
#ifdef PRETICE
// ע������˵������ĸ��ʵ������Сд��ĸ�����Կ�����һ������Ϊ26����������¼ÿ����ĸ�����ֵ�λ��
// ÿ����ĸ��һ�γ��ֺ�������λ�ã�����һ��Ƭ��Ҫ���������ĸ�Ļ���Ҫȡ����С���䣬��Ϊһ����ĸֻ�ܳ�����һ��Ƭ����
class Solution {
public:
    vector<int> partitionLabels(string s) {

        // ��Ҫ���䳤��
        int n = s.size();
        // ��¼ÿ����ĸ�����ֵ�λ��
		int last[26] = { 0 }; // ��ʼ��Ϊ0����ʾû�г��ֹ�
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        // ������
        vector<int> ans;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            // ����Ƭ�εĽ���λ��
            end = max(end, last[s[i] - 'a']);
            // �ҵ���
            if (end == i) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};


#endif // PRETICE