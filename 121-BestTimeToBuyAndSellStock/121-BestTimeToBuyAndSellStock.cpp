// Last updated: 18/07/2026, 20:03:10
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mx = 0;
        int n = prices.size();
        for(int i=n-1; i>=0; i--){
            mx = max(mx, prices[i]);
            ans = max(ans, mx-prices[i]);
        }
        return ans;
    }
};