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

        // 先求出链表长度（有点k个一组字符串反转的感觉）
        int size = 0;
        ListNode* count = head;
        while (count) {
            size++;
            count = count->next;
        }
        // 剩余节点个数
        int numsRemain = size;

        // 开始k个一组的反转逻辑
        // 哨兵，反转域前一个节点
        ListNode* dummy = new ListNode(-1, head);
        ListNode* before = dummy;

        ListNode* cur = head;
        ListNode* pre = nullptr;

        // 剩余节点大于k
        while (numsRemain >= k) {

            numsRemain -= k;
            // 从第一个节点就开始了，相当于反转链表Ⅱ的left = 0的情况，正好用上dummy
            for (int i = 0; i < k; i++) {
                // 保存next
                ListNode* next = cur->next;
                // 反转
                cur->next = pre;
                // 移动
                pre = cur;
                cur = next;


            }
            // 一组结束后修改before和before->next两个节点的下一个节点
            before->next->next = cur;
            ListNode* beforeTemp = before->next;
            before->next = pre;

            // 一组循环结束，现在要更新before的位置，和再把pre置空
            
            //before = pre;// 这里错误！！！！！！！！！
            // before应该指向原来的反转区域的第一个节点before->next，但是上面我们要修改before->next，所以要提前存好
            before = beforeTemp;
            pre = nullptr;
        
        }

        // 注意取出的是dummy->next，如果只是ListNode* temp = dummy,是错了，dummy内存被删除了，不能访问
        ListNode* temp = dummy->next;
        delete dummy;

        return temp;

    }
};
#endif // DEBUG


