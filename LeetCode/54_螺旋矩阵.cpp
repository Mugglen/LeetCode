#include <vector>

using namespace std;



// https://leetcode.cn/problems/spiral-matrix/solutions/2362055/54-luo-xuan-ju-zhen-mo-ni-qing-xi-tu-jie-juvi

//˳ʱ���ӡ�����˳���� ���������ҡ��������¡��������󡢴������ϡ� ѭ����
//��ˣ������趨����� �����ϡ��ҡ��¡� �ĸ��߽磬ģ�����Ͼ������˳��

class Solution {

public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {\

		// �쳣ֵ����
		if (matrix.empty()) return{};

		// ��ʼ���߽�(��Ϊ����������ֵ������Ҫ-1)
		int left = 0; 
		int right = matrix[0].size() - 1;
		int top = 0;
		int bottom = matrix.size() - 1;

		// ��ʼ���������
		vector<int> res;

		// �߽紦�����ѭ���ѭ������д��
		while (true) {
			
			// ����������
			for (int i = left; i <= right; i++)  res.push_back(matrix[top][i]); 
			if (++top > bottom) break; // ע����>���� == �����ǵ��е������top��bottom����������ȵ�,˳����top������ע����������������
		
			// �Ҳ��������
			for(int i = top; i<=bottom; i++) res.push_back(matrix[i][right]);
			if (--right < left) break;

			// �ײ���������
			for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
			if (--bottom < top) break;

			// ����������
			for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
			if (++left > right) break;
		}
		return res;
	}
};