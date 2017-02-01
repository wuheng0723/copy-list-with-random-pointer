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
		while(HeadMid->next!=NULL)   //	HeadMid���е㣬�ı�˳�������һ���ڵ�
		{
			ListNode *TailTemp = HeadMid;
			ListNode *tail    = HeadMid->next;
			while(tail->next!=NULL)   //�����ڶ����ڵ�
			{
				TailTemp = TailTemp->next;
				tail     = tail->next;
			}
			TailTemp->next = NULL;
			pHead->next = tail;    //һ��ѭ���������ڵ��ָ��ı�
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
			if(fast->next == NULL)   //���������ڵ㣬��ָ��պõ����һ��
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