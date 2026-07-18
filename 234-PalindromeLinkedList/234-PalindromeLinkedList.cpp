// Last updated: 18/07/2026, 20:01:26
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
    bool isPalindrome(ListNode* head) {
        ListNode *sp = head, *fp = head;
        while(fp and fp->next)
        {
            sp = sp->next;
            fp = fp->next->next;
        }
        if(fp)
        {
            sp = sp->next;
        }
        ListNode *curr = sp, *prev = NULL, *next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        sp = prev;
        while(head and sp)
        {
            if(sp->val != head->val)
            {
                return false;
            }
            head = head->next;
            sp = sp->next;
        }
        return true;
    }
};