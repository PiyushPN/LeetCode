// Last updated: 18/07/2026, 20:03:57
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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;
        int count = 0;
        while(temp)
        {
            count++;
            if(temp->next == NULL)
            {
                temp->next = head;
                break;
            }
            temp = temp->next;
        }
        temp = head;
        int i = 0;
        int k1 = count-(k%count);
        while(i < k1)
        {
            prev = head;
            head = head->next;
            i++; 
        }
        prev->next = NULL;
        return head;
        
    }
};