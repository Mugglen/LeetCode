#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>  // 用于分割字符串

using namespace std;

// 本题和77.组合 (opens new window)，216.组合总和III (opens new window)的区别是：
// 本题没有数量要求，可以无限重复，但是有总和的限制，所以间接的也是有个数的限制。

// 题目开始前尽量自己画树状图分析一下

// 本题是从同一个元素集合中，可以无限次取相同的元素
/*
// candidates = [2, 5, 3]
// target = 4

// 根节点：初始状态，开始从 [2,5,3] 中选数
start
 |
 ├── 取 2（sum = 2） --> 在 [2,5,3] 中继续选（可以重复）
 |     |
 |     ├── 取 2（sum = 4）== target ✅ --> return（加入结果）
 |     |
 |     ├── 取 5（sum = 7）> target ❌ --> return（剪枝）
 |     |
 |     └── 取 3（sum = 5）> target ❌ --> return（剪枝）
 |
 ├── 取 5（sum = 5）> target ❌ --> return（剪枝）
 |
 └── 取 3（sum = 3） --> 在 [3] 中继续选
	   |
	   └── 取 3（sum = 6）> target ❌ --> return（剪枝）

*/



class Solution {
private:
    vector<vector<int>> result;  // 存每个符合题意的结果集合
    vector<int> path;            // 存每层求和使用的数字

    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        // 条件判断
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 开始本次for循环
        for (int i = startIndex; i < candidates.size(); i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i); // 注意不用i + 1，可以重复读取相同元素

            sum -= candidates[i];  // 回溯过程逐层清空
            path.pop_back();
        }
    }

public:
    // 解析输入字符串为整数数组和目标值
    void parseInput(vector<int>& candidates, int& target) {
        // 读取第一行候选数字
        string candidates_line;
        getline(cin, candidates_line);

        // 读取第二行目标值
        string target_line;
        getline(cin, target_line);

        // 解析candidates_line为数字并存入candidates数组
        stringstream ss(candidates_line);
        string num;
        while (getline(ss, num, ',')) {
            candidates.push_back(stoi(num));  // 将分割出来的字符串转为整数
        }

        // 解析目标值
        target = stoi(target_line);  // 目标值是第二行的整数
        return;
    }



    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end());  // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

//#define DEBUG
#ifdef DEBUG

int main() {
    Solution solution;
    string input;

    vector<int> candidates;
    int target;

    // 解析输入
    solution.parseInput(candidates, target);

    // 调用算法并打印结果
    vector<vector<int>> result = solution.combinationSum(candidates, target);

    // 输出结果
    for (const auto& combination : result) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

#endif