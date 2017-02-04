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
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL || head->next==NULL) return head;
		//find the last element of the linked list
		ListNode *p = head;
		ListNode *last = NULL;
		for(;k!=0;k--)
		{
			while(p->next->next!=NULL)
				p = p->next;
			last = p->next;    //���һ��Ԫ��
			last->next = head;  //����һ��
			head = last; //�����µ�head
			p->next = NULL;  //�����µ�β�ڵ�
			p = head;
		}
		return head;
    }
};