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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return 0;
		ListNode *fast = head;
		ListNode *slow = head;
		while(fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if(slow == fast)
				break;
		}
		return !((fast==NULL)||(fast->next==NULL));
    }
};