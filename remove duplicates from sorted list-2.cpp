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
    ListNode *deleteDuplicates(ListNode *head) {
		if(head == NULL || head->next == NULL) return head;
        ListNode *p = head;
        ListNode *pLast = NULL;
        int flag = 0;   //表示当前节点是否重复
        while(p)  
        {
            if(p->next!=NULL && p->val == p->next->val) //删除在后边重复的节点
            {
                p->next = p->next->next;
                flag = 1;
            }
            else
                if(flag == 0)
                {
                    pLast = p;
                    p = p->next;
                }
                else //删除第一个重复的节点
                {
                    if(pLast == NULL) //第一个节点即重复
                        head = p->next;
                    else
                        pLast->next = p->next;	
                    p = p->next;
                    flag = 0;
                }
        }
        return head;
    }
};