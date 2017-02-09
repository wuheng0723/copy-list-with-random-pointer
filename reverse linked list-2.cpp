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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL || head->next == NULL) return head;
        if(n-m==0) return head;
        ListNode *p = head;
        int num = 1;
        while(p->next)
        {
            p = p->next;
            num++;
        }
        ListNode *pNew = new ListNode(0);   //方便后边的分析
        pNew->next = head;
        p = pNew;
        int i = 0;
        while(p)
        {
            if(i==m-1)
            {
                ListNode *pStart = p;
                ListNode *pPrevious = pStart->next;
                p = pPrevious->next;
                ListNode *pNext = p->next;
                i = i+2;
                while(i<=n)
                {
                    p->next = pPrevious;
                    pPrevious = p;
                    p = pNext;
                    i++;
                    if(p!=NULL)
                        pNext = pNext->next;
                }
                pStart->next->next = p;
                pStart->next = pPrevious;
            }
            else
            {
                p = p->next;
                i++;
            }
        }
        return pNew->next;
    }
};