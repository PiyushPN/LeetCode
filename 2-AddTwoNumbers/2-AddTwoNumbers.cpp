// Last updated: 18/07/2026, 20:04:39
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyhead = new ListNode(0);
        ListNode* tail = dummyhead;
        int carry=0;
        while(l1 || l2 || carry!=0){
            int num1 = l1?l1->val:0;
            int num2 = l2?l2->val:0;
            int sum=num1+num2+carry;
            int digit = sum%10;
            carry=sum/10;
            ListNode* node = new ListNode(digit);
            tail->next=node;
            tail=tail->next;
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
        ListNode* result=dummyhead->next;
        delete dummyhead;
        return result;
        
    }
};