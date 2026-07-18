// Last updated: 18/07/2026, 19:57:02
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp = head;
        ListNode *head2 = NULL;
        ListNode *prev = NULL;
        temp = temp->next;
        int cnt = 1;
        int flag = 1;
        int sum = 0;
        while(temp != NULL)
        {
            if(temp->val == 0)
            {
                cnt++;
            }
            if(cnt == 2)
            {
                if(flag == 1)
                {
                    head2 = new ListNode(sum);
                    prev = head2;
                    flag = 0;
                }
                else
                {
                    ListNode* temp2 = new ListNode(sum);
                    prev->next = temp2;
                    prev = temp2;
                }
                sum = 0;
                cnt = 1;
            }
            sum += temp->val;
            temp = temp->next;    
        }
        return head2;
    }
};