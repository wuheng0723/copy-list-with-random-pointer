/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return head;
        RandomListNode *pOld = head;
        RandomListNode *head1 = NULL;
        while (pOld!=NULL)
        {
         	RandomListNode *pNew = new RandomListNode(pOld->label);
            pNew->label = pOld->label;
            pNew->next  = pOld->next;    //将新节点插入到旧节点的后边
            pOld->next  = pNew;
            pNew->random = NULL;
            pOld = pOld->next->next;
        }
        pOld = head;
        head1 = pOld->next;
        RandomListNode *pNew = head1;
        while(pNew!=NULL)
        {
            if(pOld->random != NULL)
            	pNew->random = pOld->random->next;
            if(pNew->next == NULL)
                break;
            pOld = pOld->next->next;
            pNew = pNew->next->next;
        }
        pNew = head1;
        while(pNew->next!=NULL)
        {
            pNew->next = pNew->next->next;
            pNew = pNew->next;
        }
        pOld = NULL;
        pNew = NULL;
        return head1;
    }
};