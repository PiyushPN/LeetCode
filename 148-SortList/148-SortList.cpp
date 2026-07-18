// Last updated: 18/07/2026, 20:02:36
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
    ListNode* merge(ListNode *h1, ListNode *h2){
        if(h1==NULL or h2==NULL){
            return (h1==NULL)?h2:h1;
        }
        if(h1->val < h2->val){
            h1->next = merge(h1->next, h2);
            return h1;
        } else {
            h2->next = merge(h1, h2->next);
            return h2;
        }
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* sp=head, *fp=head, *prev=NULL;
        while(fp and fp->next){
            prev=sp;
            sp=sp->next;
            fp=fp->next->next;
        }
        prev->next=NULL;
        ListNode* h1=sortList(head);
        ListNode* h2=sortList(sp);
        return merge(h1, h2);
    }
};