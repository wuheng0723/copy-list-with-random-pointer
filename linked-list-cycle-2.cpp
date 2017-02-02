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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return head;
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *meet = NULL;        //记录快指针和慢指针的相遇未知
		while(fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if(slow == fast)
				break;
		}
		if(!((fast==NULL)||(fast->next==NULL)) == 0)
			return NULL;
		else
		{
			meet = slow;
			slow = head;//令慢指针和快指针分别从head和相遇未知出发，以相同速度行进,则必在环起始位置相遇
			while(slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		return fast;
    }
};