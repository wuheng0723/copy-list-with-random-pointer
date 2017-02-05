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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
			return l2;
        if(l2==NULL)
            return l1;
        ListNode *head = new ListNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p3 = head;
        while(p1 && p2)
        {
            if(p1->val < p2->val)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3= p3->next;
        }
        if(p1!=NULL)
            p3->next = p1;
        if(p2!=NULL)
            p3->next = p2;
        return head->next;
    }
};