// Last updated: 18/07/2026, 19:58:05
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int n1 = rolls.size();
        int sum = accumulate(rolls.begin(), rolls.end(), 0);
        int N = n1+n;
        int total = N*mean;
        int req = total-sum;
        int rem = req%n;
        if(6*n < req or req < n)
        {
            return {};
        }
        vector<int> ans(n, req/n);
        int j = 0;
        while(rem)
        {
            ans[j]++;
            rem--;
            j++;
        }
        return ans;
    }
};