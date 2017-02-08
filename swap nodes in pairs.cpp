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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p = head;
        ListNode *pNext = head->next;
        ListNode *pLast = NULL;    //上一对的第二个节点
        while(p&&pNext)
        {
            p->next = pNext->next;
            pNext->next = p;
            if(p == head)
                head = pNext;
            if(pLast!=NULL)
                pLast->next = pNext;
            pLast = p;
            p = p->next;
            if(p==NULL)
                break;
            pNext = p->next;
        }
        return head;
    }
};