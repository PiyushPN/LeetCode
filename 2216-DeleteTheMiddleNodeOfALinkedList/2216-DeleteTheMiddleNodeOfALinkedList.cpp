// Last updated: 18/07/2026, 19:57:45
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *fp = head, *sp = head, *prev = NULL;
        if(head == NULL or head->next == NULL)
        {
            return NULL;
        }
        while(fp and fp->next)
        {
            prev = sp;
            sp=sp->next;
            fp = fp->next->next;
        }
        prev->next = sp->next;
        sp->next = NULL;
        return head;
    }
};