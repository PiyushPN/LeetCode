// Last updated: 18/07/2026, 20:02:20
class Solution {
public:
    int trailingZeroes(int n) {
        int k = n;
        int ans = 0;
        while(k)
        {
            ans = ans + k/5;
            k = k/5;
        }
        return ans;
        
    }
};