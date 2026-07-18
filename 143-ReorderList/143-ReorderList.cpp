// Last updated: 18/07/2026, 20:02:43
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
    void reorderList(ListNode* head) {
        if(!head){
            return;
        }
        ListNode *fp=head, *sp=head;
        while(fp and fp->next){
            fp=fp->next->next;
            sp=sp->next;
        }
        
        ListNode *second = sp->next;
        sp->next = NULL;
        ListNode *prev=NULL;
        
        while(second){
            ListNode* tmp = second->next;
            second->next=prev;
            prev=second;
            second=tmp;
        }
        second=prev;
        ListNode *first=head;

        while(second){
            ListNode *tmp=first->next;
            ListNode *tmp1=second->next;
            first->next=second;
            second->next=tmp;
            first=tmp;
            second=tmp1;
        }
    }
};