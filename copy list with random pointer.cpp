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
        if(head == NULL)
            return head;          //if link list is NULL
        RandomListNode *head1 = NULL;
        RandomListNode *pPrevious = NULL;
        RandomListNode *pOld  = head;
        while (pOld != NULL)      //通过next指针将链表拷贝一份
            {
            	RandomListNode *pNew = new RandomListNode(pOld->label);
            	if (head1 == NULL)
                {
                    head1 = pNew;
                    pPrevious = head1;
                }
            	else
                    pPrevious->next = pNew;
            	pNew->label = pOld->label;
            	pNew->next  = NULL;
            	pNew->random = NULL;
            	pPrevious = pNew;
            	pOld = pOld->next;
			}
        pOld = head;
        RandomListNode *pNew = head1;
        while (pOld != NULL)
			{
            	if(pOld->random != NULL)
                {
                 	RandomListNode *pOld_1   = head;
                 	RandomListNode *pNew_1   = head1;
                 	while(pOld_1 != pOld->random)    //找到新链表里的random指针对应的单元
                        {
                         	pOld_1 = pOld_1->next;
                         	pNew_1 = pNew_1->next;
						}
                	pNew->random = pNew_1;
             	}
            	pOld = pOld->next;
            	pNew = pNew->next;
        	}
        return head1;
    }
};