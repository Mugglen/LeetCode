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
    // O(1)插入和查找需要哈希表
    unordered_map<int, int> indices;
    vector<int> nums;

public:
    RandomizedSet() {
        // 设置随机数种子
        srand((unsigned)time(NULL));
    }

    bool insert(int val) {
        // 查找哈希表(注意是有元素才返回false)
        if (indices.find(val) != indices.end()) return false;
        // 在数组尾插入
        int index = nums.size();
        nums.emplace_back(val);
        // 更新哈希表
        indices[val] = index;
        return true;
    }

    bool remove(int val) {
        // 查找哈希表
        if (indices.find(val) == indices.end()) return false;
        // 取出下标
        int indexToRemove = indices[val];
        int indexLast = nums.size() - 1;
        // 尾部元素插入要删除位置
        nums[indexToRemove] = nums[indexLast];
        // 更新尾部元素的Index
        indices[nums[indexLast]] = indexToRemove;
        // 删除尾部元素
        nums.pop_back();
        // 更新哈希表
        indices.erase(val);
        return true;
    }

    int getRandom() {
        // 获取随机下标
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