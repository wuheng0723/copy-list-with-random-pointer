/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
			return l2;
        if(l2 == NULL)
            return l1;
        ListNode *head = new ListNode(l1->val+l2->val);
        ListNode *pLast = head;
        ListNode *p1 = l1->next;
        ListNode *p2 = l2->next;
        while(p1&&p2)
        {
            ListNode *pNew = new ListNode(p1->val+p2->val+pLast->val/10);   //上一个节点进一位
            pLast->val = pLast->val%10;  //上一个节点进位之后的余数
            pLast->next = pNew;
            pLast = pNew;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1!=NULL)
        {
            ListNode *pNew = new ListNode(p1->val+pLast->val/10);   //上一个节点进一位
            pLast->val = pLast->val%10;  //上一个节点进位之后的余数
            pLast->next = pNew;
            pLast = pNew;
            p1 = p1->next;
        }
        while(p2!=NULL)
        {
            ListNode *pNew = new ListNode(p2->val+pLast->val/10);   //上一个节点进一位
            pLast->val = pLast->val%10;  //上一个节点进位之后的余数
            pLast->next = pNew;
            pLast = pNew;
            p2 = p2->next;
        }
        if(pLast->val>=10)
        {
            ListNode *pNew = new ListNode(pLast->val/10);   //上一个节点进一位
            pLast->val = pLast->val%10;  //上一个节点进位之后的余数
            pLast->next = pNew;
        }
        return head;
    }
};