// ɾ����������N���ڵ�



// �����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
// ע�⣺����ʹ���κ����õ� BigInteger ���ֱ�ӽ�����ת��Ϊ������
// ��Ŀ�����ǣ�ģ������˷�������LeetCode��û������

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:
	string multiply(string num1, string num2) {

		// �������һ�������ǡ�0����ֱ�ӷ��ء�0��
		if (num1 == "0" || num2 == "0") return "0";

		int m = num1.size(), n = num2.size();

		// ��ʼ��һ�� m + n ���ȵ����飬�������ÿһλ�ĳ˻�(ע���ʼ����ʽ�ͳ���)
		vector<int> res(m + n, 0);

		// �Ӻ���ǰ����num1 �� num2�����ﵱʱҲд���ˣ�������ע���λ�������λ��
		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				// ��ǰ�������ֵĳ˻�			
				int mul = (num1[i] - '0') * (num2[j] - '0');

				// ���ϵ�ǰλ��ԭ�е�ֵ����Ϊ�����н�λ��ע���������������������
				// �����Ƶ�������򵥵������˵���������λ���ߵ�λ˵�����ַ�����ʾ������i = m - 1,j = n - 1��ʱ�򣬳˻�Ӧ�ñ�����
				// res���λm + n - 1��,����������i + j + 1
				int sum = mul + res[i + j + 1];

				// �洢��λ�������ѽ�λ�ӵ�ǰһλ
				res[i + j + 1] = sum % 10;
				res[i + j] += sum / 10;

			}
		
		}

		// ���������ת��Ϊ�ַ���
		string result = "";
		for (int i = 0; i < res.size(); ++i) {
		
			// ����ǰ����(Ϊɶ�ж�resultҪ��Ϊ�գ�ŶŶ��Ϊ���result����ֵ�ˣ�������ֵ��������Ч����)
			if (!(result.empty() && res[i] == 0)) {
				result += to_string(res[i]);
			}
		}

		return result;

	}

};

//#define DEBUG
#ifdef DEBUG

int main() {
	Solution solution;

	string num1 = "123", num2 = "456"; // ���56088
		cout << "Result:" << solution.multiply(num1, num2) << endl;

	return 0;
}

#endif // DEBUG

