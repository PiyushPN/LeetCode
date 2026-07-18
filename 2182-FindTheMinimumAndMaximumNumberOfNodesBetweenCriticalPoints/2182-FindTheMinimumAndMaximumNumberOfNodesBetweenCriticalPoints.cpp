// Last updated: 18/07/2026, 19:57:57
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
    int mn = INT_MAX, mx = INT_MIN;
    void dis(ListNode *t1, ListNode *t2)
    {
        int dis = 0;
        while(t1 != t2)
        {
            dis++;
            t1=t1->next;
        }
        mn = min(mn, dis);
        mx = max(mx, dis);
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<ListNode*> cp;
        ListNode *temp = head->next;
        ListNode *prev = head;
        int i = 1;
        vector<int> ans;
        vector<int> index;
        while(temp->next != NULL)
        {
            if(temp->val < prev->val and temp->val < temp->next->val)
            {
                cp.push_back(temp);
                index.push_back(i);
                
            }
            if(temp->val > prev->val and temp->val > temp->next->val)
            {
                cp.push_back(temp);
                index.push_back(i);
            }
            prev = temp;
            temp = temp->next;
            i++;
        }
        if(cp.size() == 0 or cp.size() == 1)
        {
            return {-1, -1};
        }
        for(int i = 0; i < index.size()-1; i++)
        {
            mn = min(index[i+1]-index[i],mn);
        }
        ans.push_back(mn);
        ans.push_back(index.back()-index[0]);
        return ans;
    }
};