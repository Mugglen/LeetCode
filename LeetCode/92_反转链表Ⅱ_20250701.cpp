

//#define DEBUG
#ifdef DEBUG
// https://www.bilibili.com/video/BV1sd4y1x7KN/?vd_source=7863beabe20c537c924d81df79243393

struct ListNode {
    
    int val;
    ListNode* next;
    ListNode(int x, ListNode* next) : val(x), next(next) {};

};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // ����Ϊ�˺ͷ�ת�����ƥ�䣬��Ҫ������cur ָ��left�ڵ��λ�ã�
        // ע��������preΪnullptr������ٰѷ�ת���������ӵ�ԭ������
        // ��Ϊ��֪��before����ת�����ǰһ���ڵ㣩ָ���ģ�������ʵ�ǲ�����left-1
        // ͬʱ��left = 0ʱ��û��before��λ�ã����Լ���һ���ڱ��������������
        ListNode* dummy = new ListNode(-1, head);
        ListNode* before = dummy;

        // �Ȱ�before�ƶ�����ת�����ǰһ���ڵ�
        for (int i = 0; i < left - 1; i++) {
            before = before->next;
        }

        // ��ʼ���淴ת
        ListNode* pre = nullptr;
        ListNode* cur = before->next;
        
        // ע����Ʒ�ת������Ҫת���ٸ��ڵ���Ƕ��ٴΣ�
        for (int i = 0; i < right - left + 1; i++) {
            
            // ����next������һ��
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        
        }

        // ����cur ָ��ľ��Ƿ�ת����ĺ�һ���ڵ㣬����Ҫ�ѷ�ת����ƴ������
        // ע���������д�����������߼��Ͼʹ���
        /*cur->next = before->next;
        before->next = pre;*/

        // Ӧ���Ƿ�ת����ĵ�һ���ڵ�ָ��ת�����һ���ڵ�
        // Ȼ��ת����ǰһ���ڵ�ָ��ת�������һ���ڵ�
        before->next->next = cur;
        before->next = pre;

        // ����ͷ�ڵ㣬�ͷ�dummp
        ListNode* temp = dummy->next;
        delete dummy;
        return temp;

    }
};
#endif // DEBUG
