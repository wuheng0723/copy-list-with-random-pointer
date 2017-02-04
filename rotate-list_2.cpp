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
		int num = 1;
		while(p->next!=NULL)
		{
			p = p->next;
			num++;
		}
		ListNode *last = p;  //��ǰ��������һ���ڵ�
		k = k%num;    //k������Ԫ�ظ�������,k�п��ܴ���num
		if(k==0)      //�ƶ�������Ԫ�ظ����պ���ͬ
			return head;
		int n = num-k;  
		p = head;
		int i = 1;
		while(i<n)
		{
			p = p->next;
			i++;
		}
		last->next = head;
		head = p->next;
		p->next = NULL;
		return head;
    }
};