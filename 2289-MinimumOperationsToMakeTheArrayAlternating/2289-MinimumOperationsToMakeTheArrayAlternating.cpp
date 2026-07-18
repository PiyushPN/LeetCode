// Last updated: 18/07/2026, 19:57:07
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp1, mp2;
        int n1, n2;
        int ans = 0;
        
        priority_queue<pair<int, int>> pq1, pq2;
        int n = nums.size();
        if(n==1)
        {
            return 0;
        }
        for(int i = 0; i < n; i++)
        {
            if(i%2 == 0)
            {
                mp1[nums[i]]++;
            }
            else
            {
                mp2[nums[i]]++;
            }
        }
        for(auto it: mp1)
        {
            pq1.push({it.second, it.first});
        }
        for(auto it: mp2)
        {
            
            pq2.push({it.second, it.first});
        }
        if(n%2==0)
        {
            n1 = n/2;
            n2 = n/2;
        }
        else
        {
            n1 = (n/2)+1;
            n2 = n/2;
        }
        // cout<<n1<<" "<<n2<<endl;
        auto temp1 = pq1.top();
        pq1.pop();
        auto temp2 = pq2.top();
        pq2.pop();
        // cout<<temp1<<" "<<temp2<<endl;
        if(temp1.second == temp2.second)
        {
            int op1 = (n1 - temp1.first);
            if(!pq2.empty())
            {
                op1 += (n2 - pq2.top().first);
            }
            else
            {
                op1 += n2;
            }
            int op2 = (n2 - temp2.first);
            if(!pq1.empty())
            {
                op2 += (n1 - pq1.top().first);
            }
            else
            {
                op2 += n1;
            } 
            ans = min(op1,op2);
        }
        else if(temp1 != temp2)
        {
            ans += n1-temp1.first;
            ans += n2-temp2.first;
        }
        return ans;
    }
};