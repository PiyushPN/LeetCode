// Last updated: 18/07/2026, 20:02:44
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
        if(head == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *sp = head;
        ListNode *fp = head;
        while(fp and fp->next)
        {
            sp = sp->next;
            fp = fp->next->next;
            if(sp == fp)
            {
                while(temp<temp->next)
                {
                    temp = temp->next;
                }
                return temp->next;
            }
        }
        return NULL;
    }
};