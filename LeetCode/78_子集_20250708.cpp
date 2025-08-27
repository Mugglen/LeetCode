#include <vector>

using namespace std;

// 如果把 子集问题、组合问题、分割问题都抽象为一棵树的话，那么组合问题和分割问题都是收集树的叶子节点，
// 而子集问题是找树的所有节点！
//#define DEBUG
#ifdef DEBUG
// https://www.programmercarl.com/0078.%E5%AD%90%E9%9B%86.html#%E6%80%9D%E8%B7%AF
// 思路1: 规定遍历顺序，比如123时，第一次for循环锁定1开头，第二次for循环就从2开始了，相当于不要1了
class Solution {

public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int startIndex) {
        
        // 集合问题先保存一下当前路径，要放在终止添加的上面，否则会漏掉自己
        result.push_back(path);

        // 边界条件
        if (startIndex >= nums.size())return;

        for (int i = startIndex; i < nums.size(); i++) {
            // 收集路径
            path.push_back(nums[i]);
            // 增加索引的同时往下递归
            backtracking(nums, i + 1);
            // 恢复现场
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
// 【回溯算法套路①子集型回溯【基础算法精讲 14】】https://www.bilibili.com/video/BV1mG4y1A7Gu?vd_source=394ce55653aeb29ebdb87e06077ee56c
// 思路2：在不规定遍历顺序的情况下，直接表示当前元素是选择加入path还是不加入，这时应该在边界条件里收集
// 时间复杂度O（n*2^n）每个节点选择有两种，一共n个节点

class Solution {

public:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(vector<int>& nums, int index) {

        // 保存结果（错误点1！！！！！现在就不是收集所有路径了，应该是收集叶子节点的路径，放在边界条件里收集）
        //result.push_back(path);

        // 边界条件
        if (index >= nums.size()) {
            result.push_back(path); // 应该放在这里收集
            return;
        };

        // 不选择当前数字,直接进入下一级递归
        backtracking(nums, index + 1);

        // 选择当前数字
        path.push_back(nums[index]);
        backtracking(nums, index + 1);

        // 递归完成，需要恢复现场
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


// 注意两个思路的最主要差别，主要是收集位置不同
// 思路1因为使用了for循环进行了提前规划，所以每次遍历到每个节点时都是独立的且固定的，所以每个节点都收集一次path
// 思路2因为递归到每个节点的时候都要独立判断一次，一直到叶子节点才能定下整个路径的全貌，所以是到叶子节点的时候才收集path