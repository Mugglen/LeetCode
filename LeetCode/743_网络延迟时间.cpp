#include <vector>

using namespace std;





// https://leetcode.cn/problems/network-delay-time/solutions/2668220/liang-chong-dijkstra-xie-fa-fu-ti-dan-py-ooe8
// �����·�� �Ͻ�˹���� dijkstra�㷨 ���ݽṹ���㷨��https://www.bilibili.com/video/BV1QESyYGE55?vd_source=394ce55653aeb29ebdb87e06077ee56c

// Dijkstra �㷨

class Solution {

public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		// ����һ�� n x n ���ڽӾ��󣬲���ʼ��Ϊ INT_MAX / 2
		// INT_MAX / 2 ������ʾ�ڵ�֮��ĳ�ʼ���룬����������
		// ������������洢�ӽڵ� i ���ڵ� j �ľ���
		vector<vector<int>> g(n, vector<int>(n, INT_MAX / 2)); // ʹ��INT_MAX / 2����������
	
		// ���������� times ���飬������ڽӾ��� g
		// ÿ��Ԫ�� times[i] = [x, y, d]����ʾ�� x �ڵ㵽 y �ڵ�ľ����� d
		for (auto& t : times) {
			g[t[0] - 1][t[1] - 1] = t[2]; // ���� x �� y �ľ���
		}

		// ��ʼ��һ���������� dis����ʾ����� k ���������нڵ����̾���
        // ��ʼʱ���нڵ�ľ��붼����Ϊ INT_MAX / 2����ʾ���ɴ�
		vector<int> dis(n, INT_MAX / 2);

		// ��� k ����̾���Ϊ 0
		dis[k - 1] = 0;

		// ����һ���������� done,���ÿ���ڵ�����·���Ƿ��Ѿ�ȷ��
		vector<int> done(n);

		// ����ѭ�������ϸ��½ڵ�����·��
		while (true) {
			
			// ѡ��һ��δȷ�����·���Ľڵ�x��ѡ��ǰ�����������Ľڵ�(�����������ҵ��Ľڵ��)
			int x = -1;

			for (int i = 0; i < n; i++) {
				// Ѱ��һ����δ���Ϊ done �Ҿ����������Ľڵ�
				// �����x = -1�Ļ�����done�����нڵ��Ѿ��������ˣ�
				// ����Ȼ���ҵ�done ��Ϊfalse����dis��С���Ǹ���
				if (!done[i] && (x < 0 || dis[i] < dis[x])) {
					x = i;
				}
			}

			// ���û���ҵ�δ����Ľڵ㣬��ʾ���нڵ�����·���Ѿ�ȷ�� �����ص�ǰ��������·��
			if (x < 0) {
				// C++11д��
				return *max_element(dis.begin(), dis.end()); // �������·�������ֵ

				// C++20д��
				//return range::max(dis);
			}

			// �����ǰ�ڵ�ľ����������˵�������޷�����Ľڵ�
			if (dis[x] == INT_MAX / 2) {
				return -1;
			}

			// ��ǽڵ� x Ϊ�Ѵ������·����ȷ��
			done[x] = true;

			// ������x ���ڵĽڵ� y �����·��
			for (int y = 0; y < n; y++) {
				//����� x �� y ��·�����̣� ����� dis[y]
				dis[y] = min(dis[y], dis[x] + g[x][y]);
			}
		}
	}
};