#include <vector>

using namespace std;

// ����� �Ӽ����⡢������⡢�ָ����ⶼ����Ϊһ�����Ļ�����ô�������ͷָ����ⶼ���ռ�����Ҷ�ӽڵ㣬
// ���Ӽ����������������нڵ㣡
//#define DEBUG
#ifdef DEBUG
// https://www.programmercarl.com/0078.%E5%AD%90%E9%9B%86.html#%E6%80%9D%E8%B7%AF
// ˼·1: �涨����˳�򣬱���123ʱ����һ��forѭ������1��ͷ���ڶ���forѭ���ʹ�2��ʼ�ˣ��൱�ڲ�Ҫ1��
class Solution {

public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {
        
        // ���������ȱ���һ�µ�ǰ·����Ҫ������ֹ��ӵ����棬�����©���Լ�
        result.push_back(path);

        // �߽�����
        if (startIndex >= nums.size())return;

        for (int i = startIndex; i < nums.size(); i++) {
            // �ռ�·��
            path.push_back(nums[i]);
            // ����������ͬʱ���µݹ�
            backtracking(nums, i + 1);
            // �ָ��ֳ�
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;

    }

};

#endif // DEBUG

//#define DEBUG2
#ifdef DEBUG2
// �������㷨��·���Ӽ��ͻ��ݡ������㷨���� 14����https://www.bilibili.com/video/BV1mG4y1A7Gu?vd_source=394ce55653aeb29ebdb87e06077ee56c
// ˼·2���ڲ��涨����˳�������£�ֱ�ӱ�ʾ��ǰԪ����ѡ�����path���ǲ����룬��ʱӦ���ڱ߽��������ռ�
// ʱ�临�Ӷ�O��n*2^n��ÿ���ڵ�ѡ�������֣�һ��n���ڵ�

class Solution {

public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int index) {

        // �������������1�������������ھͲ����ռ�����·���ˣ�Ӧ�����ռ�Ҷ�ӽڵ��·�������ڱ߽��������ռ���
        //result.push_back(path);

        // �߽�����
        if (index >= nums.size()) {
            result.push_back(path); // Ӧ�÷��������ռ�
            return;
        };

        // ��ѡ��ǰ����,ֱ�ӽ�����һ���ݹ�
        backtracking(nums, index + 1);

        // ѡ��ǰ����
        path.push_back(nums[index]);
        backtracking(nums, index + 1);

        // �ݹ���ɣ���Ҫ�ָ��ֳ�
        path.pop_back();

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }

};




#endif // DEBUG2


// ע������˼·������Ҫ�����Ҫ���ռ�λ�ò�ͬ
// ˼·1��Ϊʹ����forѭ����������ǰ�滮������ÿ�α�����ÿ���ڵ�ʱ���Ƕ������ҹ̶��ģ�����ÿ���ڵ㶼�ռ�һ��path
// ˼·2��Ϊ�ݹ鵽ÿ���ڵ��ʱ��Ҫ�����ж�һ�Σ�һֱ��Ҷ�ӽڵ���ܶ�������·����ȫò�������ǵ�Ҷ�ӽڵ��ʱ����ռ�path