

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

        // 首先为了和反转链表Ⅰ匹配，需要步进到cur 指向left节点的位置，
        // 注意先设置pre为nullptr，最后再把反转的链表链接到原链表上
        // 但为了知道before（反转区域的前一个节点）指向哪，所以其实是步进到left-1
        // 同时，left = 0时，没有before的位置，所以加入一个哨兵来处理特殊情况
        ListNode* dummy = new ListNode(-1, head);
        ListNode* before = dummy;

        // 先把before移动到反转区域的前一个节点
        for (int i = 0; i < left - 1; i++) {
            before = before->next;
        }

        // 开始常规反转
        ListNode* pre = nullptr;
        ListNode* cur = before->next;
        
        // 注意控制反转次数（要转多少个节点就是多少次）
        for (int i = 0; i < right - left + 1; i++) {
            
            // 创建next保存下一个
            ListNode* next = cur->next;

            cur->next = pre;
            pre = cur;
            cur = next;
        
        }

        // 现在cur 指向的就是反转区域的后一个节点，现在要把反转区域拼接起来
        // 注意这个错误写法！！！！逻辑上就错了
        /*cur->next = before->next;
        before->next = pre;*/

        // 应该是反转区域的第一个节点指向反转区域后一个节点
        // 然后反转区域前一个节点指向反转区域最后一个节点
        before->next->next = cur;
        before->next = pre;

        // 保存头节点，释放dummp
        ListNode* temp = dummy->next;
        delete dummy;
        return temp;

    }
};
#endif // DEBUG
