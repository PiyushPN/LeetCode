// Last updated: 18/07/2026, 20:01:52
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
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next){
            return head;
        }
        ListNode *curr=head, *prev=NULL, *next=curr->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=next;
            if(curr){
                next=curr->next;
            }
        }
        head=prev;
        return head;
    }
};