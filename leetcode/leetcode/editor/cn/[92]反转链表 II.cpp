//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。请你反转从位置 left 到位置 right 的链
//表节点，返回 反转后的链表 。
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], left = 2, right = 4
//输出：[1,4,3,2,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [5], left = 1, right = 1
//输出：[5]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点数目为 n 
// 1 <= n <= 500 
// -500 <= Node.val <= 500 
// 1 <= left <= right <= n 
// 
//
// 
//
// 进阶： 你可以使用一趟扫描完成反转吗？ 
// Related Topics 链表 👍 1249 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
class Solution {
public:
    ListNode * next = nullptr;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
         /*
          if (left>1){
             head->next = reverseBetween(head->next, left-1,right-1);
             return head;
         }
         else {
             if (right == 1) {
                 next = head->next;
                 return head;
             }
             ListNode * tmp = reverseBetween(head->next, left, right-1);
             head->next->next = head;
             head->next = next;
             return tmp;
         }
         */

         ListNode * now = head;
         ListNode * headPre = new ListNode();
         headPre -> next = head;
         ListNode * pre = headPre;
         ListNode * leftH ;
         int i = 1;
         while(now) {
             ListNode* next = now->next;
             if (i==left) leftH = pre;
             if (i==right) {
                 leftH->next->next = next;
                 leftH->next = now;
             }
             if (i>left && i<=right){
                 now -> next = pre;
             }
             pre = now;
             now = next;
             i++;
             if (i>right) break;
         }
         return headPre->next;

    }
};
//leetcode submit region end(Prohibit modification and deletion)
