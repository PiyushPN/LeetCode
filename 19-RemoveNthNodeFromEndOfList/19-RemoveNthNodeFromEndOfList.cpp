// Last updated: 18/07/2026, 20:04:28
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fp = head;
        ListNode* sp = head;
        for(int i=0; i<n; i++){
            fp=fp->next;
        }
        if(fp==NULL){
            return head->next;
        }
        while(fp->next!=NULL){
            fp=fp->next;
            sp=sp->next;
        }
        ListNode* tmp=sp->next;
        sp->next=sp->next->next;
        delete tmp;
        return head;
    }
};