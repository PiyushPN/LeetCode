// Last updated: 18/07/2026, 20:01:40
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
    void deleteNode(ListNode* node) {
        ListNode *curr;
        curr=node->next;
        node->val = curr->val;
        node->next = curr->next;
        delete curr;
        
    }
};