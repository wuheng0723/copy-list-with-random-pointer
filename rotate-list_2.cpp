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
		ListNode *last = p;  //当前链表的最后一个节点
		k = k%num;    //k对链表元素个数求余,k有可能大于num
		if(k==0)      //移动个数与元素个数刚好相同
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