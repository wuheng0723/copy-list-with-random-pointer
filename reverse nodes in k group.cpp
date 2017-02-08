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
    ListNode *reverse(ListNode *pStart,ListNode *p)
	{
        ListNode *pLast = pStart->next;   //��ǰ�εĵ�һ���ڵ㣬Ҳ������ת�����һ���ڵ�
        ListNode *pNext = p->next;
        ListNode *pre = pStart->next;
        ListNode *cur = pre->next;
        ListNode *nex = cur->next;
        while(cur!=pNext)      //��ǰ������λ���
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        pStart->next->next = pNext;   //��ǰ�ε����һ���ڵ�ָ�����
        pStart->next       = p;       //ǰһ�ε����һ��ָ�����
        return pLast;      //������ת�󱾶ε����һ���ڵ�
	}
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL || head->next == NULL)
			return head;
        if(k == 1) return head;
        //Ϊ����д���룬�¹���һ���ڵ�
        ListNode *pNew = new ListNode(0);
        pNew->next = head;
        ListNode *p = head;
        ListNode *pStart = pNew;  //pStartָ��ǰ�ε�ǰһ���ڵ�
        int num = 1;
        while(p)
        {
            if(num == k)
            {
                num = 1;
                if(pStart == pNew)
                    head = p;
                pStart = reverse(pStart,p);
                p = pStart->next;
            }
            else
            {
                p = p->next;
                num++;
            }	
        }
        return head;
    }
};