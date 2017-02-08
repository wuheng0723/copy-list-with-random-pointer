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
        ListNode *pLast = pStart->next;   //当前段的第一个节点，也就是逆转后最后一个节点
        ListNode *pNext = p->next;
        ListNode *pre = pStart->next;
        ListNode *cur = pre->next;
        ListNode *nex = cur->next;
        while(cur!=pNext)      //从前向后依次滑动
        {
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex->next;
        }
        pStart->next->next = pNext;   //当前段的最后一个节点指针调整
        pStart->next       = p;       //前一段的最后一个指针调整
        return pLast;      //返回逆转后本段的最后一个节点
	}
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL || head->next == NULL)
			return head;
        if(k == 1) return head;
        //为方便写代码，新构造一个节点
        ListNode *pNew = new ListNode(0);
        pNew->next = head;
        ListNode *p = head;
        ListNode *pStart = pNew;  //pStart指向当前段的前一个节点
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