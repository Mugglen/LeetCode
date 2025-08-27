// �ҵ�������a[i] ,a[j]��i<jʱa[i]>a[j]������

#include <iostream>
#include <vector>

using namespace std;

// �鲢����ĺϲ��׶Σ��������������
int mergeAndCount(vector<int>& nums, int left, int mid, int right) {
    int count = 0;
    int i = left, j = mid + 1;
    vector<int> temp;

    // �ϲ�����������Ĳ���
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i]);
            i++;
        }
        else {
            // nums[i] > nums[j]��˵���� i �� mid ֮���Ԫ�ض����� nums[j]�����������
            temp.push_back(nums[j]);
            count += (mid - i + 1); // �������Ŀ����
            j++;
        }
    }

    // ��ʣ���Ԫ�ؼ��뵽 temp
    while (i <= mid) {
        temp.push_back(nums[i]);
        i++;
    }
    while (j <= right) {
        temp.push_back(nums[j]);
        j++;
    }

    // ����ʱ�����е�Ԫ�ؿ�����ԭ����
    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }

    return count;
}

// �鲢����������������Ե�����
int mergeSortAndCount(vector<int>& nums, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSortAndCount(nums, left, mid); // ��벿�ֵ������
        count += mergeSortAndCount(nums, mid + 1, right); // �Ұ벿�ֵ������
        count += mergeAndCount(nums, left, mid, right); // �ϲ�������ʱ���������
    }
    return count;
}


//#define DEBUG
#ifdef DEBUG

int main() {
    vector<int> nums = { 7, 5, 6, 4 };
    int result = mergeSortAndCount(nums, 0, nums.size() - 1);
    cout << "����Ե�����: " << result << endl;
    return 0;
}

#endif // DEBUG


