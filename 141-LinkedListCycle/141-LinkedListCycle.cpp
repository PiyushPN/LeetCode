// Last updated: 18/07/2026, 20:02:45
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
        ListNode *sp=head, *fp=head;
        while(fp and fp->next){
            sp=sp->next;
            fp=fp->next->next;
            if(sp==fp){
                return true;
            }
        }
        return false;
    }
};