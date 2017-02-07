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
    ListNode *partition(ListNode *head, int x) {
        if(head==NULL || head->next==NULL)
			return head;
        ListNode *p = head;
        ListNode *less = new ListNode(0);
        ListNode *equal = new ListNode(0);
        ListNode *newLink = less;
        ListNode *newEqual = equal;
        while(p)
        {
            if(p->val < x)
            {
                less->next = p;
                less = less->next;
            }
            else
            {
                equal->next = p;
                equal = equal->next;
            }
            p = p->next;
        }
        less->next = newEqual->next;
        equal->next = NULL;
        return newLink->next;
        
    }
};