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
        int flag = 0;   //��ʾ��ǰ�ڵ��Ƿ��ظ�
        while(p)  
        {
            if(p->next!=NULL && p->val == p->next->val) //ɾ���ں���ظ��Ľڵ�
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
                else //ɾ����һ���ظ��Ľڵ�
                {
                    if(pLast == NULL) //��һ���ڵ㼴�ظ�
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