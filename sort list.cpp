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
    ListNode *sortList(ListNode *head) {
        if(head == NULL) return head;
		if(head->next == NULL) 
			return head;
		else
		{
			ListNode *HeadMid = GetMid(head);
			head = sortList(head);
			HeadMid = sortList(HeadMid);
			return merge(head,HeadMid);
		}
    }
    ListNode *GetMid(ListNode *head)
	{
		ListNode *fast = head;
		ListNode *slow = head;
		while(true)
		{
			if(fast->next == NULL)   //有奇数个节点，快指针刚好到最后一个
			{
				ListNode *ReturnNode = slow->next;
				slow->next = NULL;
				return ReturnNode;
			}
			else
				if(fast->next!=NULL && fast->next->next==NULL)
				{
					ListNode *ReturnNode = slow->next;
					slow->next = NULL;
					return ReturnNode;
				}
				else
				{
					fast = fast->next->next;
					slow = slow->next;
				}
		}
	}
	ListNode *merge(ListNode *head,ListNode *HeadMid)
	{
		if(head==NULL) return HeadMid;
		if(HeadMid==NULL) return head;
		ListNode *NewSortList = NULL;
		ListNode *pLeft = head;
		ListNode *pRight = HeadMid;
		ListNode *pOld = NULL;
		while(pLeft!=NULL && pRight!=NULL)
		{
			ListNode *pNew = NULL;
			if(pLeft->val < pRight->val)
			{
				pNew = new ListNode(pLeft->val);
				pLeft = pLeft->next;
			}
			else
			{
				pNew = new ListNode(pRight->val);
				pRight = pRight->next;
			}
			if(NewSortList == NULL)
			{
				NewSortList = pNew;
				pOld = NewSortList;
			}
			pOld->next = pNew;
			pOld = pNew;
		}
		while(pLeft!=NULL)
		{
			ListNode *pNew = new ListNode(pLeft->val);
			pLeft = pLeft->next;
			pOld->next = pNew;
			pOld = pNew;
		}
		while(pRight!=NULL)
		{
			ListNode *pNew = new ListNode(pRight->val);
			pRight = pRight->next;
			pOld->next = pNew;
			pOld = pNew;
		}
		return NewSortList;
	}
};