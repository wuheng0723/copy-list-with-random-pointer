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
    void reorderList(ListNode *head) {
        if(head == NULL) return ;
        ListNode *HeadMid = GetMid(head);
		ListNode *pHead   = head;
		ListNode *pHeadNext = head->next;
		while(HeadMid->next!=NULL)   //	HeadMid是中点，改变顺序后的最后一个节点
		{
			ListNode *TailTemp = HeadMid;
			ListNode *tail    = HeadMid->next;
			while(tail->next!=NULL)   //倒数第二个节点
			{
				TailTemp = TailTemp->next;
				tail     = tail->next;
			}
			TailTemp->next = NULL;
			pHead->next = tail;    //一次循环将两个节点的指针改变
			tail->next  = pHeadNext;
			pHead = pHeadNext;
			if(pHead->next == NULL)
				break;
			else
				pHeadNext = pHeadNext->next;
		}
    }
    ListNode *GetMid(ListNode *head)
	{
		ListNode *fast = head;
		ListNode *slow = head;
		while(true)
		{
			if(fast->next == NULL)   //有奇数个节点，快指针刚好到最后一个
				return slow;
			else
				if(fast->next!=NULL && fast->next->next==NULL)
					return slow->next;
				else
				{
					fast = fast->next->next;
					slow = slow->next;
				}
		}
	}
};