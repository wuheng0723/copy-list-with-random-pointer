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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return head;
        ListNode *p = head;
        int num = 1;
        while(p->next)
        {
            p = p->next;
            num++;
        }
        int m = num - n;
        if(m == 0)
            return head->next;
        p = head;
        int i = 1;
        while(p->next)
        {
            if(i==m)
            {
                p->next = p->next->next;
                break;
            }
            p = p->next;
            i++;
        }
        return head;
    }
};