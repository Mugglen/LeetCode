#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
using namespace std;


//#define DEBUGs
#ifdef DEBUG

// ͬhot100 ��105
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param preOrder int����vector
     * @param vinOrder int����vector
     * @return TreeNode��
     */
    // ��Ŀ�ᵽ��û���ظ�Ԫ��
    // ֱ���뵽��˼·��
    // ��ǰ������ҵ����ڵ�
    // ����������ֳ���������
    // ����ǰ������ҵ������������ڵ�
    // ��ƴ�ӵ�ǰ���ڵ�������������ڵ�
    // ���������ɶ������������в�������Ҫ���ݵĲ������������ڵ������������� ���� ���������еķ�Χ��
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {

        // ʹ�ù�ϣ������Ԫ������������е�����
        unordered_map<int, int> map;
        for (int i = 0; i < vinOrder.size(); i++) {
            map[vinOrder[i]] = i;
        }

        // ʹ�õݹ�
        // ����ǩ��Ϊ����ǰ������и��ڵ������� �����������߽磬 ����������ұ߽磬��Ҫ������ָ������һ�����ڵ�λ�ã�
        // ������ڵ��������ڵݹ麯���ﹹ��󷵻�
        //auto constructor = [&](this auto&& constructor, int root, int left, int right) -> TreeNode* {
        function<TreeNode*(int, int, int)> constructor = [&](int root, int left, int right) -> TreeNode* {
            // �߽紦��
            if (left > right) return nullptr;
            // ����(root����ʹ��ǰ������е�λ�ã������ݹ�������ʱ���һ���������Թ̶���0����ȻҪ��һ������������rootλ�ò��������һ��)
            TreeNode* node = new TreeNode(preOrder[root]);
            // ����Ҫ�����������ĸ��ڵ㣨������Ҫ��ȡ���ڵ�����������е�λ�ã��Ϳ����ù�ϣ�������٣���ȷ�����������ķ�Χ�������жϵݹ���ֹ������
            // ȡ����ǰ���ڵ������
            int rootIndex = map[preOrder[root]];
            // �ݹ����
            node -> left = constructor(root + 1, left, rootIndex - 1);
            node->right = constructor(root + rootIndex - left + 1, rootIndex + 1, right);

            return node;
            };

        // �����ݹ�
        return constructor(0, 0, preOrder.size() - 1);
    }
};
#endif // DEBUG
