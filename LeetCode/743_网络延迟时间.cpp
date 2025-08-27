#include <vector>

using namespace std;





// https://leetcode.cn/problems/network-delay-time/solutions/2668220/liang-chong-dijkstra-xie-fa-fu-ti-dan-py-ooe8
// 【最短路径 迪杰斯特拉 dijkstra算法 数据结构与算法】https://www.bilibili.com/video/BV1QESyYGE55?vd_source=394ce55653aeb29ebdb87e06077ee56c

// Dijkstra 算法

class Solution {

public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		// 构造一个 n x n 的邻接矩阵，并初始化为 INT_MAX / 2
		// INT_MAX / 2 用来表示节点之间的初始距离，避免出现溢出
		// 这个矩阵用来存储从节点 i 到节点 j 的距离
		vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2)); // 使用INT_MAX / 2避免相加溢出
	
		// 遍历给定的 times 数组，并填充邻接矩阵 g
		// 每个元素 times[i] = [x, y, d]，表示从 x 节点到 y 节点的距离是 d
		for (auto& t : times) {
			g[t[0] - 1][t[1] - 1] = t[2]; // 更新 x 到 y 的距离
		}

		// 初始化一个距离数组 dis，表示从起点 k 到其他所有节点的最短距离
        // 初始时所有节点的距离都设置为 INT_MAX / 2，表示不可达
		vector<int> dis(n, INT_MAX / 2);

		// 起点 k 的最短距离为 0
		dis[k - 1] = 0;

		// 创建一个布尔数组 done,标记每个节点的最短路径是否已经确定
		vector<int> done(n);

		// 进入循环，不断更新节点的最短路径
		while (true) {
			
			// 选择一个未确定最短路径的节点x，选择当前距离起点最近的节点(下用来保存找到的节点号)
			int x = -1;

			for (int i = 0; i < n; i++) {
				// 寻找一个尚未标记为 done 且距离起点最近的节点
				// （最后x = -1的话就是done内所有节点已经处理完了）
				// （不然会找到done 里为false，且dis最小的那个）
				if (!done[i] && (x < 0 || dis[i] < dis[x])) {
					x = i;
				}
			}

			// 如果没有找到未处理的节点，表示所有节点的最短路径已经确定 ，返回当前的最大最短路径
			if (x < 0) {
				// C++11写法
				return *max_element(dis.begin(), dis.end()); // 返回最短路径的最大值

				// C++20写法
				//return range::max(dis);
			}

			// 如果当前节点的距离是无穷大，说明存在无法到达的节点
			if (dis[x] == INT_MAX / 2) {
				return -1;
			}

			// 标记节点 x 为已处理，最短路径已确定
			done[x] = true;

			// 更新与x 相邻的节点 y 的最短路径
			for (int y = 0; y < n; y++) {
				//如果从 x 到 y 的路径更短， 则更新 dis[y]
				dis[y] = min(dis[y], dis[x] + g[x][y]);
			}
		}
	}
};