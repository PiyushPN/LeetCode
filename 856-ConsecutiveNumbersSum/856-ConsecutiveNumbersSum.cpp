// Last updated: 18/07/2026, 19:59:22
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for(int k = 1; k<sqrt(2*n); k++)
        {
            if((n-(k*(k-1)/2))%k==0)
            {
                ans++;
            }
        }
        return ans;
    }
};