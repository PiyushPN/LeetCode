// Last updated: 18/07/2026, 20:00:44
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i = 0; i < n+1; i++)
        {
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};