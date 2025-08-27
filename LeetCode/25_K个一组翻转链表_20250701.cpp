/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// https://www.bilibili.com/video/BV1sd4y1x7KN/?vd_source=7863beabe20c537c924d81df79243393
//#define DEBUG
#ifdef DEBUG

struct ListNode {

    int val;
    ListNode* next;
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        // ����������ȣ��е�k��һ���ַ�����ת�ĸо���
        int size = 0;
        ListNode* count = head;
        while (count) {
            size++;
            count = count->next;
        }
        // ʣ��ڵ����
        int numsRemain = size;

        // ��ʼk��һ��ķ�ת�߼�
        // �ڱ�����ת��ǰһ���ڵ�
        ListNode* dummy = new ListNode(-1, head);
        ListNode* before = dummy;

        ListNode* cur = head;
        ListNode* pre = nullptr;

        // ʣ��ڵ����k
        while (numsRemain >= k) {

            numsRemain -= k;
            // �ӵ�һ���ڵ�Ϳ�ʼ�ˣ��൱�ڷ�ת������left = 0���������������dummy
            for (int i = 0; i < k; i++) {
                // ����next
                ListNode* next = cur->next;
                // ��ת
                cur->next = pre;
                // �ƶ�
                pre = cur;
                cur = next;


            }
            // һ��������޸�before��before->next�����ڵ����һ���ڵ�
            before->next->next = cur;
            ListNode* beforeTemp = before->next;
            before->next = pre;

            // һ��ѭ������������Ҫ����before��λ�ã����ٰ�pre�ÿ�
            
            //before = pre;// ������󣡣���������������
            // beforeӦ��ָ��ԭ���ķ�ת����ĵ�һ���ڵ�before->next��������������Ҫ�޸�before->next������Ҫ��ǰ���
            before = beforeTemp;
            pre = nullptr;
        
        }

        // ע��ȡ������dummy->next�����ֻ��ListNode* temp = dummy,�Ǵ��ˣ�dummy�ڴ汻ɾ���ˣ����ܷ���
        ListNode* temp = dummy->next;
        delete dummy;

        return temp;

    }
};
#endif // DEBUG


