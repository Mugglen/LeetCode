#include <vector>
#include <functional>
using namespace std;


//#define DEBUG
#ifdef DEBUG

//时间复杂度 O(N!N) ： N 为数组 nums 的长度；时间复杂度和数组排列的方案数成线性关系，方案数为 N×(N−1)×(N−2)…×2×1 ，即复杂度为 O(N!) ；数组拼接操作 join() 使用 O(N) ；因此总体时间复杂度为 O(N!N) 。
//  可以使用路径长度乘上叶子节点个数来算。
//空间复杂度 O(N) ： 全排列的递归深度为 N ，系统累计使用栈空间大小为 O(N) 。
// https://leetcode.cn/problems/permutations/solutions/2079585/hui-su-bu-hui-xie-tao-lu-zai-ci-jing-que-6hrh/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path(n), on_path(n); // 所有排列的长度都是一样的 n

        //auto dfs = [&](this auto&& dfs, int i) {
        std::function<void(int)> dfs = [&](int i) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!on_path[j]) {
                    path[i] = nums[j];
                    on_path[j] = true;
                    dfs(i + 1);
                    on_path[j] = false;
                }
            }
            };
        dfs(0);
        return ans;
    }
};


#endif // DEBUG

//#define DEBUG1
#ifdef DEBUG1

//时间复杂度 O(N!N) ： N 为数组 nums 的长度；时间复杂度和数组排列的方案数成线性关系，方案数为 N×(N−1)×(N−2)…×2×1 ，即复杂度为 O(N!) ；数组拼接操作 join() 使用 O(N) ；因此总体时间复杂度为 O(N!N) 。
//  可以使用路径长度乘上叶子节点个数来算。
//空间复杂度 O(N) ： 全排列的递归深度为 N ，系统累计使用栈空间大小为 O(N) 。
// https://leetcode.cn/problems/permutations/solutions/2363882/46-quan-pai-lie-hui-su-qing-xi-tu-jie-by-6o7h/?envType=study-plan-v2&envId=top-100-liked
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
private:
    vector<vector<int>> res;
    void dfs(vector<int> nums, int x) {
        if (x == nums.size() - 1) {
            res.push_back(nums);      // 添加排列方案
            return;
        }
        for (int i = x; i < nums.size(); i++) {
            swap(nums[i], nums[x]);   // 交换，将 nums[i] 固定在第 x 位
            dfs(nums, x + 1);         // 开启固定第 x + 1 位元素
            swap(nums[i], nums[x]);   // 恢复交换
        }
    }
};


#endif // DEBUG1


