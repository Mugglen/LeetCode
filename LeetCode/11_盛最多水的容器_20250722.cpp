//#define DEBUG
#ifdef DEBUG

#include<vector>
using namespace std;
// 左右指针，每次向内移动短板指针
class Solution {
public:
    int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1, res = 0;
        while (i < j) {
            if (height[i] < height[j]) {
				res = max(res, height[i] * (j - i));
				i++;
            }
            else {
				res = max(res, height[j] * (j - i));
                j--;
            }
        }
        return res;
    }
};

#endif