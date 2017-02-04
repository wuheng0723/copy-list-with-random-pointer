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
			last = p->next;    //最后一个元素
			last->next = head;  //右旋一步
			head = last; //定义新的head
			p->next = NULL;  //定义新的尾节点
			p = head;
		}
		return head;
    }
};