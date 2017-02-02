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
		ListNode *meet = NULL;        //��¼��ָ�����ָ�������δ֪
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
			slow = head;//����ָ��Ϳ�ָ��ֱ��head������δ֪����������ͬ�ٶ��н�,����ڻ���ʼλ������
			while(slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		return fast;
    }
};