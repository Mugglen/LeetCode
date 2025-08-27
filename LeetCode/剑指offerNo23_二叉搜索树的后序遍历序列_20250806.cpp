#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;


//#define DEBUG1
#ifdef DEBUG1

// 注意本题和hot100里的98验证二叉搜索树不同，这个是验证是不是后序遍历
// 二叉搜索树是指父亲节点大于左子树中的全部节点，但是小于右子树中的全部节点的树
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 特判
        if (sequence.empty()) return false; // 空
        if (sequence.size() == 1) return true; // 只有一个节点
        // 因为是对遍历后序列进行判断而不是去后序遍历序列，所以递归不是后序的
        return verify(sequence, 0, sequence.size() - 1);
    }

    // 判断当前范围low到high内的序列是不是二叉搜索树的后序遍历
    bool verify(vector<int>& sequence, int low, int high) {
        // 递归边界，到叶子节点
        if (low >= high) return true;
        int start = low;
        // 因为二叉搜索树，左子树全部小于根，右子树全部大于根，
        // 找到第一个大于根的元素，那么在他之前都是左子树，之后都是右子树
        while (start < high && sequence[start] < sequence[high]) ++start;
        // 当前suquence[start]表示右子树遍历结果的第一个节点，循环判断右子树序列是不是都大于根节点sequence[high
        for (int i = start; i < high; ++i) {
            if (sequence[i] <= sequence[high]) return false; // 右子树必须全部大于根，否则为假
        }
        // 子问题，左子树序列是不是二叉搜索树的后序遍历, 右子树序列是不是二叉搜索树的后序遍历
        return verify(sequence, low, start - 1) && verify(sequence, start, high - 1);
    }
};


#endif // DEBUG1


//#define DEBUG2
#ifdef DEBUG2

// 练习
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        // 特判
        if (sequence.empty()) return false;
        if (sequence.size() == 1) return true; // 但节点是二叉搜索树
        return verify(sequence, 0, sequence.size() - 1);// 启动递归
    }

    // 判断当前范围low到high内的序列是不是二叉搜索树的后序遍历
    bool verify(vector<int>& sequence, int low, int high) {
        // 终止条件，递归到叶子
        if (low >= high) return true;
        // 找到当前序列左右子树的边界，第一个大于根的节点
        int start = low;
        while (start < high && sequence[start] < sequence[high]) ++start;
        // 循环判断右子树是否都大于根
        for (int i = start; i < high; ++i) {
            if (sequence[i] <= sequence[high]) return false;
        }
        // 当前序列看着可以，递归看左子树和右子树
        // 注意！！！！！右子树范围是start 到 high - 1不是到high
        return verify(sequence, low, start - 1) && verify(sequence, start, high - 1);
    }
};


#endif // DEBUG2