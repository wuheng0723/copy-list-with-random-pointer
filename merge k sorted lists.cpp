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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty()) return NULL;
        ListNode *head = NULL;
        for(int i=0;i<lists.size();i++)
            merge(head,lists[i]);
        return head;
    }
    void merge(ListNode *&head1,ListNode *head2)
	{
        if(head1 == NULL)
        {
            head1 = head2;
            return;
        }
        if(head2 == NULL)
            return;
        ListNode *p1 = head1;
        ListNode *p2 = head2;
        ListNode *head3 = NULL;
        if(head1->val<=head2->val)
        {
            head3 = head1;
            p1 = p1->next;
        }
        else
        {
            head3 = head2;
            p2 = p2->next;
        }
        ListNode *p3 = head3;
        while(p1&&p2)
        {
            if(p1->val<=p2->val)
            {
                p3->next = p1;
                p1 = p1->next;
            }
            else
            {
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;	
        }
        while(p1)
        {
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while(p2)
        {
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        head1= head3;
	}
};