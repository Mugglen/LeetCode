#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <functional>
#include <cstdlib>
#include <ctime>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1
// https://leetcode.cn/problems/insert-delete-getrandom-o1/?envType=study-plan-v2&envId=top-interview-150
class RandomizedSet {

private:
    // O(1)����Ͳ�����Ҫ��ϣ��
    unordered_map<int, int> indices;
    vector<int> nums;

public:
    RandomizedSet() {
        // �������������
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        // ���ҹ�ϣ��(ע������Ԫ�زŷ���false)
        if (indices.find(val) != indices.end()) return false;
        // ������β����
        int index = nums.size();
        nums.emplace_back(val);
        // ���¹�ϣ��
        indices[val] = index;
        return true;
    }

    bool remove(int val) {
        // ���ҹ�ϣ��
        if (indices.find(val) == indices.end()) return false;
        // ȡ���±�
        int indexToRemove = indices[val];
        int indexLast = nums.size() - 1;
        // β��Ԫ�ز���Ҫɾ��λ��
        nums[indexToRemove] = nums[indexLast];
        // ����β��Ԫ�ص�Index
        indices[nums[indexLast]] = indexToRemove;
        // ɾ��β��Ԫ��
        nums.pop_back();
        // ���¹�ϣ��
        indices.erase(val);
        return true;
    }

    int getRandom() {
        // ��ȡ����±�
        int randomIndex = rand()%nums.size();
        return nums[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


#endif // DEBUG1